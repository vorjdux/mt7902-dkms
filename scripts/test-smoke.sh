#!/usr/bin/env bash
# MT7902 Driver Smoke Test
# Tests basic functionality of the MT7902 driver

set -euo pipefail

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

log_info() {
    echo -e "${GREEN}[INFO]${NC} $1"
}

log_warn() {
    echo -e "${YELLOW}[WARN]${NC} $1"
}

log_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

cleanup() {
    log_info "Cleaning up test environment..."
    # Stop any running network operations
    sudo pkill -f "iw.*scan" 2>/dev/null || true
}

# Set trap for cleanup on exit
trap cleanup EXIT

echo "=== MT7902 Driver Smoke Test ==="
echo "Testing basic driver functionality..."

# Check if we're running as root or with sudo
if [[ $EUID -ne 0 ]]; then
    log_error "This script requires root privileges"
    echo "Run with: sudo $0"
    exit 1
fi

# Step 1: Check if modules are built
log_info "Checking if modules are built..."
if [[ ! -f "mt76/mt7902/mt7902-common.ko" ]] || [[ ! -f "mt76/mt7902/mt7902.ko" ]]; then
    log_error "Driver modules not found. Run ./scripts/build.sh first"
    exit 1
fi

# Step 2: Unload conflicting modules
log_info "Unloading conflicting modules..."
modprobe -r mt7902 2>/dev/null || true
modprobe -r mt7902-common 2>/dev/null || true
modprobe -r mt76 2>/dev/null || true
modprobe -r mt76x2e 2>/dev/null || true
modprobe -r mt76x0e 2>/dev/null || true
modprobe -r mt7921e 2>/dev/null || true

# Step 3: Load our modules
log_info "Loading MT7902 modules..."
if ! insmod ./mt76/mt7902/mt7902-common.ko; then
    log_error "Failed to load mt7902-common.ko"
    dmesg | tail -10
    exit 1
fi

if ! insmod ./mt76/mt7902/mt7902.ko; then
    log_error "Failed to load mt7902.ko"
    dmesg | tail -10
    exit 1
fi

log_info "Modules loaded successfully"

# Step 4: Wait for device initialization
log_info "Waiting for device initialization..."
sleep 3

# Step 5: Check for PCI device
log_info "Checking for MT7902 PCI device..."
if lspci -d 14c3:7902 | grep -q "7902"; then
    log_info "MT7902 PCI device detected:"
    lspci -d 14c3:7902
else
    log_warn "MT7902 PCI device not found in lspci output"
fi

# Step 6: Check for wireless interface
log_info "Checking for wireless interface..."
WIFI_INTERFACES=$(ip link show | grep -E "wl[a-z0-9]+:" | awk -F: '{print $2}' | tr -d ' ' || true)

if [[ -z "$WIFI_INTERFACES" ]]; then
    log_error "No wireless interfaces found"
    log_info "Available network interfaces:"
    ip link show
    exit 1
fi

log_info "Found wireless interface(s): $WIFI_INTERFACES"

# Use the first wireless interface for testing
WIFI_IF=$(echo "$WIFI_INTERFACES" | head -n1)
log_info "Using interface: $WIFI_IF"

# Step 7: Check rfkill status
log_info "Checking rfkill status..."
rfkill list wifi

# Step 8: Bring interface up
log_info "Bringing interface up..."
if ! ip link set "$WIFI_IF" up; then
    log_error "Failed to bring interface up"
    exit 1
fi

# Wait for interface to come up
sleep 2

# Step 9: Check interface status
log_info "Interface status:"
ip link show "$WIFI_IF"

# Step 10: Check iw capabilities
log_info "Checking wireless capabilities..."
if iw dev "$WIFI_IF" info; then
    log_info "Interface info retrieved successfully"
else
    log_warn "Failed to get interface info"
fi

# Step 11: Test scanning (basic functionality test)
log_info "Testing wireless scanning..."
SCAN_TIMEOUT=15
if timeout $SCAN_TIMEOUT iw dev "$WIFI_IF" scan > /tmp/mt7902_scan.txt 2>&1; then
    SCAN_RESULTS=$(grep -c "BSS " /tmp/mt7902_scan.txt || echo "0")
    log_info "Scan completed successfully. Found $SCAN_RESULTS networks."
    
    if [[ $SCAN_RESULTS -gt 0 ]]; then
        log_info "Sample scan results:"
        head -n 20 /tmp/mt7902_scan.txt
    fi
else
    log_warn "Scan failed or timed out after ${SCAN_TIMEOUT}s"
fi

# Step 12: Check kernel messages for errors
log_info "Checking kernel messages for critical errors..."
if dmesg | tail -20 | grep -iE "(error|fail|oops|panic|bug)" | grep -v "rfkill"; then
    log_warn "Found potential error messages in dmesg"
else
    log_info "No critical errors in recent kernel messages"
fi

# Step 13: Module information
log_info "Module information:"
lsmod | grep mt7902 || log_warn "mt7902 modules not shown in lsmod"

echo ""
echo "=== Smoke Test Summary ==="
log_info "✓ Modules loaded successfully"
log_info "✓ Wireless interface detected: $WIFI_IF"
log_info "✓ Interface brought up successfully"

if [[ ${SCAN_RESULTS:-0} -gt 0 ]]; then
    log_info "✓ Wireless scanning functional"
else
    log_warn "⚠ Wireless scanning issues detected"
fi

echo ""
log_info "Basic functionality test completed"
log_info "For full testing, try connecting to a network:"
echo "  wpa_supplicant -i $WIFI_IF -c /path/to/wpa_supplicant.conf"
echo "  dhclient $WIFI_IF"

# Optional: Clean temporary files
rm -f /tmp/mt7902_scan.txt
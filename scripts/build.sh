#!/usr/bin/env bash
# MT7902 DKMS Driver Build Script
# Builds the driver for the running kernel or specified kernel version

set -euo pipefail

# Default to current kernel if not specified
KDIR=${KDIR:-/lib/modules/$(uname -r)/build}
VERBOSE=${VERBOSE:-0}

# Parse command line options
while [[ $# -gt 0 ]]; do
    case $1 in
        --kver)
            KVER="$2"
            KDIR="/lib/modules/$KVER/build"
            shift 2
            ;;
        --verbose|-v)
            VERBOSE=1
            shift
            ;;
        --help|-h)
            echo "Usage: $0 [--kver KERNEL_VERSION] [--verbose]"
            echo "  --kver: Target kernel version (default: current)"
            echo "  --verbose: Enable verbose build output"
            exit 0
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

echo "=== MT7902 Driver Build ==="

# Auto-detect available kernel headers in Docker/container environments
if [[ ! -d "$KDIR" ]]; then
    echo "Warning: Kernel headers not found at $KDIR"
    echo "Searching for available kernel headers..."
    
    # Find available kernel headers
    AVAILABLE_HEADERS=($(find /lib/modules/*/build -maxdepth 0 2>/dev/null | head -5))
    
    if [[ ${#AVAILABLE_HEADERS[@]} -gt 0 ]]; then
        KDIR="${AVAILABLE_HEADERS[0]}"
        DETECTED_KVER=$(basename $(dirname "$KDIR"))
        echo "Auto-detected kernel headers: $DETECTED_KVER"
        echo "Using: $KDIR"
    else
        echo "Error: No kernel headers found in /lib/modules/"
        echo "Available modules directories:"
        ls -la /lib/modules/ 2>/dev/null || echo "No /lib/modules/ directory found"
        echo ""
        echo "Install headers with: sudo apt install linux-headers-generic"
        exit 1
    fi
fi

echo "Kernel: $(basename "$KDIR")"
echo "Build directory: $KDIR"

# Final check if kernel headers are available
if [[ ! -d "$KDIR" ]]; then
    echo "Error: Kernel headers not found at $KDIR"
    echo "Install with: sudo apt install linux-headers-$(uname -r)"
    exit 1
fi

# Set make flags based on verbosity
MAKE_FLAGS="modules"
if [[ $VERBOSE -eq 1 ]]; then
    MAKE_FLAGS="V=1 VERBOSE=1 $MAKE_FLAGS"
fi

# Build the modules
echo "Building modules..."
export KDIR="$KDIR"
make KDIR="$KDIR" $MAKE_FLAGS

echo "=== Build Complete ==="

echo ""
echo "To load the modules:"
echo "  sudo insmod mt76/mt7902/mt7902-common.ko"
echo "  sudo insmod mt76/mt7902/mt7902.ko"
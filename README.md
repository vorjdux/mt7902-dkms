# MT7902 DKMS Wi-Fi Driver

Linux kernel driver for MediaTek MT7902 Wi-Fi chips (PCI ID `14c3:7902`), based on the upstream MT7921 driver with compatibility updates for modern kernels.

## Status

✅ **Kernel Compatibility**: 6.8 - 6.16+  
✅ **Build System**: DKMS and manual builds supported  
✅ **Platform**: Ubuntu 24.04, kernel 6.14+ tested  
⚠️ **Secure Boot**: Needs testing (see [Ubuntu SecureBoot docs](https://wiki.ubuntu.com/UEFI/SecureBoot/))

## Requirements

### System Requirements
- **Kernel**: Linux 6.8+ (tested up to 6.16)
- **OS**: Ubuntu 24.04+ recommended
- **Hardware**: MediaTek MT7902 Wi-Fi chip

### Build Dependencies
```bash
sudo apt install build-essential linux-headers-$(uname -r) dkms
```

## Quick Start

### Option 1: Docker Testing (Recommended - No Host Impact)
```bash
# Clone the repository
git clone https://github.com/your-repo/mt7902-dkms
cd mt7902-dkms

# Quick build test
./scripts/docker-test.sh build

# Comprehensive testing
./scripts/docker-test.sh test

# Test across multiple Ubuntu versions
./scripts/docker-test.sh multi

# Interactive debugging
./scripts/docker-test.sh debug
```

### Option 2: Manual Build (Host System)
```bash
# Install firmware
cd firmware && sudo bash get-firmware.sh && cd ..

# Build the driver
./scripts/build.sh

# Test the driver
sudo ./scripts/test-smoke.sh
```

### Option 3: DKMS Installation

```bash
# Clone to DKMS source directory
sudo git clone https://github.com/your-repo/mt7902-dkms /usr/src/mt7902-0.0.1

# Register and build with DKMS
sudo dkms add mt7902/0.0.1
sudo dkms build mt7902/0.0.1
sudo dkms install mt7902/0.0.1

# Install firmware
cd /usr/src/mt7902-0.0.1/firmware && sudo bash get-firmware.sh

# Check status
sudo dkms status mt7902
```

## Troubleshooting

### Build Issues
- **Missing headers**: `sudo apt install linux-headers-$(uname -r)`
- **Kernel too old**: Update to kernel 6.8+ or use kernel compatibility patches
- **Build failures**: Check `dmesg` for detailed error messages

### Runtime Issues
```bash
# Check if device is detected
lspci -d 14c3:7902

# Check rfkill status
rfkill list wifi

# Check kernel messages
dmesg | grep mt7902

# Manual module loading
sudo modprobe -r mt7902 mt7902-common  # unload
sudo modprobe mt7902-common && sudo modprobe mt7902  # load
```

### Secure Boot
For systems with Secure Boot enabled:
1. Sign the modules with your MOK key
2. Or disable Secure Boot temporarily for testing
3. See [Ubuntu Secure Boot documentation](https://wiki.ubuntu.com/UEFI/SecureBoot/)

## Uninstallation

### DKMS Method
```bash
sudo dkms uninstall mt7902/0.0.1
sudo dkms remove mt7902/0.0.1 --all
sudo rm -rf /usr/src/mt7902*
```

### Manual Method
```bash
# Remove modules
sudo rmmod mt7902 mt7902-common
rm -rf /path/to/mt7902-dkms
```

## Development

### Docker-based Testing (Recommended)
```bash
# Quick build test (no host system impact)
./scripts/docker-test.sh build

# Full validation with module checks
./scripts/docker-test.sh test

# Test across Ubuntu 22.04, 23.04, 24.04
./scripts/docker-test.sh multi

# Interactive debugging shell
./scripts/docker-test.sh debug

# Clean up Docker resources
./scripts/docker-test.sh clean
```

### Building for Different Kernels
```bash
# Build for specific kernel version
./scripts/build.sh --kver 6.14.0-generic

# Verbose build output
./scripts/build.sh --verbose

# Docker build with verbose output
./scripts/docker-test.sh build --verbose
```

### Running Tests
```bash
# Docker-based smoke test (safe)
./scripts/docker-test.sh test

# Host-based smoke test (requires root)
sudo ./scripts/test-smoke.sh

# Check for API compatibility issues
grep -r "LINUX_VERSION_CODE" include/
```

## Hardware Compatibility

### Supported Devices
- **PCI ID**: `14c3:7902` (base MediaTek MT7902)
- **Variants**: MicroTek, AzureWave modules
- **Interface**: PCIe only (SDIO/USB variants disabled)

### Known Working Hardware
- Various laptop Wi-Fi cards with MT7902 chipset
- See [MediaTek MT7902 Reference Design](https://wikidevi.wi-cat.ru/MediaTek_MT7902_Reference_Design)

## Firmware

Firmware is automatically downloaded from Acer's driver package:
- **Source**: Acer Windows driver package
- **Installation**: Automatically placed in `/lib/firmware/mediatek/`
- **License**: Proprietary (Acer/MediaTek)

## Contributing

1. Fork the repository
2. Create a feature branch
3. Test with `./scripts/build.sh && sudo ./scripts/test-smoke.sh`
4. Submit a pull request

### Kernel API Updates
When updating for new kernels:
1. Add compatibility shims to `include/compat.h`
2. Update function signatures in relevant files
3. Test across kernel versions 6.8-6.16+

## License

- **Driver Source**: GPL-2.0 (follows upstream Linux kernel)
- **Firmware**: Proprietary (not included in repository)
- **Build Scripts**: GPL-2.0

## Support

- **Issues**: Report on GitHub Issues
- **Wiki**: Check project wiki for additional documentation
- **Secure Boot**: Community testing needed

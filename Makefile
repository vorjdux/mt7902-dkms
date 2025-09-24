# SPDX-License-Identifier: ISC
# MT7902 DKMS Driver Top-level Makefile

# Get kernel version and build directory
KVER ?= $(shell uname -r)
KDIR ?= /lib/modules/$(KVER)/build

# Default target
default: modules

# Build all modules
modules:
	$(MAKE) -C $(KDIR) M=$(PWD)/mt76/mt7902 modules
	@echo "=== Build Summary ==="
	@echo "Built modules:"
	@find mt76/mt7902/ -name "*.ko" -exec ls -lh {} \; 2>/dev/null || echo "No modules built"

# Clean all modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD)/mt76/mt7902 clean
	@echo "Cleaned build artifacts"

# Install modules (requires root)
install: modules
	$(MAKE) -C $(KDIR) M=$(PWD)/mt76/mt7902 modules_install
	depmod -a

# DKMS support
dkms-build:
	$(MAKE) -C $(KDIR) M=$(PWD)/mt76/mt7902 modules

# Help target
help:
	@echo "MT7902 Driver Build Targets:"
	@echo "  modules     - Build driver modules (default)"
	@echo "  clean       - Clean build artifacts"
	@echo "  install     - Install modules (requires root)"
	@echo "  dkms-build  - Build for DKMS"
	@echo "  help        - Show this help"
	@echo ""
	@echo "Variables:"
	@echo "  KVER        - Target kernel version (default: $(KVER))"
	@echo "  KDIR        - Kernel build directory (default: $(KDIR))"

.PHONY: default modules clean install dkms-build help
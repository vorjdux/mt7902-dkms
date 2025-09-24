# MT7902 Driver Kernel Compatibility Updates

## Summary

This document outlines the changes made to update the MT7902 driver for compatibility with Linux kernels 6.14-6.16, while maintaining backward compatibility with kernels 6.8+.

## Key Changes Made

### 1. Compatibility Layer (`include/compat.h`)
- Created a centralized compatibility header
- Defines version-gated macros for API changes
- Provides clean abstractions for kernel version differences

### 2. MAC80211 API Updates

#### get_txpower Callback (6.14+)
- **Change**: Signature changed from `int *dbm` to `unsigned int *dbm`
- **Files**: `mt76/mac80211.c`, `mt76/mt7902/main.c`
- **Solution**: Added `mt7902_get_txpower_compat()` wrapper

#### sta_state Callback (6.14+)
- **Change**: Added `bool link_sta` parameter
- **Files**: `mt76/mac80211.c`, `mt76/mt7902/main.c`
- **Solution**: Added `mt7902_sta_state_compat()` wrapper

#### bss_info_changed Callback (6.14+)
- **Change**: Added `unsigned int link_id` parameter
- **Files**: `mt76/mt7902/main.c`
- **Solution**: Added `mt7902_bss_info_changed_compat()` wrapper

#### get_survey Callback (6.15+)
- **Change**: Added `u32 flags` parameter
- **Files**: `mt76/mac80211.c`, `mt76/mt7902/main.c`
- **Solution**: Added `mt7902_get_survey_compat()` wrapper

#### set_key Callback (6.14+)
- **Change**: Added `unsigned int link_id` parameter
- **Files**: `mt76/mt7902/main.c`
- **Solution**: Added `mt7902_set_key_compat()` wrapper

### 3. Build System Updates

#### Makefile Changes
- Added `ccflags-y += -I$(src)/../../include` for compat headers
- Maintained existing DKMS compatibility

#### New Build Scripts
- `scripts/build.sh`: Improved build script with error checking
- `scripts/test-smoke.sh`: Comprehensive testing script

### 4. Testing Infrastructure

#### Smoke Testing
- Device detection tests
- Module loading verification
- Wireless scanning tests
- Interface management tests
- Error checking and reporting

#### CI/CD Pipeline
- `.github/workflows/build.yml`: Multi-kernel build testing
- Artifact collection for debugging

### 5. Documentation Updates

#### README.md
- Updated kernel compatibility information
- Added troubleshooting sections
- Improved installation instructions
- Added development guidelines

#### Copilot Instructions
- Updated with kernel compatibility focus
- Added specific API change guidance
- Enhanced troubleshooting procedures

## Implementation Strategy

### Version Guards
All compatibility code uses `LINUX_VERSION_CODE` checks:
```c
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 14, 0)
    // New API
#else
    // Old API
#endif
```

### Wrapper Functions
- Minimal overhead wrapper functions
- Preserve original function behavior
- Ignore new parameters when safe
- Maintain backward compatibility

### Error Handling
- Comprehensive error reporting
- Graceful degradation for unsupported features
- Clear diagnostic messages

## Testing Status

### Kernel Versions Targeted
- ✅ 6.8.x (baseline)
- ✅ 6.11.x (intermediate)
- ✅ 6.14.x (primary target)
- ✅ 6.16.x (future-proofing)

### Test Coverage
- Build testing across kernel versions
- Module loading/unloading
- Basic wireless functionality
- PCI device detection
- Firmware loading

## Known Limitations

1. **Link Aggregation**: New `link_id` parameters are ignored
2. **Survey Flags**: New survey flags are not utilized
3. **Multi-Link Operation**: MLO features not fully supported

## Future Considerations

### Kernel 6.17+ Preparation
- Monitor mac80211 API changes
- Track cfg80211 updates
- Watch for regulatory domain changes

### Feature Enhancements
- Implement proper MLO support
- Utilize new survey capabilities
- Enhanced power management

## Files Modified

### Core Driver Files
- `mt76/mac80211.c` - Core mac80211 interface
- `mt76/mt7902/main.c` - Driver main operations
- `mt76/mt7902/Makefile` - Build configuration

### New Files
- `include/compat.h` - Compatibility layer
- `scripts/build.sh` - Enhanced build script
- `scripts/test-smoke.sh` - Testing framework
- `.github/workflows/build.yml` - CI pipeline
- `VERSION` - Version tracking

### Documentation
- `README.md` - Updated documentation
- `.github/instructions/copilot-instructions.md` - AI assistant guidance

## Validation

The changes have been designed to:
1. Maintain full backward compatibility with 6.8+
2. Support forward compatibility through 6.16+
3. Provide clear error messages for unsupported configurations
4. Enable easy testing and debugging

## Deployment

The updated driver can be deployed using:
1. **Manual build**: `./scripts/build.sh && sudo ./scripts/test-smoke.sh`
2. **DKMS**: Standard DKMS installation with updated configuration
3. **CI testing**: Automated build verification across kernel versions
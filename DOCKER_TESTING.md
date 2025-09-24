# Docker Testing Examples for MT7902 Driver

This document provides practical examples for testing the MT7902 driver using Docker without affecting your host system.

## Prerequisites

- Docker installed and running
- Docker Compose (optional, for advanced scenarios)

## Basic Usage

### 1. Quick Build Test
```bash
# Test if the driver builds successfully
./scripts/docker-test.sh build
```

### 2. Comprehensive Testing
```bash
# Full build and validation
./scripts/docker-test.sh test
```

### 3. Multi-Version Testing
```bash
# Test across Ubuntu 22.04, 23.04, 24.04
./scripts/docker-test.sh multi
```

### 4. Interactive Debugging
```bash
# Get a shell inside the container
./scripts/docker-test.sh debug

# Inside the container, you can:
./scripts/build.sh --verbose
ls -la mt76/mt7902/*.ko
/sbin/modinfo mt76/mt7902/mt7902.ko
```

## Using Docker Compose

### Available Services

```bash
# Basic build test
docker-compose up build-test

# Full test with validation
docker-compose up full-test

# Interactive shell
docker-compose up debug

# Test with Ubuntu 22.04
docker-compose up ubuntu-22
```

## Advanced Testing Scenarios

### Testing Specific Kernel APIs
```bash
# Build and check for specific API usage
./scripts/docker-test.sh debug

# Inside container:
./scripts/build.sh --verbose
grep -r "get_txpower" mt76/
grep -r "LINUX_VERSION_CODE" include/
```

### Validating Symbol Dependencies
```bash
./scripts/docker-test.sh test | grep -A 10 "Symbol check"
```

### Cross-Version Compatibility
```bash
# Test build consistency across versions
./scripts/docker-test.sh multi 2>&1 | grep -E "(SUCCESS|FAILED)"
```

## Troubleshooting

### Build Failures
1. Check kernel headers availability:
   ```bash
   ./scripts/docker-test.sh debug
   # Inside: ls -la /lib/modules/*/build
   ```

2. Verify source code integrity:
   ```bash
   ./scripts/docker-test.sh debug
   # Inside: find . -name "*.c" -exec grep -l "get_txpower" {} \;
   ```

### Docker Issues
```bash
# Clean up everything and start fresh
./scripts/docker-test.sh clean
docker system prune -f

# Rebuild and test
./scripts/docker-test.sh build
```

### Performance Issues
```bash
# Use .dockerignore to speed up builds
cat .dockerignore

# Build only what's needed
docker build --no-cache -t mt7902-test .
```

## Expected Output

### Successful Build
```
[INFO] Docker is available and running
[STEP] Building Docker image...
[INFO] Docker image built successfully
[STEP] Running build test in Docker...
=== MT7902 Driver Build ===
Kernel: 6.8.0-40-generic
Building modules...
=== Build Complete ===
Modules built:
-rw-r--r-- 1 root root 1.2M mt7902-common.ko
-rw-r--r-- 1 root root  45K mt7902.ko
```

### Multi-Version Results
```
[STEP] Testing with Ubuntu 22.04...
[INFO] ✓ Ubuntu 22.04: SUCCESS
[STEP] Testing with Ubuntu 23.04...
[INFO] ✓ Ubuntu 23.04: SUCCESS
[STEP] Testing with Ubuntu 24.04...
[INFO] ✓ Ubuntu 24.04: SUCCESS
[INFO] Multi-version test results: 3/3 versions successful
[INFO] 🎉 All versions passed!
```

## Benefits of Docker Testing

1. **No Host Impact**: Build and test without installing kernel headers or affecting your system
2. **Reproducible**: Same environment every time
3. **Multi-Version**: Test across different Ubuntu versions easily
4. **Safe**: Containers are isolated and disposable
5. **Fast**: Cached layers make subsequent builds quick
6. **Debuggable**: Interactive shells for troubleshooting

## Integration with CI/CD

The Docker setup is designed to work with GitHub Actions and other CI systems:

```yaml
- name: Test MT7902 Driver
  run: |
    ./scripts/docker-test.sh test
    ./scripts/docker-test.sh multi
```
#!/usr/bin/env bash
# Docker-based testing script for MT7902 driver
# This script provides comprehensive testing without affecting the host system

set -euo pipefail

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
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

log_step() {
    echo -e "${BLUE}[STEP]${NC} $1"
}

show_help() {
    cat << EOF
MT7902 Driver Docker Test Script

USAGE:
    $0 [COMMAND] [OPTIONS]

COMMANDS:
    build           Build the driver in Docker (default)
    test            Full build and validation test
    debug           Start interactive shell in container
    kernelcheck     Check kernel and header compatibility
    multi           Test across multiple Ubuntu versions
    kernels         Test across multiple kernel versions
    clean           Clean up Docker images and containers
    
OPTIONS:
    --verbose       Enable verbose output
    --help          Show this help message

EXAMPLES:
    $0                          # Quick build test
    $0 build --verbose          # Verbose build
    $0 test                     # Full validation
    $0 debug                    # Interactive debugging
    $0 kernelcheck              # Check kernel/header compatibility
    $0 multi                    # Multi-version testing
    $0 kernels                  # Multi-kernel testing
    $0 clean                    # Cleanup

REQUIREMENTS:
    - Docker installed and running
    - Docker Compose (optional, for advanced features)
EOF
}

check_docker() {
    if ! command -v docker &> /dev/null; then
        log_error "Docker is not installed or not in PATH"
        echo "Please install Docker: https://docs.docker.com/get-docker/"
        exit 1
    fi
    
    if ! docker info &> /dev/null; then
        log_error "Docker daemon is not running"
        echo "Please start Docker daemon"
        exit 1
    fi
    
    log_info "Docker is available and running"
}

build_image() {
    log_step "Building Docker image..."
    docker build -t mt7902-test . || {
        log_error "Failed to build Docker image"
        exit 1
    }
    log_info "Docker image built successfully"
}

run_build_test() {
    local verbose=""
    if [[ "${1:-}" == "--verbose" ]]; then
        verbose="--verbose"
    fi
    
    log_step "Running build test in Docker..."
    docker run --rm -v "$PWD:/workspace" mt7902-test ./scripts/build.sh $verbose
}

run_full_test() {
    log_step "Running comprehensive test in Docker..."
    
    docker run --rm -v "$PWD:/workspace" mt7902-test /bin/bash -c "
        echo '=== MT7902 Driver Comprehensive Test ==='
        echo 'System Information:'
        echo \"Host: \$(hostname)\"
        echo \"Running kernel: \$(uname -r)\"
        echo \"Architecture: \$(uname -m)\"
        echo \"Ubuntu version: \$(lsb_release -ds 2>/dev/null || echo 'Unknown')\"
        echo ''
        echo 'Kernel Headers Analysis:'
        echo \"Target KDIR: \${KDIR:-/lib/modules/\$(uname -r)/build}\"
        if [[ -d \"/lib/modules/\$(uname -r)/build\" ]]; then
            echo \"✓ Matching headers found for kernel \$(uname -r)\"
        else
            echo \"✗ No matching headers for kernel \$(uname -r)\"
            echo \"Available headers:\"
            find /lib/modules/*/build -maxdepth 0 2>/dev/null | while read dir; do
                version=\$(basename \$(dirname \"\$dir\"))
                echo \"  - \$version (\$dir)\"
            done
        fi
        echo ''
        echo '=== Building Driver ==='
        ./scripts/build.sh --verbose
        echo ''
        echo '=== Validating Built Modules ==='
        find mt76/mt7902/ -name '*.ko' -exec ls -lh {} \;
        echo ''
        echo '=== Module Information ==='
        for ko in mt76/mt7902/*.ko; do
            if [[ -f \"\$ko\" ]]; then
                echo \"--- \$ko ---\"
                /sbin/modinfo \"\$ko\" 2>/dev/null || echo \"modinfo failed for \$ko\"
                echo \"Symbol check:\"
                nm \"\$ko\" | grep -E '(undefined|UNDEF)' || echo \"No undefined symbols\"
                echo ''
            fi
        done
        echo '=== Test Summary ==='
        echo \"Built modules:\"
        ls -1 mt76/mt7902/*.ko 2>/dev/null | wc -l || echo '0'
        echo 'Test completed successfully!'
    "
}

run_debug_shell() {
    log_step "Starting interactive debug shell..."
    log_info "You'll be dropped into a bash shell inside the container"
    log_info "Run './scripts/build.sh --verbose' to build the driver"
    log_info "Type 'exit' to return to host system"
    
    docker run --rm -it -v "$PWD:/workspace" mt7902-test /bin/bash
}

run_kernel_check() {
    log_step "Checking kernel and header compatibility..."
    
    docker run --rm -v "$PWD:/workspace" mt7902-test /bin/bash -c "
        echo '=== Kernel and Header Compatibility Check ==='
        echo ''
        echo 'System Information:'
        echo \"Distribution: \$(lsb_release -ds 2>/dev/null || cat /etc/os-release | grep PRETTY_NAME | cut -d'\"' -f2)\"
        echo \"Running kernel: \$(uname -r)\"
        echo \"Architecture: \$(uname -m)\"
        echo \"Kernel command line: \$(cat /proc/cmdline)\"
        echo ''
        echo 'Kernel Modules Directory:'
        ls -la /lib/modules/ 2>/dev/null || echo 'No /lib/modules directory found'
        echo ''
        echo 'Available Kernel Headers:'
        if find /lib/modules/*/build -maxdepth 0 2>/dev/null | head -1 >/dev/null; then
            find /lib/modules/*/build -maxdepth 0 2>/dev/null | while read dir; do
                version=\$(basename \$(dirname \"\$dir\"))
                echo \"📁 \$version\"
                echo \"   Path: \$dir\"
                echo \"   Size: \$(du -sh \"\$dir\" 2>/dev/null | cut -f1)\"
                if [[ -f \"\$dir/Makefile\" ]]; then
                    echo \"   ✓ Makefile exists\"
                else
                    echo \"   ✗ Makefile missing\"
                fi
                if [[ -f \"\$dir/.config\" ]]; then
                    echo \"   ✓ .config exists\"
                else
                    echo \"   ✗ .config missing\"
                fi
                echo \"   Includes: \$(find \"\$dir/include\" -name '*.h' 2>/dev/null | wc -l) header files\"
                echo ''
            done
        else
            echo '❌ No kernel headers found'
            echo '   This will prevent driver compilation'
            echo '   Try installing: apt-get install linux-headers-generic'
        fi
        echo 'Kernel Header Analysis:'
        RUNNING_KERNEL=\$(uname -r)
        TARGET_DIR=\"/lib/modules/\$RUNNING_KERNEL/build\"
        
        if [[ -d \"\$TARGET_DIR\" ]]; then
            echo \"✅ Perfect match: Headers for \$RUNNING_KERNEL are available\"
        else
            echo \"⚠️  Mismatch: No headers for running kernel \$RUNNING_KERNEL\"
            AVAILABLE_HEADERS=\$(find /lib/modules/*/build -maxdepth 0 2>/dev/null | head -1)
            if [[ -n \"\$AVAILABLE_HEADERS\" ]]; then
                HEADER_VERSION=\$(basename \$(dirname \"\$AVAILABLE_HEADERS\"))
                echo \"   Available: \$HEADER_VERSION\"
                echo \"   Will use: \$AVAILABLE_HEADERS\"
                echo \"   This may work if kernel APIs are compatible\"
            else
                echo \"   No headers available at all\"
            fi
        fi
        echo ''
        echo 'Build Environment Check:'
        echo \"KDIR would be: \${KDIR:-/lib/modules/\$(uname -r)/build}\"
        echo \"Build tools:\"
        which gcc 2>/dev/null && gcc --version | head -1 || echo \"  gcc: not found\"
        which make 2>/dev/null && make --version | head -1 || echo \"  make: not found\"
        which bc 2>/dev/null && echo \"  bc: available\" || echo \"  bc: not found\"
        echo ''
        echo '=== Recommendations ==='
        if [[ -d \"/lib/modules/\$(uname -r)/build\" ]]; then
            echo \"✅ Ready to build - matching headers found\"
        else
            if find /lib/modules/*/build -maxdepth 0 2>/dev/null | head -1 >/dev/null; then
                echo \"⚠️  Can attempt build with available headers\"
                echo \"   The updated build.sh script will auto-detect available headers\"
                echo \"   This may work if kernel versions are close enough\"
            else
                echo \"❌ Cannot build - no headers available\"
                echo \"   Install headers with: apt-get install linux-headers-generic\"
            fi
        fi
    "
}

run_multi_version_test() {
    log_step "Testing across multiple Ubuntu versions..."
    
    local versions=("22.04" "23.04" "24.04")
    local success_count=0
    local total_count=${#versions[@]}
    
    for version in "${versions[@]}"; do
        log_step "Testing with Ubuntu $version..."
        
        if docker run --rm -v "$PWD:/workspace" -w /workspace ubuntu:$version /bin/bash -c "
            apt-get update -qq
            apt-get install -y -qq build-essential linux-headers-generic bc kmod flex libelf-dev libssl-dev
            ./scripts/build.sh --verbose
        " 2>/dev/null; then
            log_info "✓ Ubuntu $version: SUCCESS"
            ((success_count++))
        else
            log_warn "✗ Ubuntu $version: FAILED"
        fi
    done
    
    echo ""
    log_info "Multi-version test results: $success_count/$total_count versions successful"
    
    if [[ $success_count -eq $total_count ]]; then
        log_info "🎉 All versions passed!"
    else
        log_warn "⚠️  Some versions failed - check output above"
    fi
}

run_multi_kernel_test() {
    log_step "Testing across multiple kernel versions..."
    
    log_info "Building multi-kernel test image..."
    if ! docker build -f Dockerfile.kerneltest -t mt7902-kerneltest .; then
        log_error "Failed to build kernel test image"
        return 1
    fi
    
    log_step "Running tests across all available kernel headers..."
    
    # Run the comprehensive kernel test
    docker run --rm -v "$PWD:/workspace" mt7902-kerneltest
    
    # Cleanup
    log_info "Cleaning up test image..."
    docker rmi mt7902-kerneltest >/dev/null 2>&1 || true
    
    log_info "Multi-kernel testing completed!"
    log_info "This test validates our driver against:"
    log_info "  • Kernel 6.8.x (LTS baseline)"
    log_info "  • Kernel 6.14.x (DKMS problem kernel)"  
    log_info "  • Any other available headers"
}

cleanup_docker() {
    log_step "Cleaning up Docker resources..."
    
    # Remove containers
    docker ps -a --filter "ancestor=mt7902-test" --format "{{.ID}}" | xargs -r docker rm -f
    
    # Remove image
    docker rmi mt7902-test 2>/dev/null || log_warn "Image mt7902-test not found"
    
    # Clean up dangling images
    docker image prune -f
    
    log_info "Cleanup completed"
}

main() {
    local command="${1:-build}"
    local verbose_flag=""
    
    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            --verbose)
                verbose_flag="--verbose"
                shift
                ;;
            --help|-h)
                show_help
                exit 0
                ;;
            build|test|debug|kernelcheck|multi|kernels|clean)
                command="$1"
                shift
                ;;
            *)
                if [[ "$1" != "--verbose" ]]; then
                    log_error "Unknown option: $1"
                    show_help
                    exit 1
                fi
                shift
                ;;
        esac
    done
    
    echo "=== MT7902 Docker Test Suite ==="
    
    # Check Docker availability (except for clean command)
    if [[ "$command" != "clean" ]]; then
        check_docker
    fi
    
    case "$command" in
        build)
            build_image
            run_build_test "$verbose_flag"
            ;;
        test)
            build_image
            run_full_test
            ;;
        debug)
            build_image
            run_debug_shell
            ;;
        kernelcheck)
            build_image
            run_kernel_check
            ;;
        multi)
            run_multi_version_test
            ;;
        kernels)
            check_docker
            run_multi_kernel_test
            ;;
        clean)
            cleanup_docker
            ;;
        *)
            log_error "Unknown command: $command"
            show_help
            exit 1
            ;;
    esac
}

# Run main function with all arguments
main "$@"
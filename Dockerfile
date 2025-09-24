# Dockerfile for MT7902 driver testing
FROM ubuntu:24.04

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    bc \
    kmod \
    cpio \
    flex \
    libncurses5-dev \
    libelf-dev \
    libssl-dev \
    dkms \
    wget \
    curl \
    git \
    pciutils \
    wireless-tools \
    iw \
    rfkill \
    && rm -rf /var/lib/apt/lists/*

# Install kernel headers - try multiple approaches for compatibility
RUN apt-get update && \
    (apt-get install -y linux-headers-generic || \
    apt-get install -y linux-headers-$(uname -r) || \
    apt-get install -y linux-headers-6.8.0-84-generic || \
    echo "Warning: Could not install specific kernel headers") && \
    rm -rf /var/lib/apt/lists/*

# Create a symbolic link for easier kernel header detection
RUN if [ ! -L /lib/modules/kernel/build ] && [ -d "/lib/modules" ]; then \
    FIRST_HEADER=$(find /lib/modules/*/build -maxdepth 0 2>/dev/null | head -1); \
    if [ -n "$FIRST_HEADER" ]; then \
    mkdir -p /lib/modules/kernel && \
    ln -sf "$FIRST_HEADER" /lib/modules/kernel/build; \
    fi; \
    fi

WORKDIR /workspace

# Copy source code
COPY . .

# Make scripts executable
RUN chmod +x scripts/*.sh

# Set default command
CMD ["./scripts/build.sh", "--verbose"]
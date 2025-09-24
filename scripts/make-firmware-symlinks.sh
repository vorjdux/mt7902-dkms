#!/usr/bin/env bash
# Helper: create symlinks from existing MT79xx firmware blobs to the MT7902 expected names
# Non-destructive: prompts before creating each symlink and never overwrites existing files.

set -euo pipefail

MTK_FW_DIR=/lib/firmware/mediatek

# Expected target names (what the driver will look for)
ROM_TARGETS=(
    "WIFI_MT7902_patch_mcu_1_1_hdr.bin"
)

RAM_TARGETS=(
    "WIFI_RAM_CODE_MT7902_1.bin"
)

# Family candidates to prefer when creating symlinks (in order)
PREFERRED_FAMILIES=("7902" "7922" "7961" "7925")

if [[ ! -d "$MTK_FW_DIR" ]]; then
    echo "Firmware directory $MTK_FW_DIR not found. Exiting."
    exit 1
fi

echo "Scanning $MTK_FW_DIR for MT79xx firmware files..."

declare -a CANDIDATES=()
for f in "$MTK_FW_DIR"/*; do
    bn=$(basename "$f")
    if [[ "$bn" =~ (MT79|mt79|WIFI_RAM_CODE|patch_mcu) ]]; then
        CANDIDATES+=("$f")
        echo "  Found: $bn"
    fi
done

if [[ ${#CANDIDATES[@]} -eq 0 ]]; then
    echo "No MT79xx-like firmware files found in $MTK_FW_DIR"
    exit 0
fi

prompt_yes_no() {
    # $1 = prompt
    while true; do
        read -r -p "$1 [y/N]: " ans
        case "$ans" in
            [Yy]* ) return 0 ;;
            [Nn]*|"" ) return 1 ;;
            * ) echo "Please answer yes or no." ;;
        esac
    done
}

create_symlink() {
    src="$1"
    dst="$2"

    if [[ -e "$dst" && ! -L "$dst" ]]; then
        echo "Target $dst exists and is not a symlink; skipping to avoid overwriting."
        return
    fi

    if [[ -L "$dst" ]]; then
        echo "Target $dst is already a symlink; skipping."
        return
    fi

    ln -s "$src" "$dst"
    echo "Created symlink: $dst -> $src"
}

echo "\nProposing symlinks to MT7902 expected names (will prompt before creating):"

# For each expected target, pick the best candidate (prefer family order), then prompt
for tgt in "${ROM_TARGETS[@]}"; do
    dst="$MTK_FW_DIR/$tgt"
    if [[ -e "$dst" ]]; then
        echo "Target exists: $tgt (skipping)"
        continue
    fi

    # Prefer candidate that matches one of the preferred families
    chosen=""
    for fam in "${PREFERRED_FAMILIES[@]}"; do
        for c in "${CANDIDATES[@]}"; do
            cbn=$(basename "$c")
            if [[ "$cbn" == *"${fam}"* ]]; then
                chosen="$c"
                break 2
            fi
        done
    done

    # If no preferred family matched, pick the first candidate
    if [[ -z "$chosen" && ${#CANDIDATES[@]} -gt 0 ]]; then
        chosen="${CANDIDATES[0]}"
    fi

    if [[ -n "$chosen" ]]; then
        echo "  Propose: $(basename "$chosen") -> $tgt"
        if prompt_yes_no "Create symlink $tgt -> $(basename "$chosen")?"; then
            create_symlink "$chosen" "$dst"
        fi
    fi
done

for tgt in "${RAM_TARGETS[@]}"; do
    dst="$MTK_FW_DIR/$tgt"
    if [[ -e "$dst" ]]; then
        echo "Target exists: $tgt (skipping)"
        continue
    fi

    chosen=""
    for fam in "${PREFERRED_FAMILIES[@]}"; do
        for c in "${CANDIDATES[@]}"; do
            cbn=$(basename "$c")
            if [[ "$cbn" == *"${fam}"* ]]; then
                chosen="$c"
                break 2
            fi
        done
    done

    if [[ -z "$chosen" && ${#CANDIDATES[@]} -gt 0 ]]; then
        chosen="${CANDIDATES[0]}"
    fi

    if [[ -n "$chosen" ]]; then
        echo "  Propose: $(basename "$chosen") -> $tgt"
        if prompt_yes_no "Create symlink $tgt -> $(basename "$chosen")?"; then
            create_symlink "$chosen" "$dst"
        fi
    fi
done

echo "Done. If you created symlinks, reload the modules or reboot to apply changes."

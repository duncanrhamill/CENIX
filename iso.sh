#!/bin/sh
set -e
. ./build.sh
mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/cenix.kernel isodir/boot/cenix.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "cenix" {
    multiboot /boot/cenix.kernel
}
EOF
grub-mkrescue -o cenix.iso isodir

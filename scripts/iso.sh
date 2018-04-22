#!/bin/sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub
mkdir -p isodir/boot/grub/fonts
export PREF=isodir/boot/

cp sysroot/boot/picOS.kernel ${PREF}
cp loader/unicode.pfs2 ${PREF}grub/fonts
if [ -d /sys/firmware/efi ]; then
  cp loader/grub_uefi.cfg ${PREF}grub/grub.cfg
else
  cp loader/grub_bios.cfg ${PREF}grub/grub.cfg
fi
grub-mkrescue -o picOS.iso isodir

#!/bin/sh

if [ $debug ]
  then
  objcopy --only-keep-debug kernel/picOS.kernel picOS.sym
  qemu-system-$(./scripts/target-triplet-to-arch.sh $HOST) -d guest_errors \
  -s -S -cdrom picOS.iso &
  gdb -s picOS.sym -ex "target remote localhost:1234"
  else
  qemu-system-$(.scripts/target-triplet-to-arch.sh $HOST) -d guest_errors \ 
  -cdrom picOS.iso
fi

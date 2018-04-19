#!/bin/sh



#managing arguments
while [[ $# -gt 0 ]]
do
  key="$1"
  case $key in
  -gdb|--debug)
    shift
    export debug="defined"
    ;;
  *)
    echo "qemu.sh : Unkown option : $1"
    exit 0
    ;;
  esac
done

set -e
. ./iso.sh

if [ $debug ]
  then
  objcopy --only-keep-debug kernel/picOS.kernel picOS.sym
  qemu-system-$(./target-triplet-to-arch.sh $HOST) -d guest_errors -s -S -cdrom\
    picOS.iso &
  gdb -s picOS.sym -ex "target remote localhost:1234"
  else
  qemu-system-$(./target-triplet-to-arch.sh $HOST) -d guest_errors -cdrom\
    picOS.iso
fi

#!/bin/sh

# This is the main script to build the project. Description of options below :

#   Output options
#   if nothing is specified, the script stop after producing the iso
#     -o      Only load configration file
#     -c      Perform clean after every other operation
#     -d      Delete all produced files. Equivalent to -o -c
#     -i      Only install headers, dont build the kernel
#     -b      Only build the project, do not produce bootable iso
#     -q      Run qemu on the iso
#     -f NAME Flash the iso on /dev/NAME
#
#   Build options
#     --force Force the project to be built, bypassing warnings
#     --debug  Define the __MY_DEBUG__ macro.
#
#   Iso options
#
#   Qemu options
#     --gdb    Lauch qemu monitored by gdb
#

# managing arguments

export install="defined"
export build="defined"
export iso="defined"
export qemu=""
export flash=""
export clean=""
export warns_as_errors="defined"
export debug=""
export gdb=""

while [[ $# -gt 0 ]]
do
  key="$1"
  case $key in
  -d)
    shift
    export install=""
    export build=""
    export iso=""
    export flash=""
    export qemu=""
    export clean="defined"
    ;;
  -o)
    shift
    export install=""
    export build=""
    export iso=""
    export flash=""
    export qemu=""
    ;;
  -c)
    shift
    export clean="defined"
    ;;
  -i)
    shift
    export build=""
    export iso=""
    export qemu=""
    ;;
  -b)
    shift
    export build="defined"
    export iso=""
    export qemu=""
    ;;
  -q)
    shift
    export build="defined"
    export iso="defined"
    export qemu="defined"
    ;;
  -f)
    shift
    export build="defined"
    export iso="defined"
    export flash="defined"
    shift
    export dev_name="$1"
    ;;
  --force)
    shift
    export warns_as_errors=""
    ;;
  --debug)
    shift
    export debug="defined"
    ;;
  --gdb)
    shift
    export gdb="defined"
    ;;
  *)
    echo "mk : Unkown option : $1"
    exit 0
    ;;
  esac
done

set -e
. ./scripts/config.sh
if [ $gdb ]
  then . ./scripts/clean.sh
fi
. ./scripts/headers.sh
if [ $build ]
  then . ./scripts/build.sh
fi
if [ $iso ]
  then . ./scripts/iso.sh
fi
if [ $qemu ]
  then . ./scripts/qemu.sh
fi
if [ $flash ]
  then . ./scripts/flash.sh $dev_name
fi
if [ $clean ]
  then . ./scripts/clean.sh
fi

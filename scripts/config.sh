SYSTEM_HEADER_PROJECTS="libc kernel"
PROJECTS="libc kernel"

export MAIN_ROOT=`pwd`
export MAKE=${MAKE:-make}
export HOST=${HOST:-$(./scripts/default-host.sh)}
if [ -f scripts/path ] ; then
  export PATH=$(cat scripts/path):$PATH
else
  echo "Error : path file not found"
  echo "Please add a file path with the path to your cross compilers"
  echo "in the scripts folder."
  exit 1
fi
echo $PATH

export AR=${HOST}-ar
export AS=${HOST}-as
export CC=${HOST}-gcc

export PREFIX=/usr
export EXEC_PREFIX=$PREFIX
export BOOTDIR=/boot
export LIBDIR=$EXEC_PREFIX/lib
export INCLUDEDIR=$PREFIX/include

if [ $gdb ]; then
  export CFLAGS='-O0'
else
  export CFLAGS='-Ofast'
fi

if [ $debug ]; then 
  export CFLAGS="$CFLAGS -D __MY_DEBUG__"
fi
if [ $gdb ]; then 
  export CFLAGS="$CFLAGS -ggdb"
fi
if [ $warns_as_errors ]; then
  export CFLAGS="$CFLAGS -Werror"
fi
export CFLAGS="$CFLAGS -Wno-error=unused-parameter \
-Wno-error=unused-but-set-variable \
-Wno-error=unused-variable \
"

export CPPFLAGS=''

# Configure the cross-compiler to use the desired system root.
export SYSROOT="$(pwd)/sysroot"
export CC="$CC --sysroot=$SYSROOT"

# Work around that the -elf gcc targets doesn't have a system include directory
# because it was configured with --without-headers rather than --with-sysroot.
if echo "$HOST" | grep -Eq -- '-elf($|-)'; then
  export CC="$CC -isystem=$INCLUDEDIR"
fi

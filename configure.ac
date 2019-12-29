
AC_PREREQ(2.57)
AC_INIT([bolthur-driver], [0.1], [https://github.com/bolthur/driver/issues], [bolthur-driver], [https://github.com/bolthur/driver])
AC_COPYRIGHT([Copyright (C) 2018 - 2019 bolthur project])

AC_CONFIG_AUX_DIR([build-aux/config])
AC_CONFIG_MACRO_DIR([build-aux/m4])

AC_CANONICAL_HOST
AC_CONFIG_SRCDIR([src/main.c])
AM_INIT_AUTOMAKE()
AC_CONFIG_HEADERS([src/config.h])

AC_LANG([C])

# Prevent enter folder output
AC_SUBST(MAKEFLAGS, "${MAKEFLAGS} --no-print-directory")

AC_ARG_ENABLE([device],
  AC_HELP_STRING(
    [--enable-device],
    [set target device to compile for [possible targets: rpi2_b_rev1]]
  ),
  [enable_device=$enableval],
  [AC_MSG_ERROR([Target device missing])]
)

AC_ARG_WITH(
  [optimization-level],
  AC_HELP_STRING(
    [--with-optimization-level],
    [compile with specific code optimization level [possible values: 0, 1, 2, 3, s, g | default: 2]]
  ),
  [with_optimization_level=$withval]
)

AC_ARG_WITH(
  [debug-symbols],
  AC_HELP_STRING(
    [--with-debug-symbols],
    [compile with debug symbols]
  ),
  [with_debug_debug_symbols=yes]
)

# set target and flags
BOLTHUR_DRIVER_SET_DEVICE
BOLTHUR_DRIVER_SET_HOST
# set rest of flags
BOLTHUR_DRIVER_SET_FLAG

# conftest
AC_LANG_CONFTEST([AC_LANG_SOURCE([[const char hw[] = "Hello, World\r\n";]])])

# checks for programs
AC_PROG_CC
AC_PROG_RANLIB

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_VOLATILE
AC_C_RESTRICT

# Some compiler dependent features.
AC_DEFINE_UNQUOTED(
  [__packed],
  [__attribute__((__packed__))],
  [Keyword for packing structures.]
)
AC_DEFINE_UNQUOTED(
  [__section(x)],
  [__attribute__((__section__(x)))],
  [Keyword for section placement.]
)
AC_DEFINE_UNQUOTED(
  [__aligned(x)],
  [__attribute__((__aligned__(x)))],
  [Keyword for alignment.]
)
AC_DEFINE_UNQUOTED(
  [__no_optimization],
  [__attribute__((__optimize__("O0")))],
  [Disable optimization]
)
AC_DEFINE_UNQUOTED(
  [__unused],
  [__attribute__((unused))],
  [Unused function]
)
AC_DEFINE_UNQUOTED(
  [__no_sanitize],
  [__attribute__((no_sanitize("undefined")))],
  [disable undefined behaviour sanitization]
)
AC_DEFINE_UNQUOTED(
  [__no_return],
  [__attribute__((noreturn))],
  [mark function as function without continuing exectution]
)
AC_DEFINE_UNQUOTED(
  [__constructor],
  [__attribute__((constructor))],
  [mark function as constructor]
)
AC_DEFINE_UNQUOTED(
  [__alias(x)],
  [__attribute__((alias(x)))],
  [alias function]
)

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  src/generic/Makefile
  src/generic/vfs/Makefile
  src/platform/Makefile
  src/platform/rpi/Makefile
  src/platform/rpi/emmc/Makefile
  src/platform/rpi/network/Makefile
  src/platform/rpi/uart/Makefile
  src/platform/rpi/usb/Makefile
])

AC_OUTPUT

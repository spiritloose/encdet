#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT(encdet, 0.1.0, jiro@cpan.org)
AC_CONFIG_SRCDIR([src/encdet.cpp])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_HEADER([src/config.h])
AM_INIT_AUTOMAKE($PACKAGE_NAME, $PACKAGE_VERSION)

LTVERSION="0:0:0"
AC_SUBST(LTVERSION)

# Checks for programs.
AC_PROG_CC
AM_PROG_CC_C_O
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_LN_S
AC_PROG_MAKE_SET

if test "$GCC" = "yes"; then
  CFLAGS="$CFLAGS -Wall -Wextra -Wno-unused-parameter"
fi
#if test "$GXX" = "yes"; then
#  CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wno-unused-parameter"
#fi

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 man/Makefile
                 test/Makefile])
AC_OUTPUT

AC_MSG_RESULT
AC_MSG_RESULT([configure complete, now type \"make\" to build $PACKAGE_NAME $PACKAGE_VERSION])


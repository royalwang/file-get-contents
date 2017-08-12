AC_PREREQ([2.69])
AC_INIT([file-get-contents], [1.0.0], [https://github.com/daniel-araujo/file-get-contents/issues])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects silent-rules])

AC_CONFIG_SRCDIR([src/file-get-contents.h])
AC_CONFIG_FILES([Makefile])

AC_PROG_CC
AC_PROG_RANLIB

AC_TYPE_SIZE_T

AX_CHECK_COMPILE_FLAG([-std=c11],
	[AX_APPEND_FLAG([-std=c11])],
	[AC_MSG_ERROR([-std=c11 not supported.])])

# Error messages: the more the better.
AX_APPEND_FLAG([-Wall -Wextra])

# Allowing C files to rely on being able to include files relative to the src
# directory.
AX_APPEND_FLAG([-iquote $srcdir/src -iquote src])

AC_OUTPUT

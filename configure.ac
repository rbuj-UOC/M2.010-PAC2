AC_PREREQ([2.71])

AC_INIT(g_compropietarios2, 1.0, rbuj@uoc.edu)
AM_INIT_AUTOMAKE([1.9 foreign dist-xz no-dist-gzip check-news])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_CONFIG_SRCDIR([src/g_compropietarios2.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION(0.20)

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_CHECK_FUNCS([floor modf setlocale])

GETTEXT_PACKAGE=AC_PACKAGE_NAME
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE, "$GETTEXT_PACKAGE",
                   [The gettext translation domain])
AC_SUBST(GETTEXT_PACKAGE)

g_compropietarios2_CPPFLAGS="-g -Og -Wall -Wextra -std=c++14"
AC_SUBST([g_compropietarios2_CPPFLAGS])

AC_CONFIG_FILES([Makefile src/Makefile po/Makefile.in])
AC_OUTPUT

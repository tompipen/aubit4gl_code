dnl This file is in the public domain.

dnl Checks for $INFORMIXDIR and $INFORMIXDIR/bin in $PATH.
dnl People who add trailing slashes to the directories in $PATH will suffer.
AC_DEFUN(AC_INFORMIX_ENV,
[AC_MSG_CHECKING([whether the Informix environment looks sane])
if test "x$INFORMIXDIR" != x && test -d "$INFORMIXDIR"; then
    ac_junk_ixp=no
    for ac_junk in `echo "$PATH" | sed 's/:/ /g'`; do
	if test "$ac_junk" = "$INFORMIXDIR/bin"; then
	    ac_junk_ixp=yes
	    break
	fi
    done
    if test "$ac_junk_ixp" = yes; then
	AC_MSG_RESULT(yes)
    else
	AC_MSG_RESULT(no)
	AC_MSG_ERROR([\$INFORMIXDIR/bin not in \$PATH])
    fi
else
    AC_MSG_RESULT(no)
    AC_MSG_ERROR([\$INFORMIXDIR not set or not a directory])
fi])

dnl ESQL/C AC_LANG definition.
AC_DEFUN(AC_LANG_ESQLC,
[define([AC_LANG], [ESQLC])dnl
ac_ext=ec
if test -n "$INFORMIXC"; then
    ac_link='${ESQL-esql} $ESQLFLAGS -o conftest $LDFLAGS conftest.$ac_ext 1>&AC_FD_CC'
else
    ac_link='${ESQL-esql} $ESQLFLAGS $CFLAGS -o conftest $LDFLAGS conftest.$ac_ext 1>&AC_FD_CC'
fi
])

dnl Checks whether the ESQL/C preprocessor works.
AC_DEFUN(AC_PROG_ESQL_WORKS,
[if test ! -n "$INFORMIXC"; then
    ac_junk_cflags="$CFLAGS"
fi
AC_MSG_CHECKING([whether the ESQL/C preprocessor (${ESQL}${ESQLFLAGS+ $ESQLFLAGS}${ac_junk_cflags+ $ac_junk_cflags}${LDFLAGS+ $LDFLAGS}) works])
AC_LANG_SAVE
AC_LANG_ESQLC
AC_TRY_COMPILER([main(){
EXEC SQL close database;
}], ac_cv_prog_esql_works, ac_junk)
AC_LANG_RESTORE
AC_MSG_RESULT($ac_cv_prog_esql_works)
if test $ac_cv_prog_esql_works = no; then
    AC_MSG_ERROR([installation or configuration problem with ESQL/C])
fi
])

dnl Determines the ESQL/C version.
AC_DEFUN(AC_PROG_ESQLC_VERSION,
[AC_CACHE_CHECK(${ESQL-esql} version, ac_cv_prog_esqlc_version,
[ac_junk=`${ESQL-esql} -V 2>/dev/null |
changequote(, )dnl
	  sed -e 's/[ ]*$//' -e 's/.* \([^ ]*\)$/\1/' -e 1q`
changequote([, ])dnl
if test "x$ac_junk" != x; then
    ac_cv_prog_esqlc_version=$ac_junk
else
    ac_cv_prog_esqlc_version="0.00.AA0"
fi])])

dnl Checks for rgetlmsg().
AC_DEFUN(AC_FUNC_RGETLMSG,
[AC_LANG_SAVE
AC_LANG_ESQLC
ac_ext=c
dnl That was gross, but we don't want esql to insert any #include's
dnl with true prototypes.
AC_CHECK_FUNC(rgetlmsg, AC_DEFINE(HAVE_RGETLMSG))
AC_LANG_RESTORE
])

dnl Checks for an ESQL/C preprocessor.
AC_DEFUN(AC_PROG_ESQL,
[AC_CHECK_PROG(ESQL, esql, esql)
if test -z "$ESQL"; then
    AC_CHECK_PROG(ESQL, c4gl, c4gl)
    test -z "$ESQL" && AC_MSG_ERROR([no ESQL/C preprocessor found in \$PATH])
fi
AC_PROG_ESQLC_VERSION
AC_PROG_ESQL_WORKS
])

# build configuration for autotools
#
# ToDo: as_echo is deprecated
#
# autoconf setup:
# [projekt name], [version], [bug report address]
AC_INIT([stdttests], [0.0.1])

# safety check in case user has overwritten --srcdir
AC_CONFIG_SRCDIR([configure.ac])

AC_CONFIG_AUX_DIR([autotools])

# we have only a makefile in the main directory
SUBDIRS=.
DIST_SUBDIRS=.

# silence output:
# disabled in this early state
AM_SILENT_RULES([yes])
AM_SILENT_RULES([no])


## get maintainer-mode from env
## maintainer should see all warnings
## probably bail out with an error
## set default:
#AM_MAINTAINER_MODE([disable])
AM_MAINTAINER_MODE([enable])

# option disabled in this early state

#$as_echo "checking environment for MAINTAINER_MODE"
#if test  -n "$MAINTAINER_MODE" ; then
#$as_echo "maintainer_mode"
#AM_MAINTAINER_MODE([enable])
#fi



# Allow controlling debug mode from the configure script
# use --enable-debug  for -DDEBUG
# use --disable-debug for -DNDEBUG
AC_ARG_ENABLE([debug],
[  --enable-debug          Activate DEBUG mode],
[case "${enableval}" in
  yes) debug_mode=true ;;
  no)  debug_mode=false ;;
  on) debug_mode=true ;;
  off)  debug_mode=false ;;
  *) AC_MSG_ERROR([invalid value ${enableval} for --enable-debug]) ;;
esac],[debug_mode=false])

AM_CONDITIONAL([DEBUG], [test x$debug_mode = xtrue])


# ToDo: add more options here

#####################################
#
# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html

AC_CONFIG_FILES([Makefile])

# Tell automake to create a config result file
AC_CONFIG_HEADERS([config.h])


#############################################################
# 
# autotools generate checks also for very old, ancient systems.
# 
# Try to avoid some of the features for a speedup
# overwrite with: $ANCIENT_OR_BROKEN_SYSTEM  

if test -z "$ANCIENT_OR_BROKEN_SYSTEM"; then :
AS_ECHO(["ANCIENT_OR_BROKEN_SYSTEM not set."])
AS_ECHO(["Extra caching is activated to speedup autotools."])

# claim, that we have a BSD-compatible install. overwrite with $INSTALL
if test -z "$INSTALL"; then
ac_cv_path_install="`which install` -c"
fi

# claim, that we have a thread save mkdir -p: overwrite with $MKDIR_P
if test -z "$MKDIR_P"; then
ac_cv_path_mkdir="`which mkdir` -p"
fi

# claim, that we have an awk, that work as expected: overwrite with $AWK
if test -z "$AWK"; then
ac_cv_prog_AWK="`which gawk` "
if test -z "$ac_cv_prog_AWK"; then
ac_cv_prog_AWK="`which awk` "
fi
fi

# claim, that the compiler accepts -g
ac_cv_prog_cc_g="yes"

# claim, that the compiler understand C89 without an option
ac_cv_prog_cc_c89=""

# claim, that the compiler understand -c and -o together
am_cv_prog_cc_c_o="yes"
fi

#
# end of speedup block 1
#############################################################

# Init automake with relaxed structures:
# ChangeLog, COPYING, AUTHORS, INSTALL, README etc. are not required
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])


# Check for C compiler
AC_PROG_CC

# Check for C++ compiler
AC_PROG_CXX


# When checking for any C Header,
# autotools adds many additional tests:
# * how to run the C preprocessor,
# * grep that handles long lines and -e
# * egrep
# * ANSI C header files ( stdlib.h stdarg.h string.h float.h )
# * sys/types.h
# * sys/stat.h
# * stdlib.h
# * string.h
# * memory.h
# * strings.h
# * inttypes.h
# * stdint.h
# * unistd.h

#############################################################
# 
# autotools generate checks also for very old, ancient systems.
# 
# Try to avoid some of the features for a speedup
# overwrite with: $ANCIENT_OR_BROKEN_SYSTEM

if test -z "$ANCIENT_OR_BROKEN_SYSTEM"; then :

# claim, that the compiler works with -E as preprocessor. overwrite with $CPP
if test -z "$CPP"; then :
if test -n "$CC"; then :
ac_cv_prog_CPP="$CC -E "
fi
fi

# claim, that grep works as expected. overwrite with $GREP
if test -z "$GREP"; then :
ac_cv_path_GREP="`which grep`"
if test -n "$ac_cv_path_GREP" ; then
ac_cv_path_EGREP="$ac_cv_path_GREP -E"
fi
fi

# claim, that we have the required stdc headers
# old autotools checked: stdlib.h stdarg.h string.h and float.h
# current autotools check: stdio.h stdlib.h string.h 
# inttypes.h stdint.h and float.h
# stdio.h stdlib.h string.h inttypes.h stdint.hand float.h

#ac_cv_header_stdc="yes"
#ac_cv_header_stdlib_h="yes"
#ac_cv_header_stdarg_h="yes"
#ac_cv_header_string_h="yes"
#ac_cv_header_float_h="yes"

# claim, that we have also the extra headers
# hey autotools, when stdc headers are found,
# why are there also stdc header in this list?
#ac_cv_header_sys_types_h="yes"
#ac_cv_header_sys_stat_h="yes"
#ac_cv_header_stdlib_h="yes"
#ac_cv_header_string_h="yes"
#ac_cv_header_memory_h="yes"
#ac_cv_header_inttypes_h="yes"
#ac_cv_header_stdint_h="yes"

# this extra unix header might be missing on windows
# ac_cv_header_unistd_h="yes"

# this non stdc header might be missing
# ac_cv_header_strings_h="yes"

fi

# end of speedup block 2
#############################################################



#############################################
# checking for system header:
#
#

# vararg.h is for variable arguments in K&R C
# that header was replaced with stdarg.h
AC_CHECK_HEADERS([ vararg.h ])


# using AC. HEADER_STDC is obsolete and produce a warning
#AC_HEADER_STDC

AC_LANG([C])

# loading my c header list
# my_c_header_list=`grep -v "^#"  "$srcdir/c/c23_header.txt" | sort -u | tr "\012" " " `
# echo >c_filtered_headers.txt $my_c_header_list

AC_CHECK_HEADERS([\
    assert.h complex.h ctype.h errno.h fenv.h float.h inttypes.h iso646.h \
    limits.h locale.h math.h setjmp.h signal.h stdalign.h stdarg.h stdatomic.h \
    stdbool.h stdckdint.h stddef.h stdint.h stdio.h stdlib.h stdnoreturn.h \
    string.h tgmath.h threads.h time.h uchar.h wchar.h wctype.h \
])


AC_LANG([C++])

# loading my c++ header list
# my_cxx_header_list=`cat "$srcdir/cxx/c_header.txt" "$srcdir/cxx/cxx_header.txt" | grep -v "^#"  | sort -u | tr "\012" " " `
# echo >cxx_filtered_headers.txt $my_cxx_header_list

AC_CHECK_HEADERS([\
    algorithm allocators any array atomic bit bitset cassert ccomplex cctype \
    cerrno cfenv cfloat charconv chrono cinttypes ciso646 climits clocale cmath \
    codecvt compare complex concepts condition_variable contract coroutine \
    csetjmp csignal cstdalign cstdarg cstdbool cstddef cstdint cstdio cstdlib \
    cstdlibnumeric cstring ctgmath ctime cuchar cvt/wbuffer cvt/wstring cwchar \
    cwctype deque exception execution filesystem forward_list fstream functional \
    future initializer_list iomanip ios iosfwd iostream istream iterator limits \
    list locale map memory memory_resource mutex new numeric optional ostream \
    queue random ranges ratio regex scoped_allocator set shared_mutex span sstream \
    stack stdexcept streambuf string string_view strstreamc syncstream system_error \
    thread tuple type_traits typeindex typeinfo unordered_map unordered_set \
    utility variant vector version  \
])


#############################################
# Check for functions
# pthread_create as example

if test "$ac_cv_header_pthread_h" = "yes"
then
    AC_CHECK_FUNC(pthread_create,,[AC_CHECK_LIB(pthread,pthread_create,[AC_SUBST(PTHREAD_LIBS,"-lpthread")])])
fi


#############################################
# Now write the output files

AC_OUTPUT


AS_ECHO(["reached the end"])



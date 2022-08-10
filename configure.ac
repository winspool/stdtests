# build configuration for autotools
#
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

#######################################
#
# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html

AC_CONFIG_FILES([Makefile])

# Tell automake to create a config result file
AC_CONFIG_HEADERS([config.h])


#######################################
# set defaults for my used options

USE_DEBUG="2"
USE_MAINTAINER_MODE="2"

CHECK_C="2"
CHECK_CXX="2"
CHECK_LIBC="2"
CHECK_STDCXX="2"

WITH_LIBC="2"

# silence output: disabled in this early state
AM_SILENT_RULES([no])

# MAINTAINER_MODE: always active in this early project state
AM_MAINTAINER_MODE([enable])

# support activating MAINTAINER_MODE from environment
if test  -n "$MAINTAINER_MODE" ;
then
    AM_MAINTAINER_MODE([enable])
fi



#######################################
# support extra command line arguments:

# use --enable-debug  for -DDEBUG
# use --disable-debug for -DNDEBUG
AC_ARG_ENABLE(debug, AS_HELP_STRING([--enable-debug],[Activate DEBUG mode]))

AC_ARG_ENABLE(maintainer-mode, AS_HELP_STRING([--enable-maintainer-mode],[enable maintainer-specific build rules]))

AC_ARG_ENABLE(c,      AS_HELP_STRING([--disable-c],      [Do not check the C Compiler (use the C++ compiler)]))
AC_ARG_ENABLE(cxx,    AS_HELP_STRING([--disable-cxx],    [Do not check the C++ Compiler (use the C compiler)]))
AC_ARG_ENABLE(libc,   AS_HELP_STRING([--disable-libc],   [Do not check the C runtime library]))
AC_ARG_ENABLE(stdcxx, AS_HELP_STRING([--disable-stdcxx], [Do not check the C++ runtime library]))

AC_ARG_WITH(libc, AS_HELP_STRING([--without-libc], [Do not link to a C runtime library (use builtins)]))


#######################################
# handle command line arguments

# manage debug mode from the configure script
# use --enable-debug  for -DDEBUG
# use --disable-debug for -DNDEBUG
if test ${enable_debug}
then
    case "$enable_debug" in
    "yes" | "ja" | "on" | "1" | "enable" )
        USE_DEBUG="1"
        AC_DEFINE_UNQUOTED(DEBUG, 1, [Define to 1 to activate DEBUG build])
        ;;
    "no" | "nein" | "off" | "0" | "disable" )
        USE_DEBUG="0"
        AC_DEFINE_UNQUOTED(NDEBUG, 1, [Define to 1 to use a release build (deactivate DEBUG)])
        ;;
    *)
        as_fn_error 1 "invalid value for --enable-debug: ${enable_debug}"
        ;;
    esac
fi


# using AM _MAINTAINER_MODE sets USE_MAINTAINER_MODE,
# so use that as default for enable_maintainer_mode
if test -z ${enable_maintainer_mode}
then
    enable_maintainer_mode="$USE_MAINTAINER_MODE"
fi

if test ${enable_maintainer_mode}
then
    case "$enable_maintainer_mode" in
    "yes" | "ja" | "on" | "1" | "enable" )
        USE_MAINTAINER_MODE="1"
        AC_DEFINE_UNQUOTED(MAINTAINER_MODE, 1, [Define to 1 to activate MAINTAINER_MODE build])
        ;;
    "no" | "nein" | "off" | "0" | "disable" )
        USE_MAINTAINER_MODE="0"
        ;;
    *)
    as_fn_error 1 "invalid value for --enable-maintainer_mode: ${enable_maintainer_mode}"
    ;;
  esac
fi


if test ${enable_c}
then
    case "$enable_c" in
    "yes" | "ja" | "on" | "1" | "enable" )
        CHECK_C="1"
        CHECK_CXX="0"
        CHECK_STDCXX="0"
        ;;
    "no" | "nein" | "off" | "0" | "disable" )
        CHECK_C="0"
        ;;
    *)
        as_fn_error 1 "invalid value for --enable-c: ${enable_c}"
        ;;
    esac
fi


if test ${enable_cxx}
then
  case "$enable_cxx" in
  "yes" | "ja" | "on" | "1" | "enable" )
        CHECK_CXX="1"
        CHECK_C="0"
        CHECK_LIBC="0"
        ;;
  "no" | "nein" | "off" | "0" | "disable" )
        CHECK_CXX="0"
        CHECK_STDCXX="0"
        ;;
    *)
        as_fn_error 1 "invalid value for --enable-cxx: ${enable_cxx}"
        ;;
    esac
fi


if test ${enable_libc}
then
    case "$enable_libc" in
    "yes" | "ja" | "on" | "1" | "enable" )
        CHECK_LIBC="1"
        ;;
    "no" | "nein" | "off" | "0" | "disable" )
        CHECK_LIBC="0"
        ;;
    *)
        as_fn_error 1 "invalid value for --enable-libc: ${enable_libc}"
        ;;
    esac
fi


if test ${enable_stdcxx}
then
    case "$enable_stdcxx" in
    "yes" | "ja" | "on" | "1" | "enable" )
        CHECK_STDCXX="1"
        ;;
    "no" | "nein" | "off" | "0" | "disable" )
        CHECK_STDCXX="0"
        ;;
    *)
        as_fn_error 1 "invalid value for --enable-stdcxx: ${enable_stdcxx}"
        ;;
    esac
fi


#######################################
# debug current settings

if test "$USE_DEBUG" != "0"
then
AS_ECHO(["USE_MAINTAINER_MODE: $USE_MAINTAINER_MODE"])

AS_ECHO(["USE_DEBUG:    $USE_DEBUG"])

AS_ECHO(["CHECK_C:      $CHECK_C"])
AS_ECHO(["CHECK_CXX:    $CHECK_CXX"])

AS_ECHO(["CHECK_LIBC:   $CHECK_LIBC"])
AS_ECHO(["CHECK_STDCXX: $CHECK_STDCXX"])

AS_ECHO(["WITH_LIBC:    $WITH_LIBC"])

fi


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

if test "$USE_MAINTAINER_MODE" != "0"
then
# load and filter my c header list:
# * remove all comment lines
# * sort and remove duplicates
# * join header names to one line
my_c_header_list=`grep -v "^#"  "$srcdir/c/c23_header.txt" | sort -u | tr "\012" " " `
echo >c_filtered_headers.txt $my_c_header_list
fi

if test "$CHECK_LIBC" != "0"
then

AC_LANG([C])

AS_ECHO(["checking a K&R C header"])

# vararg.h is for variable arguments in K&R C
# that header was replaced with stdarg.h
AC_CHECK_HEADERS([ vararg.h ])


AS_ECHO(["checking C23 header"])


# using AC. HEADER_STDC is obsolete and produces a warning in autoconf
#AC. _HEADER_STDC


AC_CHECK_HEADERS([\
    assert.h complex.h ctype.h errno.h fenv.h float.h inttypes.h iso646.h \
    limits.h locale.h math.h setjmp.h signal.h stdalign.h stdarg.h stdatomic.h \
    stdbool.h stdckdint.h stddef.h stdint.h stdio.h stdlib.h stdnoreturn.h \
    string.h tgmath.h threads.h time.h uchar.h wchar.h wctype.h \
])
fi


### c++ headers

if test "$USE_MAINTAINER_MODE" != "0"
then
# load and filter my c++ header list:
# * remove all comment lines
# * sort and remove duplicates
# * join header names to one line
my_cxx_header_list=`cat "$srcdir/cxx/c_header.txt" "$srcdir/cxx/cxx_header.txt" | grep -v "^#"  | sort -u | tr "\012" " " `
echo >cxx_filtered_headers.txt $my_cxx_header_list
fi


if test "$CHECK_STDCXX" != "0"
then

AC_LANG([C++])

AS_ECHO(["checking C++20 header"])

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

fi


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



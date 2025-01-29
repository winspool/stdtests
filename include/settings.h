/* use a single header for various project settings */
/* "config.h" is also included here */

#ifndef SETTINGS_H_INCLUDED
#define SETTINGS_H_INCLUDED

/* ################################################################## */
/* Prefer POSIX.1-2024 aka The Open Group Base Specifications Issue 8 */
#if defined _POSIX_C_SOURCE && _POSIX_C_SOURCE < 202405L
#undef _POSIX_C_SOURCE
#endif

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 202405L
#endif

/* Prefer The Open Group Base Specifications Issue 8 aka POSIX.1-2024 */
#if defined _XOPEN_SOURCE && _XOPEN_SOURCE < 800
#undef _XOPEN_SOURCE
#endif

#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 800
#endif


/* activate more extensions, when available */
#define _ISOC99_SOURCE  1
#define _ISOC11_SOURCE  1
#define _ISOC2X_SOURCE  1
#define _ISOC23_SOURCE  1


/* activate GNU extensions, when available */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

/* activate BSD extensions, when available */
#ifndef _BSD_SOURCE
#define _BSD_SOURCE
#endif

/* modern glibc will complain about above defines without _DEFAULT_SOURCE */
#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif


/* ################################################## */
/* Added in C23, was a gcc extension since many years */
#ifndef __has_include
#define __has_include(name) (0)
#endif


/* ################################################ */
/* first include is always "config.h" from autoconf */
/* "config.h" has no include guard. */
#ifndef PACKAGE_NAME
#ifdef HAVE_CONFIG_H
#include "config.h"
#elif __has_include("config.h")
#include "config.h"
#endif /* end of HAVE_CONFIG_H */
#endif /* end of PACKAGE_NAME */


/* workaround: cross compiling for WIN32/WIN64 can produce failures */
/* (header found, but no implementation available) */
/* use our own implementation of "getopt_long" instead */
#ifdef _WIN32
#undef HAVE_GETOPT_LONG
#undef HAVE_GETOPT_H
#undef HAVE_LIBGEN_H
#undef HAVE_UNISTD_H
#endif


/* ######################## */
/* threading mode selection */
/* "DISABLE_THREADS" is set:
    * disable threading code */
/* "ENABLE_THREADS" is set:
    * enable threading code */

/* "DISABLE_THREADS" and "ENABLE_THREADS" are unset:
   threading depends on one of:
    * _REENTRANT: gcc/clang/tcc with "-pthread" (also solaris, osf*)
    * _THREAD_SAFE: FreeBSD, aix
    * _PTHREADS: pcc with "-pthread"
    * __MT__: used by many compilers on Windows
    * _MT: OpenWatcom has nothing else. use "owcc" with "-mthreads"
 */

#ifdef DISABLE_THREADS
#undef ENABLE_THREADS
#endif

#ifndef DISABLE_THREADS
#ifndef ENABLE_THREADS

#if defined _REENTRANT
#define ENABLE_THREADS
#elif defined _THREAD_SAVE
#define ENABLE_THREADS
#elif defined _PTHREADS
#define ENABLE_THREADS
#elif defined __MT__
#define ENABLE_THREADS
#elif defined _MT
#define ENABLE_THREADS
#else
#define DISABLE_THREADS
#endif

#endif /* end of ENABLE_THREADS */
#endif /* end of DISABLE_THREADS */


/* #################### */
/* debug mode selection */
/* "NDEBUG" is set
   * disable debug code */
/* "DEBUG" is set:
   * debug code active
   * use debug mode from "DEBUG" value */

/* "NDEBUG" and "DEBUG" are unset:
    NDEBUG/DEBUG depends on:
    * __OPTIMIZE__ set (release)
      use "NDEBUG"
    * __OPTIMIZE__ unset (dev)
      use "DEBUG 1"
 */

#ifdef NDEBUG
#undef DEBUG
#endif

#ifndef NDEBUG
#ifndef DEBUG
#ifdef  __OPTIMIZE__
#define NDEBUG
#else
#define DEBUG 1
#endif /* end of __OPTIMIZE__ */
#endif /* end of DEBUG */
#endif /* end of NDEBUG */


/* ################################## */
/* __VA_ARGS__ is available since C99 */
/* inline is available since C99 */

#ifdef __STDC_VERSION__
#if    __STDC_VERSION__ >= 199901L
#ifndef ENABLE_VARARGS
#define ENABLE_VARARGS
#endif /* end of ENABLE_VARARGS */
#ifndef EASYINLINE
#define EASYINLINE inline
#endif  /* end of EASYINLINE */
#endif  /* end of __STDC_VERSION__ >= 199901 */
#endif  /* end of __STDC_VERSION__ */

#ifdef __cplusplus
#if    __cplusplus >= 201103L
#ifndef ENABLE_VARARGS
#define ENABLE_VARARGS
#endif /* end of ENABLE_VARARGS */
#ifndef EASYINLINE
#define EASYINLINE inline
#endif  /* end of EASYINLINE */
#endif  /* end of __cplusplus >= 201103 */
#endif  /* end of __cplusplus */

/* No inline keyword found */
#ifndef EASYINLINE
#define EASYINLINE
#endif  /* end of EASYINLINE */

/* ######################################### */
/* Macros for DEBUG and VERBOSE output */

/* Is DEBUG code available? */
#ifdef DEBUG
#ifndef dbg
int g_debug;
#define dbg0(fmt)      { if (g_debug != 0) printf("#d_%d:%s: " fmt, __LINE__, __func__); }
#ifdef ENABLE_VARARGS
#define dbg(fmt, ...)  { if (g_debug != 0) printf("#d_%d:%s: " fmt, __LINE__, __func__, __VA_ARGS__); }
#else
/* Oh, a very old compiler version */
#define dbg(fmt, arg1)  { if (g_debug != 0) printf("#d_%d:%s: " fmt, __LINE__, __func__, arg1); }
#endif /* end of ENABLE_VARARGS */
#endif /* end of dbg */
#endif /* end of DEBUG */


/* The debug macros are always available */
#ifndef dbg
#define dbg0(fmt)
#ifdef ENABLE_VARARGS
#define dbg(fmt, ...)
#else
#define dbg()
#endif /* end of ENABLE_VARARGS */
#endif /* end of dbg */


/* The verbose info macros are always available */
#ifndef info
int g_verbose;
#define info0(fmt)      { if (g_verbose != 0) printf("#v_%d:%s: " fmt, __LINE__, __func__); }
#ifdef ENABLE_VARARGS
#define info(fmt, ...)  { if (g_verbose != 0) printf("#v_%d:%s: " fmt, __LINE__, __func__, __VA_ARGS__); }
#else
/* Oh, a very old compiler version */
#define info(fmt, arg1)  { if (g_verbose != 0) printf("#d_%d:%s: " fmt, __LINE__, __func__, arg1); }
#endif /* end of ENABLE_VARARGS */
#endif /* end of info */


/* ############################## */

#ifndef DIRECTORY_SEPARATOR_CHAR

#if defined __unix__  || defined __unix  || defined __UNIX__
#define DIRECTORY_SEPARATOR_CHAR '/'
#else
/* _Win32, _Win64, WIN16, OS/2, DOS or something else */
#define DIRECTORY_SEPARATOR_CHAR '\\'
#endif

#endif

/* ########################## */
/* the usual stringify macros */
#ifndef str2raw
#define str2raw(x) #x
#define str2txt(x) str2raw(x)
#endif


/* ################################# */
#endif /* end of SETTINGS_H_INCLUDED */

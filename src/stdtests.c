/* ############# */
/* ToDo: License */


#ifdef __cplusplus
extern "C" {
#endif


/* use a singe header for the project settings */
/* "settings.h" also includes "config.h" */
#include "settings.h"

/* ################################################################ */
/* workaround: cross compiling for WIN32/WIN64 can produce failures */
/* (header found, but no implementation available) */
/* use our own implementation of "getopt_long" instead */
#ifndef _WIN32
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#elif __has_include(<unistd.h>)
#include <unistd.h>
#endif /* end of HAVE_UNISTD_H */
#endif /* end of _WIN32 */


/* ###################### */
/* Now the other includes */
#include <stdio.h>

/* ################################ */
/* Detect Compiler, OS, and more... */
#include "compiler.h"


/* #################################### */
/* this is currently a system info tool */

int main(void)
{

/* print the detected compiler */
#ifdef USE_COMPILER_ID
#ifdef USE_COMPILER_VAL_FMT
    printf(FMT_DEFAULT_ID ": " USE_COMPILER_VAL_FMT "-> %s", USE_COMPILER_ID, USE_COMPILER_VALUE, USE_COMPILER_NAME);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s", USE_COMPILER_ID, USE_COMPILER_VALUE, USE_COMPILER_NAME);
#endif

#ifdef USE_COMPILER_VER_FMT
    printf(" (");
#ifdef USE_COMPILER_PL
    printf(USE_COMPILER_VER_FMT, USE_COMPILER_VER, USE_COMPILER_REV, USE_COMPILER_PL);
#else
    printf(USE_COMPILER_VER_FMT, USE_COMPILER_VER, USE_COMPILER_REV);
#endif
    printf(")");
#endif
    printf("\n");
#else
    printf("USE_COMPILER_ID not set for your compiler\n");
#endif

/* Some compiler have a version info */
#ifdef USE_VERSION_ID
    printf(FMT_DEFAULT_ID "= " USE_VERSION_FMT"\n", USE_VERSION_ID, USE_VERSION_VALUE);
#endif

/* Has the compiler a history or claims to be another compiler? */
#ifdef USE_COMPILER_ID2
#ifdef USE_COMPILER_VAL_FMT2
    printf(FMT_DEFAULT_ID ": " USE_COMPILER_VAL_FMT2 "-> %s", USE_COMPILER_ID2, USE_COMPILER_VALUE2, USE_COMPILER_NAME2);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s", USE_COMPILER_ID2, USE_COMPILER_VALUE2, USE_COMPILER_NAME2);
#endif

#ifdef USE_COMPILER_VER_FMT2
    printf(" (");
#ifdef USE_COMPILER_PL2
    printf(USE_COMPILER_VER_FMT2, USE_COMPILER_VER2, USE_COMPILER_REV2, USE_COMPILER_PL2);
#else
    printf(USE_COMPILER_VER_FMT2, USE_COMPILER_VER2, USE_COMPILER_REV2);
#endif
    printf(")");
#endif
    printf("\n");

#ifdef USE_VERSION_ID2
    printf(FMT_DEFAULT_ID "= " USE_VERSION_FMT2"\n", USE_VERSION_ID2, USE_VERSION_VALUE2);
#endif


/* Has the compiler a long history or claims to be a third compiler? */
#ifdef USE_COMPILER_ID3
#ifdef USE_COMPILER_VAL_FMT3
    printf(FMT_DEFAULT_ID ": " USE_COMPILER_VAL_FMT3 "-> %s", USE_COMPILER_ID3, USE_COMPILER_VALUE3, USE_COMPILER_NAME3);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s", USE_COMPILER_ID3, USE_COMPILER_VALUE3, USE_COMPILER_NAME3);
#endif

#ifdef USE_COMPILER_VER_FMT3
    printf(" (");
#ifdef USE_COMPILER_PL3
    printf(USE_COMPILER_VER_FMT3, USE_COMPILER_VER3, USE_COMPILER_REV3, USE_COMPILER_PL3);
#else
    printf(USE_COMPILER_VER_FMT3, USE_COMPILER_VER3, USE_COMPILER_REV3);
#endif
    printf(")");
#endif
    printf("\n");

#ifdef USE_VERSION_ID3
    printf(FMT_DEFAULT_ID "= " USE_VERSION_FMT3"\n", USE_VERSION_ID3, USE_VERSION_VALUE3);
#endif
#endif  /* USE_COMPILER_ID3 */
#endif  /* USE_COMPILER_ID2 */



/* ########################### */
/* print the detected standard */
#ifdef USE_STD_ID
#ifdef USE_STD_NAME
#ifdef __SMALLER_C__
/* __SMALLER_C__ in tiny or small DOS mode does not support long. printf with "%ld" fails also */
/* using "-Dlong=int" with this workaround let tiny+small DOS programs run */
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "-> %s\n", USE_STD_ID, USE_STD_VALUE, USE_STD_NAME);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s\n", USE_STD_ID, USE_STD_VALUE, USE_STD_NAME);
#endif
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID, USE_STD_VALUE);
#endif

#ifdef USE_STD_ID2
#ifdef USE_STD_NAME2
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s\n", USE_STD_ID2, USE_STD_VALUE2, USE_STD_NAME2);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID2, USE_STD_VALUE2);
#endif

#ifdef USE_STD_ID3
#ifdef USE_STD_NAME3
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "-> %s\n", USE_STD_ID3, USE_STD_VALUE3, USE_STD_NAME3);
#else
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID3, USE_STD_VALUE3);
#endif
#ifdef USE_STD_ID4
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID4, USE_STD_VALUE4);
#ifdef USE_STD_ID5
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID5, USE_STD_VALUE5);
#ifdef USE_STD_ID6
    printf(FMT_DEFAULT_ID "= " FMT_DEFAULT_VALUE "\n", USE_STD_ID6, USE_STD_VALUE6);
#endif
#endif  /* USE_STD_ID5 */
#endif  /* USE_STD_ID4 */
#endif  /* USE_STD_ID3 */
#endif  /* USE_STD_ID2 */
#else
    printf("USE_STD_ID not set. Is this really a K&R C Compiler?\n");
#endif  /* USE_STD_ID */


/* ##################### */
/* print the detected os */
/* primary os groups: unix / bsd OS */
#ifdef USE_OSGROUP_ID
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID, USE_OSGROUP_VALUE);
#ifdef USE_OSGROUP_ID2
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID2, USE_OSGROUP_VALUE2);
#ifdef USE_OSGROUP_ID3
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID3, USE_OSGROUP_VALUE3);
#ifdef USE_OSGROUP_ID4
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID4, USE_OSGROUP_VALUE4);
#ifdef USE_OSGROUP_ID5
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID5, USE_OSGROUP_VALUE5);
#ifdef USE_OSGROUP_ID6
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID6, USE_OSGROUP_VALUE6);
#ifdef USE_OSGROUP_ID7
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OSGROUP_ID7, USE_OSGROUP_VALUE7);
#endif
#endif  /* USE_OSGROUP_ID6 */
#endif  /* USE_OSGROUP_ID5 */
#endif  /* USE_OSGROUP_ID4 */
#endif  /* USE_OSGROUP_ID3 */
#endif  /* USE_OSGROUP_ID2 */
#endif  /* USE_OSGROUP_ID */


/* unix / bsd subclass, dos/windows or anything else */
#ifdef USE_OS_ID
#ifdef USE_OS_VAL_FMT
    printf(FMT_DEFAULT_ID "= " USE_OS_VAL_FMT, USE_OS_ID, USE_OS_VALUE);
#else
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE, USE_OS_ID, USE_OS_VALUE);
#endif

#ifdef USE_OS_VER_FMT
    printf(" (");
#ifdef USE_OS_PL
    printf(USE_OS_VER_FMT, USE_OS_VER, USE_OS_REV, USE_OS_PL);
#else
    printf(USE_OS_VER_FMT, USE_OS_VER, USE_OS_REV);
#endif
    printf(")");
#endif
    printf("\n");

#ifdef USE_OS_ID2
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OS_ID2, USE_OS_VALUE2);
#ifdef USE_OS_ID3
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OS_ID3, USE_OS_VALUE3);
#ifdef USE_OS_ID4
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OS_ID4, USE_OS_VALUE4);
#ifdef USE_OS_ID5
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OS_ID5, USE_OS_VALUE5);
#ifdef USE_OS_ID6
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_OS_ID6, USE_OS_VALUE6);
#endif
#endif  /* USE_OS_ID5 */
#endif  /* USE_OS_ID4 */
#endif  /* USE_OS_ID3 */
#endif  /* USE_OS_ID2 */
#else
    printf("USE_OS_ID not set for your OS.\n");
#endif  /* USE_OS_ID */


/* ############################### */
/* print the detected architecture */

#ifdef USE_ARCH_ID
#ifdef USE_ARCH_FMT
    printf(FMT_DEFAULT_ID "= " USE_ARCH_FMT "\n", USE_ARCH_ID, USE_ARCH_VALUE);
#else
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID, USE_ARCH_VALUE);
#endif
#ifdef USE_ARCH_ID2
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID2, USE_ARCH_VALUE2);
#ifdef USE_ARCH_ID3
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID3, USE_ARCH_VALUE3);
#ifdef USE_ARCH_ID4
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID4, USE_ARCH_VALUE4);
#ifdef USE_ARCH_ID5
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID5, USE_ARCH_VALUE5);
#ifdef USE_ARCH_ID6
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID6, USE_ARCH_VALUE6);
#ifdef USE_ARCH_ID7
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_ARCH_ID7, USE_ARCH_VALUE7);
#endif
#endif  /* USE_ARCH_ID6 */
#endif  /* USE_ARCH_ID5 */
#endif  /* USE_ARCH_ID4 */
#endif  /* USE_ARCH_ID3 */
#endif  /* USE_ARCH_ID2 */
#else
    printf("USE_ARCH_ID not set for your Processor architecture.\n");
#endif  /* USE_ARCH_ID1 */


/* ############################# */
/* print the detected data model */

#ifdef USE_DATAMODEL_ID
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_DATAMODEL_ID, USE_DATAMODEL_VALUE);
#ifdef USE_DATAMODEL_ID2
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_DATAMODEL_ID2, USE_DATAMODEL_VALUE2);
#endif
#endif


/* ############################### */
/* print the detected memory model */

#ifdef USE_MCMODEL_ID
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_MCMODEL_ID, USE_MCMODEL_VALUE);
#ifdef USE_MCMODEL_ID2
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "\n", USE_MCMODEL_ID2, USE_MCMODEL_VALUE2);
#endif
#endif


/* ##################################### */
/* size / width or type of various types */
/* character types */
#ifdef __CHAR16_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__CHAR16_TYPE__", str2txt(__CHAR16_TYPE__));
#endif
#ifdef __CHAR32_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__CHAR32_TYPE__", str2txt(__CHAR32_TYPE__));
#endif

#ifdef __WCHAR_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__WCHAR_TYPE__", str2txt(__WCHAR_TYPE__));
#else
#ifdef __WINT_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__WINT_TYPE__", str2txt(__WINT_TYPE__));
#endif
#endif

#ifdef __SIZEOF_WCHAR_T__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_WCHAR_T__", __SIZEOF_WCHAR_T__);
#else
#ifdef __WCHAR_WIDTH__
    printf(FMT_DEFAULT_ID "= %d\n", "__WCHAR_WIDTH__", __WCHAR_WIDTH__);
#else
#ifdef _WCHAR_T_DEFINED
    printf(FMT_DEFAULT_ID  "= %u\n", "sizeof(wchar_t)", (unsigned int) sizeof(wchar_t));
#endif  /* _WCHAR_T_DEFINED */
#endif  /* __WCHAR_WIDTH__ */
#endif  /* __SIZEOF_WCHAR_T__ */



/* ############## */
/* int types: int */
#ifdef __SIZEOF_INT__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_INT__", (__SIZEOF_INT__) );
#else
#ifdef __INT_WIDTH__
    printf(FMT_DEFAULT_ID "= %d\n", "__INT_WIDTH__", __INT_WIDTH__);
#else
    printf(FMT_DEFAULT_ID "= %u\n", "sizeof(int)", (unsigned int) sizeof(int));
#endif  /* __INT_WIDTH__ */
#endif  /* __SIZEOF_INT__ */



/* int types: long */
#ifdef __SIZEOF_LONG__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_LONG__", __SIZEOF_LONG__);
#else
#ifdef __LONG_WIDTH__
    printf(FMT_DEFAULT_ID "= %d\n", "__LONG_WIDTH__", __LONG_WIDTH__);
#else
    printf(FMT_DEFAULT_ID "= %u\n", "sizeof(long)", (unsigned int) sizeof(long));
#endif  /* __LONG_WIDTH__ */
#endif  /* __SIZEOF_LONG__ */


/* int types: long long */
#ifdef __SIZEOF_LONG_LONG__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_LONG_LONG__", __SIZEOF_LONG_LONG__);
#else
#ifdef __SIZEOF_LONGLONG__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_LONGLONG__", __SIZEOF_LONGLONG__);
#else
#ifdef __LLONG_WIDTH__
    printf(FMT_DEFAULT_ID "= %d\n", "__LLONG_WIDTH__", __LLONG_WIDTH__);
#else
#ifdef __WATCOM_INT64__
    printf(FMT_DEFAULT_ID "= %u\n", "sizeof(__int64)", (unsigned int) sizeof(__int64));
#endif
#endif  /* __LLONG_WIDTH__ */
#endif  /* __SIZEOF_LONGLONG__ */
#endif  /* __SIZEOF_LONG_LONG__ */

/* 128 bits INT is a compiler extension */
#ifdef __SIZEOF_INT128__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_INT128__", __SIZEOF_INT128__);
#endif



/* #################### */
/* floating point types */
#ifdef __SIZEOF_FLOAT__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_FLOAT__", __SIZEOF_FLOAT__);
#endif
#ifdef __SIZEOF_DOUBLE__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_DOUBLE__", __SIZEOF_DOUBLE__);
#endif
#ifdef __SIZEOF_LONG_DOUBLE__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_LONG_DOUBLE__", __SIZEOF_LONG_DOUBLE__);
#endif

#ifdef __SIZEOF_FLOAT64__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_FLOAT64__", __SIZEOF_FLOAT64__);
#endif
#ifdef __SIZEOF_FLOAT80__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_FLOAT80__", __SIZEOF_FLOAT80__);
#endif
#ifdef __SIZEOF_FLOAT128__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZEOF_FLOAT128__", __SIZEOF_FLOAT128__);
#endif


/* long double support is implementation defined */
#ifdef __LONG_DOUBLE_64__
    printf(FMT_DEFAULT_ID "= %d\n", "__LONG_DOUBLE_64__", __LONG_DOUBLE_64__);
#endif
#ifdef __LONG_DOUBLE_80__
    printf(FMT_DEFAULT_ID "= %d\n", "__LONG_DOUBLE_80__", __LONG_DOUBLE_80__);
#endif
#ifdef __LONG_DOUBLE_128__
    printf(FMT_DEFAULT_ID "= %d\n", "__LONG_DOUBLE_128__", __LONG_DOUBLE_128__);
#endif


/* ################################# */
/* types used for the implementation */
#ifdef __INT8_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__INT8_TYPE__", str2txt(__INT8_TYPE__) );
#endif
#ifdef __INT16_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__INT16_TYPE__", str2txt(__INT16_TYPE__) );
#endif
#ifdef __INT32_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__INT32_TYPE__", str2txt(__INT32_TYPE__) );
#endif
#ifdef __LONG_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__LONG_TYPE__", str2txt(__LONG_TYPE__));
#endif
#ifdef __INT64_TYPE__
    printf(FMT_DEFAULT_ID  ": %s\n", "__INT64_TYPE__", str2txt(__INT64_TYPE__) );
#endif
#ifdef __INT128_TYPE__
    printf(FMT_DEFAULT_ID ": %s\n", "__INT128_TYPE__", str2txt(__INT128_TYPE__) );
#endif


/* ############# */
/* pointer types */

#ifdef __PTRDIFF_TYPE__
    printf(FMT_DEFAULT_ID ": %s\n", "__PTRDIFF_TYPE__", str2txt(__PTRDIFF_TYPE__) );
#endif
#ifdef __INTPTR_TYPE__
    printf(FMT_DEFAULT_ID ": %s\n", "__INTPTR_TYPE__", str2txt(__INTPTR_TYPE__) );
#endif

#ifdef __SIZEOF_POINTER__
    printf(FMT_DEFAULT_ID "= %u\n", "__SIZEOF_POINTER__", __SIZEOF_POINTER__);
#else
#ifdef __POINTER_WIDTH__
    printf(FMT_DEFAULT_ID "= %u\n", "__POINTER_WIDTH__", __POINTER_WIDTH__);
#else
    printf(FMT_DEFAULT_ID "= %u\n", "sizeof(char *)", (unsigned int) sizeof(char *));
#endif  /* __POINTER_WIDTH__ */
#endif  /* __SIZEOF_POINTER__ */


#ifdef __SIZEOF_PTRDIFF_T__
    printf(FMT_DEFAULT_ID "= %u\n", "__SIZEOF_PTRDIFF_T__", __SIZEOF_PTRDIFF_T__);
#else
#ifdef __PTRDIFF_WIDTH__
    printf(FMT_DEFAULT_ID "= %u\n", "__PTRDIFF_WIDTH__", __PTRDIFF_WIDTH__);
#endif  /* __PTRDIFF_WIDTH__ */
#endif  /* __SIZEOF_PTRDIFF_T__ */


/* ########### */
/* size_t type */
#ifdef __SIZEOF_SIZE_T__
    printf(FMT_DEFAULT_ID "= %u\n", "__SIZEOF_SIZE_T__", __SIZEOF_SIZE_T__);
#else
#ifdef __SIZE_WIDTH__
    printf(FMT_DEFAULT_ID "= %d\n", "__SIZE_WIDTH__", __SIZE_WIDTH__);
#endif  /* __SIZE_WIDTH__ */
#endif  /* __SIZEOF_SIZE_T__ */

#ifdef __SIZE_TYPE__
    printf(FMT_DEFAULT_ID ": %s\n", "__SIZE_TYPE__", str2txt(__SIZE_TYPE__));
#endif


/* max int bits (common used on windows) */
#ifdef _INTEGRAL_MAX_BITS
    printf(FMT_DEFAULT_ID "= %d\n", "_INTEGRAL_MAX_BITS", (_INTEGRAL_MAX_BITS) );
#endif


#ifdef __BITINT_MAXWIDTH__
    printf(FMT_DEFAULT_ID "= %d / 0x%x\n", "__BITINT_MAXWIDTH__", __BITINT_MAXWIDTH__, __BITINT_MAXWIDTH__);
#endif


/* #################### */
/* c23 style byte order */
/* needs stdbit.h  */
#ifdef __STDC_ENDIAN_NATIVE__
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "-> %s\n", "__STDC_ENDIAN_NATIVE__", __STDC_ENDIAN_NATIVE__,
            (__STDC_ENDIAN_NATIVE__ == __STDC_ENDIAN_LITTLE__) ?
            "__STDC_ENDIAN_LITTLE__" : (__STDC_ENDIAN_NATIVE__ == __STDC_ENDIAN_BIG__) ?
            "__STDC_ENDIAN_BIG__" : "unknown" );
#else
#ifdef __STDC_ENDIAN_LITTLE__
    printf(FMT_DEFAULT_ID "= %d\n", "__STDC_ENDIAN_LITTLE__", __STDC_ENDIAN_LITTLE__);
#endif
#ifdef __STDC_ENDIAN_BIG__
    printf(FMT_DEFAULT_ID "= %d\n", "__STDC_ENDIAN_BIG__", __STDC_ENDIAN_BIG__);
#endif
#endif


/* #################### */
/* old style byte order */
#ifdef __BYTE_ORDER__
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "-> %s\n", "__BYTE_ORDER__", __BYTE_ORDER__,
            (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ?
            "__ORDER_LITTLE_ENDIAN__" : (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) ?
            "__ORDER_BIG_ENDIAN__" : "unknown" );
#else
#ifdef __ORDER_LITTLE_ENDIAN__
    printf(FMT_DEFAULT_ID "= %d\n", "__ORDER_LITTLE_ENDIAN__", __ORDER_LITTLE_ENDIAN__);
#else
#ifdef __LITTLE_ENDIAN__
    printf(FMT_DEFAULT_ID "= %d\n", "__LITTLE_ENDIAN__", __LITTLE_ENDIAN__);
#else
#ifdef __LITTLE_ENDIAN
    printf(FMT_DEFAULT_ID "= %d\n", "__LITTLE_ENDIAN", __LITTLE_ENDIAN);
#else
#ifdef _LITTLE_ENDIAN
    printf(FMT_DEFAULT_ID "= %d\n", "_LITTLE_ENDIAN", _LITTLE_ENDIAN);
#endif
#endif
#endif
#endif  /* end of __ORDER_LITTLE_ENDIAN__ */
#ifdef __ORDER_BIG_ENDIAN__
    printf(FMT_DEFAULT_ID "= %d\n", "__ORDER_BIG_ENDIAN__", __ORDER_BIG_ENDIAN__);
#else
#ifdef __BIG_ENDIAN__
    printf(FMT_DEFAULT_ID "= %d\n", "__BIG_ENDIAN__", __BIG_ENDIAN__);
#else
#ifdef __BIG_ENDIAN
    printf(FMT_DEFAULT_ID "= %d\n", "__BIG_ENDIAN", __BIG_ENDIAN);
#else
#ifdef _BIG_ENDIAN
    printf(FMT_DEFAULT_ID "= %d\n", "_BIG_ENDIAN", _BIG_ENDIAN);
#endif
#endif
#endif
#endif  /* end of __ORDER_BIG_ENDIAN__ */
#endif  /* end of __BYTE_ORDER__ */

#ifdef __FLOAT_WORD_ORDER__
    printf(FMT_DEFAULT_ID "= " FMT_INT_VALUE "-> %s\n", "__FLOAT_WORD_ORDER__", __FLOAT_WORD_ORDER__,
            (__FLOAT_WORD_ORDER__ == __ORDER_LITTLE_ENDIAN__) ?
            "__ORDER_LITTLE_ENDIAN__" :  (__FLOAT_WORD_ORDER__ == __ORDER_BIG_ENDIAN__) ?
            "__ORDER_BIG_ENDIAN__" : "unknown" );
#endif


#ifdef __BIGGEST_ALIGNMENT__
    printf(FMT_DEFAULT_ID "= %d\n", "__BIGGEST_ALIGNMENT__", __BIGGEST_ALIGNMENT__);
#endif


/* ################################## */
/* is Multi-Threading support active? */

/* solaris, osf*, pthread with gcc, clang, tcc */
#ifdef _REENTRANT
    /* printing the value of _REENTRANT failed on one system, so "is defined" is better */
    printf(FMT_DEFAULT_ID "is defined\n", "_REENTRANT" );
#endif

/* FreeBSD, aix */
#ifdef _THREAD_SAFE
    printf(FMT_DEFAULT_ID "= %d\n", "_THREAD_SAFE", _THREAD_SAFE);
#endif
#ifdef THREAD_SAFE
    printf(FMT_DEFAULT_ID "= %d\n", "THREAD_SAFE", THREAD_SAFE);
#endif
/* pcc */
#ifdef _PTHREADS
    printf(FMT_DEFAULT_ID "= %d\n", "_PTHREADS", _PTHREADS);
#endif

/* Some Windows based Compiler */
#ifdef __MT__
    printf(FMT_DEFAULT_ID "= %d\n", "__MT__", __MT__);
#endif
/* Other Windows based compiler. Example: OpenWatcom */
#ifdef _MT
    printf(FMT_DEFAULT_ID "= %d\n", "_MT", _MT + 0);
#endif

/* ########################### */
/* includes for multithreading */
#ifdef HAVE_PTHREAD_H
    printf(FMT_DEFAULT_ID "= %d\n", "HAVE_PTHREAD_H", HAVE_PTHREAD_H);
#endif

#ifdef HAVE_THREADS_H
    printf(FMT_DEFAULT_ID "= %d\n", "HAVE_THREADS_H", HAVE_THREADS_H);
#endif
#ifdef HAVE_C11THREADS_H
    printf(FMT_DEFAULT_ID "= %d\n", "HAVE_C11THREADS_H", HAVE_C11THREADS_H);
#ifdef HAVE_C11THREADS_WIN32_C
    printf(FMT_DEFAULT_ID "= %d\n", "HAVE_C11THREADS_WN32_C", HAVE_C11THREADS_WIN32_C);
#endif
#endif


/* ############# */
/* optimizations */
#ifdef __OPTIMIZE__
    printf(FMT_DEFAULT_ID "= %d\n", "__OPTIMIZE__", __OPTIMIZE__);
#endif
#ifdef __OPTIMIZE_SIZE__
    printf(FMT_DEFAULT_ID "= %d\n", "__OPTIMIZE_SIZE__", __OPTIMIZE_SIZE__);
#else
#ifdef _OPTIMIZE_FOR_SPACE
    printf(FMT_DEFAULT_ID "= %d\n", "_OPTIMIZE_FOR_SPACE", _OPTIMIZE_FOR_SPACE);
#endif
#endif


/* ############################################## */
/* SIMD related defines are Architecture specific */

/* SIMD on x86 / x86_64 */
#ifdef __MMX__
    printf(FMT_DEFAULT_ID "= %d\n", "__MMX__", (__MMX__));
#endif
#ifdef __SSE__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSE__", (__SSE__));
#endif
#ifdef __SSE2__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSE2__", (__SSE2__));
#endif
#ifdef __SSE3__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSE3__", (__SSE3__));
#endif
#ifdef __SSSE3__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSSE3__", (__SSSE3__));
#endif
#ifdef __SSE4_1__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSE4_1__", (__SSE4_1__));
#endif
#ifdef __SSE4_2__
    printf(FMT_DEFAULT_ID "= %d\n", "__SSE4_2__", (__SSE4_2__));
#endif

#ifdef __AVX__
    printf(FMT_DEFAULT_ID "= %d\n", "__AVX__", (__AVX__));
#endif
#ifdef __AVX2__
    printf(FMT_DEFAULT_ID "= %d\n", "__AVX2__", (__AVX2__));
#endif
#ifdef __AVX512F__
    printf(FMT_DEFAULT_ID "= %d\n", "__AVX512F__", (__AVX512F__));
#endif

/* SIMD on ARM / aarch64 */
#ifdef __ARM_NEON__
    printf(FMT_DEFAULT_ID "= %d\n", "__ARM_NEON__", __ARM_NEON__);
#else
#ifdef __ARM_NEON
    printf(FMT_DEFAULT_ID "= %d\n", "__ARM_NEON", __ARM_NEON);
#endif
#endif

/* SIMD on powerpc */
#ifdef __ALTIVEC__
    printf(FMT_DEFAULT_ID "= %d\n", "__ALTIVEC__", (__ALTIVEC__));
#endif


/* ######################### */
/* some things from limits.h */
#ifdef MAX_PATH
    printf(FMT_DEFAULT_ID "= %d\n", "MAX_PATH", (MAX_PATH));
#endif

#ifdef _MAX_PATH
    printf(FMT_DEFAULT_ID "= %d\n", "_MAX_PATH", (_MAX_PATH));
#endif

#ifdef PATH_MAX
    printf(FMT_DEFAULT_ID "= %d\n", "PATH_MAX", (PATH_MAX));
#endif

#ifdef _POSIX_PATH_MAX
    printf(FMT_DEFAULT_ID "= %d\n", "_POSIX_PATH_MAX", (_POSIX_PATH_MAX));
#endif

#ifdef _XOPEN_PATH_MAX
    printf(FMT_DEFAULT_ID "= %d\n", "_XOPEN_PATH_MAX", (_XOPEN_PATH_MAX));
#endif

/* ################## */
/* DEBUG mode active? */
#ifdef NDEBUG
    printf(FMT_DEFAULT_ID "= %d\n", "NDEBUG", NDEBUG+0);
#elif defined DEBUG
    printf(FMT_DEFAULT_ID "= %d\n", "DEBUG", DEBUG+0);
#endif

    return 0;
}

#ifdef __cplusplus
}
#endif


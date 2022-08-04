/* ############# */
/* ToDo: License */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>

/* ############################## */
/* 
 * compiler detection:
 * compiler, compiler version
 * Standard:
 *  C:   __STDC_VERSION__
 *  C++: __cplusplus
 */

#define fmt_id "%-18s = "
#define fmt_u  "%-7u"


/* OpenWatcom C / C++ or Watcom C/C++ */
#ifdef __WATCOMC__
#define USE_COMPILER_ID
const char compiler_id[] = "__WATCOMC__";
const int  compiler_value = __WATCOMC__;

#if  __WATCOMC__ > 1100
const char compiler_name[] = "OpenWatcom";
const int  compiler_ver = (__WATCOMC__ - 1100) / 100;
const int  compiler_rev = (__WATCOMC__ - 1100) % 100;
#else
const char compiler_name[] = "Watcom";
const int  compiler_ver = __WATCOMC__ / 100;
const int  compiler_rev = __WATCOMC__ % 100;
#endif
const char compiler_fmt[] = "%d.%d";
#endif


/* TinyC Compiler */
#ifdef __TINYC__
#define USE_COMPILER_ID
const char compiler_id[] = "__TINYC__";
const int  compiler_value = __TINYC__;

const char compiler_name[] ="Tiny C";
const int  compiler_ver = __TINYC__ / 10000;
const int  compiler_rev = (__TINYC__ % 10000) / 100;
const int  compiler_pl = __TINYC__ % 100;
const char compiler_fmt[] = "%d.%d.%d";
#define USE_COMPILER_PL
#endif


/* Check for __clang__ at the end, but before __GNUC__ */
/* some compiler are based on clang/llvm */
/* examples: zig, some versions of BCC or MSVC */
#ifdef __clang__
#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID
const char compiler_id[] = "__clang__";
const int  compiler_value = __clang__;

const char compiler_name[] ="clang";
const int  compiler_ver = __clang_major__;
const int  compiler_rev = __clang_minor__;
const int  compiler_pl = __clang_patchlevel__;
const char compiler_fmt[] = "%d.%d.%d";
#define USE_COMPILER_PL
#endif
#endif


/* Check for __GNUC__ at the end */
/* some compiler are based on gcc */
/* examples: EDG */ 
/* or claim to be compatible with gcc */
/* examples: clang / llvm */
#ifdef __GNUC__
#ifndef USE_COMPILER_ID
#define USE_COMPILER_ID
const char compiler_id[] = "__GNUC__";
const int  compiler_value = __GNUC__;

const char compiler_name[] ="gcc";
const int  compiler_ver = __GNUC__;
const int  compiler_rev = __GNUC_MINOR__;
const int  compiler_pl = __GNUC_PATCHLEVEL__;
const char compiler_fmt[] = "%d.%d.%d";
#define USE_COMPILER_PL
#endif
#endif


/* ############################## */
/*
 * standard detection:
 * C:   __STDC_VERSION__
 * C++: __cplusplus
 */

#ifdef __cplusplus
#define USE_STD_ID
const char std_id[] = "__cplusplus";
const int  std_value = __cplusplus;

const char *std_name = \
        (__cplusplus >= 202200) ? "C++23 / C++2y" :
        (__cplusplus >= 202002) ? "C++20" :
        (__cplusplus >= 201703) ? "C++17" :
        (__cplusplus >= 201402) ? "C++14" :
        (__cplusplus >= 201103) ? "C++11" :
        (__cplusplus >= 200300) ? "C++03" :
        (__cplusplus >= 199711) ? "C++98" : 
        "C++";
#endif


#ifdef __STDC_VERSION__
#define USE_STD_ID
const char std_id[] = "__STDC_VERSION__";
const int  std_value = __STDC_VERSION__;

const char *std_name = \
        (__STDC_VERSION__ >= 202000) ? "C2x / C23" :
        (__STDC_VERSION__ >= 201710) ? "C17 / C18" :
        (__STDC_VERSION__ >= 201112) ? "C11" :
        (__STDC_VERSION__ >= 199901) ? "C99" :
        (__STDC_VERSION__ >= 199409) ? "C95" : 
        "C89 / C90 / ANSI C";
#endif


#ifdef __STDC__
#ifndef USE_STD_ID
#define USE_STD_ID
/* Onlx __STDC__ without __STDC_VERSION__: C89: ANSI-C or C90: ISO-C */
const char std_id[] = "__STDC__";
const int  std_value = __STDC__;
const char std_name[] = "C89 / C90 / ANSI C";
#else
#define USE_STD_ID2
const char std2_id[] = "__STDC__";
const int  std2_value = __STDC__;
#endif
#endif


/* ############################## */

int main(void)
{

#ifdef USE_COMPILER_ID
    printf(fmt_id, compiler_id);
    printf(fmt_u "-> %s (", compiler_value, compiler_name);
#ifdef USE_COMPILER_PL
    printf(compiler_fmt, compiler_ver, compiler_rev, compiler_pl);
#else
    printf(compiler_fmt, compiler_ver, compiler_rev);
#endif
    printf(")\n");
#else
#warning "USE_COMPILER_ID not set for your compiler"
#endif


#ifdef USE_STD_ID
    printf(fmt_id fmt_u "-> %s\n", std_id, std_value, std_name);
#ifdef USE_STD_ID2
    printf(fmt_id fmt_u "\n", std2_id, std2_value);
#endif
#else
#warning "USE_STD_ID not set. Is this really a K&R C Compiler?"
#endif

    printf("\nAll Done\n");
    return 0;
}


/* ############# */
/* ToDo: License */

/*
 * Create a big bunch of tests files for testing a
 * C / C++ Compiler and a runtime library
 * Also create glue code for configure.ac and for the generator itself
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ############################## */
/* activate extensions, when available */
#define _ISOC99_SOURCE  1
#define _ISOC11_SOURCE  1
#define _ISOC2X_SOURCE  1
#define _ISOC23_SOURCE  1

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200809L
#endif

/* one, to catch them all */
/* activate GNU extensions, when available */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

/* include the results from configure */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


/* Many functions are missing in Windows since >30 years */
#include "fix_non_posix_systems.h"


/* ############################## */

#define __need_NULL
#include <stddef.h>

/* getenv, ... */
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

/* puts, ... */
#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

/* gnu extended version of basename is in string.h */
#ifdef HAVE_STRING_H
#include <string.h>
#endif

/* posix version of basename is in libgen.h */
#ifdef HAVE_LIBGEN_H
#include <libgen.h>
#endif

/* ############################## */

/* this tools is only used in MAINTAINER_MODE */
#ifndef MAINTAINER_MODE

int main(void)
{
    puts("Only used in MAINTAINER_MODE\n");
    return 0;
}

#else

/* ############################## */
/*
 * global defaults
 */

char *g_appname = NULL;
int g_debug = 0;
int g_verbose = 0;

/* ############################## */
/*
 * activate DEBUG/verbose mode, when the environment variable "DEBUG" is set 
 */
void init_debug_from_env(void)
{
    if (getenv("DEBUG"))
    {
        ++g_debug;
        ++g_verbose;
    }
}

/* ############################## */

int main(int argc, char * argv[])
{

    init_debug_from_env();
    g_appname = basename(argv[0]);

    printf("Hello %s\n", g_appname);

    return 0;
}

#endif

#ifdef __cplusplus
}
#endif

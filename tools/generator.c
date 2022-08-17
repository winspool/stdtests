/* ############# */
/* ToDo: License */

/*
 * Create a big bunch of tests files for testing a
 * C / C++ Compiler and a runtime library
 * Also create glue code for configure.ac and for the generator itself
 */


/* activate GNU extensions, when available */
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif


/* include the results from configure */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


/* ############################## */

#define __need_NULL
#include <stddef.h>

/* getenv, ... */
#include <stdlib.h>

/* puts, ... */
#include <stdio.h>

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

    puts("Hello world\n");

    return 0;
}

#endif


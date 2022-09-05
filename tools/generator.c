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

#ifndef DEBUG
#define DEBUG 0
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

/* we use getopt_long */
#ifdef HAVE_GETOPT_H
#include <getopt.h>
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
int g_debug = DEBUG;
int g_verbose = 0;

char * opt_output = NULL;

/* ############################## */

/* getopt_long public API: saved status between calls and received additional values */
extern char *optarg;    /* argument for the returned option */
extern int   opterr;    /* print errors messages on failure */
extern int   optopt;    /* unknown option character, when returning '?' */
extern int   optind;    /* next entry in argv to scan */

/* ############################## */

static struct option my_long_options[] =
{
    {"help",    no_argument, NULL, 'h'},

    /* directly update a flag. */
    {"verbose", no_argument, &g_verbose, 'v'},
    {"quiet",   no_argument, &g_verbose, 'q'},
    {"debug",   no_argument, &g_debug,   'd'},


    {"output",  required_argument, 0, 'o'},
    {0, 0, 0, 0}
};

static char my_short_options[] = "-ho:v";

static char my_help_fmt[] = "%s [%s]\n" \
    "available options:\n" \
    " -h, --help\t\tShow this help\n" \
    " -o, --output=name\tWrite output to this file\n" \
    " -v, --verbose\t\tBe more verbose\n" \
    "\0";


/* ############################## */
/*
 * activate DEBUG/verbose mode, when the environment variable "DEBUG" is set 
 */
void init_debug_from_env(void)
{
    char *env_debug = getenv("DEBUG");

    if (env_debug)
    {
        if ((*env_debug) && strcmp(env_debug, "0"))
        {
            ++g_debug;
            ++g_verbose;
        }
    }

}

/* ############################## */

int main(int argc, char * argv[])
{

    int c;
    int long_index = 0;


    init_debug_from_env();
    g_appname = basename(argv[0]);

    /* getopt_long: disable error message on unknown option */
    opterr = 0;

    while (1)
    {

        optopt = 0;
        long_index = 0;
        /* getopt_long stores the index of the matching long option in our parameter: &long_index */
        c = getopt_long(argc, argv, my_short_options, my_long_options, &long_index);

        /* Detect the end of the options. */
        if (c == -1)
        {

            if (g_debug)
            {
                printf("%03d_end of getopt_long with status\n", __LINE__);
                printf("%03d_long_index: %d\n", __LINE__, long_index);
                printf("%03d_optarg: %p / %s\n", __LINE__, optarg, optarg);
                printf("%03d_optind: %d\n", __LINE__, optind);
                printf("%03d_opterr: %d\n", __LINE__, opterr);
                printf("%03d_optopt: %d %c\n", __LINE__, optopt, optopt>32 ? optopt: 32);
            }

            break;
        }

        switch (c)
        {
            case 0:
                /* If this option set a flag, do nothing else now. */

                if (my_long_options[optind].flag != NULL)
                {
                    if (g_debug)
                    {

                        printf("%03d_index_%02d: long_index_%d  name: '%s' flag: %p->%d (optarg: %p: %s)\n",
                                __LINE__, optind, long_index, my_long_options[long_index].name,
                                my_long_options[long_index].flag,
                                my_long_options[long_index].flag ? *(my_long_options[long_index].flag) : 0,
                                optarg, optarg);
                    }
                }

                if (g_debug)
                {
                    printf("%03d_index_%02d: long_index_%d  name: '%s' (optarg: %p: %s)\n",
                            __LINE__, optind, long_index, my_long_options[long_index].name, optarg, optarg);
                }
                break;

            case 1:
                if (g_debug)
                {
                    printf("%03d_got: %d\n", __LINE__, c);
                    printf("%03d_long_index: %d\n", __LINE__, long_index);
                    printf("%03d_optarg: %p / %s\n", __LINE__, optarg, optarg);
                    printf("%03d_optind: %d\n", __LINE__, optind);
                    printf("%03d_opterr: %d\n", __LINE__, opterr);
                    printf("%03d_optopt: %d %c\n", __LINE__, optopt, optopt>32 ? optopt: 32);
                }
                printf("%03d: arg_%d: %s / %s \n", __LINE__, optind -1, optarg, argv[optind-1]);
                break;

            case 'h':
                printf(my_help_fmt, g_appname, my_short_options);
                exit(EXIT_FAILURE);

            case 'o':
                opt_output = optarg;
                if (g_debug)
                {
                    printf("%03d_index_%02d: long_index_%d  option '%c' with argument: %s\n",
                            __LINE__, optind, long_index, c, optarg);
                }
                break;

            case 'v':
                ++g_verbose;
                if (g_debug)
                {
                    printf("%03d_index_%02d: long_index_%d: -v or --verbose  (opt_verbose: %d)\n",
                            __LINE__, optind, long_index, g_verbose);
                }
                break;

            case '?':
                /* getopt_long can also print an error message and abort the program. See: opterr */
                printf("%03d_index_%02d: long_index_%d: got '?': bad option: '%c' %s\n",
                        __LINE__, optind, long_index, optopt >32 ? optopt : 32, argv[optind]);

                printf(my_help_fmt, g_appname, my_short_options);
                exit(EXIT_FAILURE);

            default:
                printf("%03d (optind: %d, long_index: %d). Program failure: No code for option %d %c (caller: %s)\n",
                        __LINE__, optind, long_index, c, c >32 ? c: 32, argv[optind]);
                exit(EXIT_FAILURE);
        }


    }

    printf("Hello %s\n", g_appname);

    while ((optind < argc) && argv[optind])
    {
        printf("%03d: arg_%d: %s\n", __LINE__, optind, argv[optind]);
        ++optind;
    }

    return 0;
}

#endif

#ifdef __cplusplus
}
#endif


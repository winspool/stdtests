/* ############# */
/* ToDo: License */

/*
 * Create a big bunch of tests files for testing a
 * C / C++ Compiler and a runtime library
 * Also create glue code for configure.ac and for the gen_test tool itself
 */
/* this tools is only used in MAINTAINER_MODE */

#ifdef __cplusplus
extern "C" {
#endif


/* ############################################ */
/* use a single header for the project settings */
/* "settings.h" also includes "config.h" */
#include "settings.h"


/* ###################### */
/* Includes for threading */

#ifdef ENABLE_THREADS

#ifdef HAVE_PTHREADS_H
#include <pthreads.h>
#endif

#ifdef HAVE_THREADS_H
#include <threads.h>
#else
#ifdef HAVE_C11THREADS_H
#include "c11threads.h"
#endif
#endif
#endif /* end of ENABLE_THREADS */


/* ############################## */

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

#ifdef HAVE_ERRNO_H
#include <errno.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif


/* ##################################################### */
/* Many functions are missing in Windows since >30 years */
#include "fix_non_posix_systems.h"


/* ################################ */
/* getopt / getopt_long public API: */
/* save status between calls, return values to the caller */
extern char *optarg;    /* argument for the returned option */
extern int   opterr;    /* print errors messages on failure */
extern int   optopt;    /* this option character is unknown (when returning '?') */
extern int   optind;    /* first entry in argv to scan */

/* used by FreeBSD, musl and probably other implementations */
extern int   optreset;

/* ############################## */

/* static linking to glibc (atexit) can fail without that */
#ifdef __PCC__
void * __dso_handle = NULL;
#endif


/* ############################## */
/*
 * global defaults
 */

char *g_appname = NULL;
char *default_path = NULL;
char *opt_output = NULL;
char *opt_path = NULL;
int opt_jobs = 0;
int opt_raw = 0;


/* ################################### */
/* static string to show, what we have */
#ifdef DEBUG
static char status_debug[] = "DEBUG";
#endif

#ifdef NDEBUG
static char status_ndebug[] = "NDEBUG";
#endif


#ifdef ENABLE_THREADS
static char status_enable_threads[] = "ENABLE";
#endif

#ifdef DISABLE_THREADS
static char status_disable_threads[] = "DISABLE";
#endif


/* ############################## */

/* getopt_long public API: saved status between calls and output of additional values */
extern char *optarg;    /* argument for the returned option */
extern int   opterr;    /* print errors messages on failure */
extern int   optopt;    /* unknown option character, when returning '?' */
extern int   optind;    /* next entry in argv to scan */

/* ############################## */

static struct option my_long_options[] =
{
    {"help",    no_argument, NULL, 'h'},

    /* directly update a flag. */
#ifdef DEBUG
    {"debug",   no_argument, &g_debug,   'd'},
#endif
    {"verbose", no_argument, &g_verbose, 'v'},
    {"quiet",   no_argument, &g_verbose, 'q'},
    {"raw",     no_argument, &opt_raw,   'r'},

    {"output",  required_argument, NULL, 'o'},
    {"path",    required_argument, NULL, 'p'},
    {0, 0, 0, 0}
};

#ifdef DEBUG
static const char my_short_options[] = "-?dhj:o:p:rv";
#else
static const char my_short_options[] = "-?hj:o:p:rv";
#endif

static const char my_help_fmt[] = "%s [%s]\n" \
    "Available options:\n" \
    " -h, --help\t\tShow this help\n" \
    " -j, --jobs=number\tUse parallel jobs [%d]\n" \
    " -o, --output=name\tWrite output to this file\n" \
    " -p, --path=directory\tPath to output directory [%s]\n" \
    " -r, --raw\t\tOutput raw data\n" \
    " -v, --verbose\t\tBe more verbose\n" \
    "";


#if defined __unix__  || defined __unix  || defined __UNIX__
static const char default_runtime_env[] = "XDG_RUNTIME_DIR";
static const char fallback_runtime_env[] = "TMPDIR";
static       char fallback_runtime_path[] = "/tmp/";
static const char default_data_path[] = "../";
#else
/* _Win32, _Win64, WIN16, OS/2, DOS or something else */
static const char default_runtime_env[] = "TEMP";
static const char fallback_runtime_env[] = "TMP";
static       char fallback_runtime_path[] = ".\\";
static const char default_data_path[] = "..\\";
#endif

static const char default_runtime_subdir[] = "" PACKAGE_NAME ".out";
static const char default_template_subdir[] = "template";

/* ############################## */
/*
 * activate DEBUG/verbose mode,
 * when the environment variable "DEBUG" is set
 * set verbose mode from the environment variable "VERBOSE"
 *
 */
static void init_debug_from_env(void)
{

#ifdef DEBUG
    char *env_data = getenv("DEBUG");

    if ((env_data != NULL) && (*env_data))
    {
        g_debug = atoi(env_data);
        ++g_verbose;
    }
    dbg("search for DEBUG: %p -> \"%s\"\n", env_data, env_data);

    env_data = getenv("VERBOSE");
    dbg("search for VERBOSE: %p -> \"%s\"\n", env_data, env_data);
    if ((env_data != NULL) && (*env_data))
    {
        g_verbose = atoi(env_data);
    }
#endif
}

/* ################################# */
/* Get the cpu count on this system  */
/* when threading support is enabled */

int get_cpu_count(void)
{
    long result;

#ifdef ENABLE_THREADS
    char *env_data;

#ifdef HAVE_SYSCONF
#ifdef _SC_NPROCESSORS_ONLN
    result = sysconf(_SC_NPROCESSORS_ONLN);
    dbg("sysconf(_SC_NPROCESSORS_ONLN) returned %d\n", (int) result);
    if (result <= 0)
#endif
#ifdef _SC_NPROCESSORS_CONF
    {
        result = sysconf(_SC_NPROCESSORS_CONF);
        dbg("sysconf(_SC_NPROCESSORS_CONF) returned %d\n", (int) result);
    }
#endif
#endif

    /* Support the well known env variable OMP_NUM_THREADS as thread count */
    /* overwrites the sysconf result */
    env_data = getenv("OMP_NUM_THREADS");
    dbg("search for OMP_NUM_THREADS: %p -> \"%s\"\n", env_data, env_data);
    if ((env_data != NULL) && (*env_data))
    {
        /* atol() is not used elsewhere */
        result = atoi(env_data);
    }

    if (result <= 0)
#endif
    {
        /* Fallback: use only one cpu */
        result = 1;
    }
    return (int) result;

}

/* ############################## */

static void free_defaults(void)
{
    free(default_path);
    default_path = NULL;
}

/* ############################## */
/*
 * set some defaults from environment
 */
static void init_defaults(char * argv_0)
{
    char * env_data;
    int len;

    g_verbose = 0;

    atexit(free_defaults);
    init_debug_from_env();

    dbg("argv[0]: %s\n", argv_0);
    g_appname = basename(argv_0);

    /* Get the cpu count on this system */
    /* Fallback: use only one job */
    opt_jobs = get_cpu_count();

    /* build a path for our output */
    env_data = getenv(default_runtime_env);

    if ((!env_data) || (! *env_data))
    {
        info("env '%s' failed: %p'\n", default_runtime_env, env_data);
        env_data = getenv(fallback_runtime_env);
        if ((!env_data) || (! *env_data))
        {
            info("env '%s' failed: %p\n", fallback_runtime_env, env_data);
            env_data = fallback_runtime_path;
        }
    }

    len = strlen(env_data);
    dbg("env_data_%d: %s\n", len, env_data);

    /* 1+1 byte extra for director separator and trailing zero */
    default_path = (char *) malloc(len + 1 + sizeof(default_runtime_subdir) + 1);

    if (!default_path)
        exit(1);

    strcpy(default_path, env_data);

    /* make sure, the path ends with a directory separator */
    if (default_path[len-1] != DIRECTORY_SEPARATOR_CHAR )
    {
        default_path[len] = DIRECTORY_SEPARATOR_CHAR ;
        ++len;
        default_path[len] = '\0';
    }

    strcpy(default_path + len, default_runtime_subdir);
    opt_path = default_path;
    info("default_path_%d: %s\n", (int) strlen(default_path), default_path);
}

/* ############################## */

void usage(int exitcode)
{
    printf(my_help_fmt, g_appname, my_short_options, opt_jobs, opt_path);
    free_defaults();
    dbg("exit with %d\n", exitcode);
    exit(exitcode);
}

/* ############################## */

int main(int argc, char * argv[])
{
    int c;

    init_defaults(argv[0]);

    {
        info("## starting with %d args\n", argc);
        for ( int i = 0; i < argc; i++)
        {
            info("arg_%d: %s\n", i, argv[i]);
        }
        info0("\n\n");
    }

    /* used by getopt_long: disable error message on unknown option */
#ifdef DEBUG
    opterr = DEBUG;
#endif

    while (1)
    {
        int old_verbose = g_verbose;
        int long_index = 0;
#ifdef DEBUG
        int old_debug = g_debug;
#endif
        optopt = 0;
        /* getopt_long stores the index of the matching long option in our parameter: &long_index */
        c = getopt_long(argc, argv, my_short_options, my_long_options, &long_index);

        dbg("getopt_long returned %d:'%c' with %d:'%c'\n", c, (c > 32) ? c : ' ',
                                            optopt, (optopt > 32) ? optopt : ' ' );

        /* Detect the end of the options. */
        if (c == -1)
        {
            dbg0("end of getopt_long with status:\n");
            dbg("long_index: %d\n", long_index);
            dbg("optarg: %p / %s\n", optarg, optarg);
            dbg("optind: %d\n", optind);
            dbg("opterr: %d\n", opterr);
            dbg("optopt: %d %c\n", optopt, optopt>32 ? optopt: 32);
            break;
        }

        switch (c)
        {
            case 0:

                /* We get a 0 result, when the argument has set/updated a flag */
                dbg("flag set. optind_%02d: long_index_%d  name: '%s' flag: %p->%d (optarg: %p: %s)\n",
                                optind, long_index, my_long_options[long_index].name,
                                my_long_options[long_index].flag,
                                my_long_options[long_index].flag ? *(my_long_options[long_index].flag) : 0,
                                optarg, optarg);


#ifdef DEBUG
                if (g_debug == 'd')
                {
                    g_debug = old_debug + 1;
                    dbg("updated --debug: %d\n", g_debug);
                }
#endif

                if (g_verbose == 'q')
                {
                    g_verbose = 0;
                    dbg("reset verbose to %d (--quiet)\n", g_verbose);
                }

                if (g_verbose == 'v')
                {
                    g_verbose = old_verbose + 1;
                    dbg("updated --verbose: %d\n", g_verbose);
                }


                break;

            case 1:
                info("got %d: found an extra arg\n", c);
                dbg("long_index: %d\n", long_index);
                dbg("optarg: %p / %s\n", optarg, optarg);
                dbg("optind: %d\n", optind);
                dbg("opterr: %d\n", opterr);
                dbg("optopt: %d %c\n", optopt, optopt>32 ? optopt: 32);
                break;

#ifdef DEBUG
            case 'd':
                ++g_debug;
                dbg("optind_%02d: long_index_%d: -d (opt_debug umdated to: %d)\n",
                            optind, long_index, g_debug);
                break;
#endif

            case 'h':
                usage(EXIT_FAILURE);
                break;


            case 'j':
                opt_jobs = atoi(optarg);
                dbg("optind_%02d: long_index_%d  option '%c' with argument: %s\n",
                            optind, long_index, c, optarg);
                break;

            case 'o':
                opt_output = optarg;
                dbg("optind_%02d: long_index_%d  option '%c' with argument: %s\n",
                            optind, long_index, c, optarg);
                break;

            case 'p':
                opt_path = optarg;
                dbg("optind_%02d: long_index_%d  option '%c' with argument: %s\n",
                            optind, long_index, c, optarg);
                break;

            case 'q':
                g_verbose = 0;
                dbg("reset verbose to %d (-q)\n", g_verbose);
                break;

            case 'r':
                opt_raw = c;
                dbg("updated raw: %3d %c\n", opt_raw, opt_raw);
                break;

            case 'v':
                ++g_verbose;
                dbg("optind_%02d: long_index_%d: -v  (opt_verbose updated to: %d)\n",
                            optind, long_index, g_verbose);
                break;

            case '?':
                /* getopt_long can print an error message and abort the program. See: opterr */

                dbg("getopt_long ended with '%c'\n", c);
                dbg("long_index: %d\n", long_index);
                dbg("optarg: %p / %s\n", optarg, optarg);
                dbg("optind: %d\n", optind);
                dbg("opterr: %d\n", opterr);
                dbg("optopt: %d %c\n", optopt, optopt>32 ? optopt: 32);

                usage(EXIT_FAILURE);
                break;

            default:
                printf("(optind: %d, long_index: %d). Program failure: No code for option %d %c (caller: %s)\n",
                        optind, long_index, c, c >32 ? c: 32, argv[optind-1]);
                exit(EXIT_FAILURE);
        }
    }

    dbg0("\n\n");

    printf("Hello %s\n", g_appname);

    dbg("opt_debug: %d %c\n", g_debug, (g_debug > 32) ? g_debug : 32);
    info("opt_jobs: %d\n", opt_jobs);
    info("opt_output: %p %s\n", opt_output, opt_output);
    info("opt_path: %p %s\n", opt_path, opt_path);
    info("opt_raw: %d %c\n", opt_raw, (opt_raw > 32) ? opt_raw : 32);
    info("opt_verbose: %d %c\n", g_verbose, (g_verbose > 32) ? g_verbose : 32);


    /* TODO: init workitem list */
    /* TODO: init thread list */
    /* TODO: add the main thread to the thread list */

    while (optind < argc)
    {
        info("extra_arg_%d: %s\n", optind, argv[optind]);
        ++optind;
    }

    /* TODO: use args to create initial work items */
    /* TODO: use the main thread to handle work items */
    /* TODO: cleanup: shutdown extra threads */

    printf("All done\n");

    info("return from main with %d\n", 0);

    printf("\n");
    return 0;
}


#ifdef __cplusplus
}
#endif


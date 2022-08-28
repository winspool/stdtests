/* ############# */
/* ToDo: License */

/*
 * Implement some functions for non posix compatible systems
 * Windows is such a system, which lacks a usable posix api for >30 years
 *
 */

#ifdef __cplusplus
extern "C" {
#endif


/* include the results from configure */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* ############################## */

#ifdef HAVE_WINDOWS_H
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif


/* ############################## */

#ifndef HAVE_BASENAME
#define HAVE_BASENAME 1
char * basename(char * path)
{
    char * res;

    if (!path) return NULL;
    res = strrchr(path, '/');

    if (res)
    {
        if (res[1])
        {
            res++;
        }
        else
        {
            *res = 0;
            res = strrchr(path, '/');
            if ((res) && (res[1]))
            {
                res++;
            }
            else
            {
                res = path;
            }
        }
    }
    else
    {
        res = path;
    }

    return res;
}
#endif

/* ############################## */

#ifndef HAVE_GETOPT_LONG
#define HAVE_GETOPT_LONG 1

/* getopt_long expect a pointer to an array of "option" structs */
/* last entry in the array has to be filled with NULL/0 values */
struct option
{
    const char *name;
    int  has_arg;
    int *flag;
    int  val;
};

/* values for the "has_arg" field */
#define no_argument	      0
#define required_argument 1
#define optional_argument 2

/* oetopt / getopt_long public API: save status between calls, return values to the caller */
char *optarg=NULL;  /* argument for the returned option */
int   opterr=1;     /* print errors messages on failure */
int   optopt=0;     /* this option character is unknown (when returning '?') */
int   optind=1;     /* next entry in argv to scan */


int getopt_long(int _gol_argc, char * _gol_argv[], const char * _gol_shortopts,
                const struct option * _gol_longopts, int * _gol_index)
{
    const char *this_arg;
    int c;
/* ToDo: do we need wchar_t here and mbtowc in the code for multibyte support? */

    if (optind <= 0)
    {
        optind = 1; /* skip argv[0] */
    }

    /* reset extended results */
    optarg = NULL;
    optopt = 0;

    if (optind >= _gol_argc || !_gol_argv[optind])
    {
        /* printf("%03d:%s: no more args\n",  __LINE__, __func__); */
        return -1;
    }

/* FIXME: getopt_long implementation */

    this_arg = _gol_argv[optind];
    c = 0;

    return -1;

}
#endif

/* ############################## */

#ifdef __cplusplus
}
#endif


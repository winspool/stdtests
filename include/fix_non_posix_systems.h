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


/* Added in C23, was a gcc extension since many years */
#ifndef __has_include
#define __has_include(name) (0)
#endif

/* ################################################ */
/* first include is always "config.h" from autoconf */
#ifdef HAVE_CONFIG_H
#ifndef PACKAGE_NAME
#include "config.h"
#elif __has_include("config.h")
#include "config.h"
#endif
#endif


/* ############################## */

/* needed for basename */
#ifdef HAVE_LIBGEN_H
#include <libgen.h>
#endif

/* needed for fprintf */
#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

/* needed for strchr */
#ifdef HAVE_STRING_H
#include <string.h>
#endif

/* sysconf and the _SC_* constants */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

/* ################ */

#ifdef HAVE_WINDOWS_H
#define WINDOWS_LEAN_AND_MEAN
#include <windows.h>
#endif

/* ############################## */

#ifndef DIRECTORY_SEPARATOR_CHAR
#ifdef _WIN32
#define DIRECTORY_SEPARATOR_CHAR '\\'
#else
#define DIRECTORY_SEPARATOR_CHAR '/'
#endif
#endif

/* ############################## */

#ifndef HAVE_BASENAME
#define HAVE_BASENAME 1
char * basename(char * path)
{
    char * res;

    if (!path) return NULL;
    res = strrchr(path, DIRECTORY_SEPARATOR_CHAR);

    if (res)
    {
        if (res[1])
        {
            res++;
        }
        else
        {
            *res = 0;
            res = strrchr(path, DIRECTORY_SEPARATOR_CHAR);
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

#ifndef __GETOPT_LONG_H__
#define __GETOPT_LONG_H__
#endif


/* getopt / getopt_long public API: save status between calls, return values to the caller */
char *optarg = NULL;    /* argument for the returned option */
int   opterr = 1;       /* print errors messages on failure */
int   optopt = 0;       /* this option character is unknown (when returning '?') */
int   optind = 1;       /* next entry in argv to scan */

/* used by FreeBSD, musl and probably other implementations (used as a bool) */
int   optreset = 1;     /* reset getopt state */

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
#define no_argument       0
#define required_argument 1
#define optional_argument 2

/* ToDo: do we need wchar_t and mbtowc in the code for multibyte support? */
int getopt_long(int _gol_argc, char * _gol_argv[], const char * _gol_shortopts,
                const struct option * _gol_longopts, int * _gol_index)
{
    char *this_arg;
    char *pos;
    int c;
    char first_opt_char = 0;

    /* reset internal state */
    if (optreset != 0 || optind <= 1)
    {
        optreset = 0;   /* no reset on the next call to getopt_long() */
        optind = 1;     /* skip argv[0] */
    }

    if (_gol_shortopts)
    {
        first_opt_char = *_gol_shortopts;
    }

    /* when first char is '+': stop at first non-option argument (default) */
    /* when first char is '-': return #1 for every non-option argument */
    if ((first_opt_char == '+') || (first_opt_char == '-'))
    {
        ++_gol_shortopts;
    }

    /* reset extended results */
    optarg = NULL;
    optopt = 0;
    if (_gol_index)
    {
        *_gol_index = 0;
    }

    if (optind >= _gol_argc || !_gol_argv[optind])
    {
        /* printf("%03d:%s: no more args\n",  __LINE__, __func__); */
        return -1;
    }

    this_arg = _gol_argv[optind];
    c = 0;

    /* do we have a long option? */
    if ((this_arg[0] == '-') && (this_arg[1] == '-'))
    {
        const struct option *found_option = NULL;
        size_t len_arg;
        size_t len_opt;
        int i = 0;

        /* skip both "--" */
        this_arg += 2;
        if ((! *this_arg) || (!_gol_longopts))
        {
            /* found a "--": stop parsing */
            ++optind;
            return -1;
        }

        /* search the _gol_longopts array for an exact match */
        pos = strchr(this_arg, '=');
        len_arg = pos ?  (pos-this_arg) : strlen(this_arg);

        while (!found_option && _gol_longopts[i].name)
        {

            len_opt = strlen(_gol_longopts[i].name);
            if ((len_arg != len_opt) || (strncmp(this_arg, _gol_longopts[i].name, len_arg)))
            {
                /* this_arg does not match the current entry in the _gol_longopts array */
                ++i;
            }
            else
            {
                found_option = &_gol_longopts[i];
            }
        }

        if (found_option)
        {

            /* has this option a flag pointer? */
            if (found_option->flag)
            {
                int * ptr = found_option->flag;
                *ptr = found_option->val;
            }

            /* has this_arg an argument? */
            if (pos)
            {
                /* an equal sign follows this_arg. Is an arg allowed? */
                if (!found_option->has_arg)
                {

                    if (opterr)
                    {
                        fprintf(stderr, "%s: no argument allowed for option --%s\n", basename(_gol_argv[0]), found_option->name);
                    }
                    pos = NULL;
                    optopt = found_option->val;
                    ++optind;
                    return '?';
                }

                /* skip the equal sign and use the rest as argument */
                optarg = pos+1;
                pos = NULL;
            }
            else if ((found_option->flag == NULL) || (found_option->has_arg == required_argument))
            {
                /* no equal sign in this_arg. try to use the next option as our argument */
                /* (a NULL follows the array: using _gol_argv[optint+1] is safe) */
                optarg = (found_option->has_arg == no_argument) ? NULL : _gol_argv[optind+1];

                if ((optarg != NULL) && (found_option->has_arg != no_argument))
                {
                    /* ok: argument present and allowed */
                    ++optind;
                }

                if ((optarg == NULL) && (found_option->has_arg == required_argument))
                {
                    /* fail: argument required, but missing */
                    if (opterr)
                    {
                        fprintf(stderr, "%s: argument required for option --%s\n", basename(_gol_argv[0]), found_option->name);
                    }
                    optopt = found_option->val;
                    ++optind;
                    return '?';
                }

            }

            if (_gol_index)
                *_gol_index = i;

            ++optind;
            return (found_option->flag) ? 0 : found_option->val;
        }
        else
        {
            /* failure: unknown option */
            if (opterr)
            {
                fprintf(stderr, "%s: unknown option --%s\n", basename(_gol_argv[0]), this_arg);
            }
            optopt=0;
            ++optind;
            return '?';
        }

    }
    else
    {
        /* check for an short option */
        if (_gol_shortopts && (*this_arg == '-') && (this_arg[1]))
        {
            c = this_arg[1];

            pos = strchr(_gol_shortopts, c);

            if (pos)
            {
                /* is an argument needed for this option? */
                if (pos[1] == ':')
                {
                    if (this_arg[2])
                    {
                        optarg = this_arg + 2;
                    }
                    else
                    {
                        ++optind;
                        optarg = _gol_argv[optind];
                    }
                    if (!optarg)
                    {
                        /* fail: argument required, but missing */
                        if (opterr)
                        {
                            fprintf(stderr, "%s: argument required for option -%c\n", basename(_gol_argv[0]), c);
                        }
                        optopt = c;
                        return '?';
                    }
                }
                else
                {
                    if (this_arg[2])
                    {
                        fprintf(stderr, "FIXME: more args in this option: %s\n", this_arg);
                    }
                }
                ++optind;
                return c;
            }
            else
            {
                /* failure: unknown option */
                if (opterr)
                {
                    fprintf(stderr, "%s: unknown option -%c\n", basename(_gol_argv[0]), c);
                }
                optopt = c;
                return '?';
            }
            fprintf(stderr, "FIXME: implement short option support\n");
        }
        else
        {
            optarg = this_arg;
            ++optind;
            return (first_opt_char == '-') ? 1 : -1;
        }
    }

    /* the caller has to handle all additional arguments */
    return -1;
}

#endif /* HAVE_GETOPT_LONG */

/* ############################## */


#ifndef HAVE_SYSCONF

#ifndef _SC_NPROCESSORS_ONLN
#define _SC_NPROCESSORS_ONLN 13
#endif

#ifdef _WIN32
#define HAVE_SYSCONF 1

long sysconf(int id)
{
    SYSTEM_INFO win32_sysinfo;
    GetSystemInfo(&win32_sysinfo);

    switch (id)
    {
        case _SC_NPROCESSORS_ONLN:
            return (long) win32_sysinfo.dwNumberOfProcessors;

        default:
            printf("%s(%d): implementation missing\n", __func__, id);
            exit(EXIT_FAILURE);
    }

    return -1;
}

#else

#warning "Need a replacement for 'sysconf()' for this OS"
#endif

#endif

/* ############################## */

#ifdef __cplusplus
}
#endif


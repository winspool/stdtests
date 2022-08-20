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
            if (res) && (res[1])
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

#ifdef __cplusplus
}
#endif


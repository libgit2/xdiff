/*
 * This file provides the necessary indirection between xdiff and
 * the calling application. Callers can use this file to avoid modifying
 * xdiff itself with application-specific code, while still using their
 * bespoke runtime. For example: callers may wish to use a specific
 * `malloc` function, and can do so by defining `xdl_malloc` in this
 * file.
 */

#ifndef __GIT_XDIFF_H__
#define __GIT_XDIFF_H__

#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* Work around C90-conformance issues */
#if !defined(__STDC_VERSION__) || (__STDC_VERSION__ < 199901L)
# if defined(_MSC_VER)
#  define inline __inline
# elif defined(__GNUC__)
#  define inline __inline__
# else
#  define inline
# endif
#endif

#if defined(__GNUC__) && defined(__GNUC_MINOR__) && \
    ((__GNUC__ << 16) + __GNUC_MINOR__ >= (4 << 16) + 5)
# define XDL_UNUSED __attribute__((unused)) \
	__attribute__((deprecated ("parameter declared as UNUSED")))
#elif defined(__GNUC__)
# define XDL_UNUSED __attribute__((unused)) \
	__attribute__((deprecated))
#else
# define XDL_UNUSED
#endif

#define xdl_malloc(x) malloc(x)
#define xdl_calloc(n, sz) calloc(n, sz)
#define xdl_free(ptr) free(ptr)
#define xdl_realloc(ptr, x) realloc(ptr, x)

#define XDL_BUG(msg) do { fprintf(stderr, "fatal: %s\n", msg); exit(128); } while(0)

#if defined(_MSC_VER) && !defined(XDL_REGEX)

# define xdl_regex_t void *
# define xdl_regmatch_t void *

inline int xdl_regexec_buf(
	const xdl_regex_t *preg, const char *buf, size_t size,
	size_t nmatch, xdl_regmatch_t pmatch[], int eflags)
{
    return 15; /* REG_ASSERT */
}

#else
# include <regex.h>

# define xdl_regex_t regex_t
# define xdl_regmatch_t regmatch_t

inline int xdl_regexec_buf(
	const xdl_regex_t *preg, const char *buf, size_t size,
	size_t nmatch, xdl_regmatch_t pmatch[], int eflags)
{
    pmatch[0].rm_so = 0;
    pmatch[0].rm_eo = size;

    return regexec(preg, buf, nmatch, pmatch, eflags | REG_STARTEND);
}

#endif /* XDL_NO_REGEX */

#endif

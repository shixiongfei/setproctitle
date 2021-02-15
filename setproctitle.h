/* ==========================================================================
 * setproctitle.c - Linux/Darwin setproctitle.
 * --------------------------------------------------------------------------
 * Copyright (C) 2010  William Ahern
 * Copyright (C) 2013  Salvatore Sanfilippo
 * Copyright (C) 2013  Stam He
 * Copyright (C) 2019  Xiongfei Shi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
 * NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 * USE OR OTHER DEALINGS IN THE SOFTWARE.
 * ==========================================================================
 */

#ifndef __SETPROCTITLE_H__
#define __SETPROCTITLE_H__

#ifndef HAVE_SETPROCTITLE
#if defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
#define HAVE_SETPROCTITLE 1
#include <sys/types.h>
#include <unistd.h>
#else
#define HAVE_SETPROCTITLE 0
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if !HAVE_SETPROCTITLE
#define INIT_SETPROCTITLE_REPLACEMENT
#ifndef _WIN32
void spt_init(int argc, char *argv[]);
void setproctitle(const char *fmt, ...);
#else /* _WIN32 */
#include <Windows.h>
#include <stdio.h>
#define spt_init(a, b)
#define setproctitle(fmt, ...)                                                 \
  do {                                                                         \
    char szTitle[MAX_PATH];                                                    \
    sprintf(szTitle, fmt, ##__VA_ARGS__);                                      \
    SetConsoleTitleA(szTitle);                                                 \
  } while (0)
#endif /* _WIN32 */
#endif /* HAVE_SETPROCTITLE */

#ifdef __cplusplus
};
#endif

#endif /* __SETPROCTITLE_H__ */

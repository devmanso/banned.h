#ifndef BANNED_H
#define BANNED_H

/*
 * This header lists functions that have been banned from our code base,
 * because they're too easy to misuse (and even if used correctly,
 * complicate audits). Including this header turns them into compile-time
 * errors.
 */

// original: https://github.com/git/git/blob/master/banned.h
// modified by me, Mansour Quddus (@devmanso)

#define BANNED(func) sorry_##func##_is_a_banned_function

#undef strcpy
#define strcpy(x, y) BANNED(strcpy)
#undef strcat
#define strcat(x, y) BANNED(strcat)
#undef strncpy
#define strncpy(x, y, n) BANNED(strncpy)
#undef strncat
#define strncat(x, y, n) BANNED(strncat)

// windows only str functions
#undef _mbscpy
#define _mbscpy(x, y) BANNED(_mbscpy)
#undef wcscpy
#define wcscpy(x, y) BANNED(wcscpy)
#undef _mbscat
#define _mbscat(x, y) BANNED(_mbscat)
#undef wcscat
#define wcscat(x, y) BANNED(wcscat)
#undef wcsncat
#define wcsncat(x, y, n) BANNED(wcsncat)
#undef _mbsncat
#define _mbsncat(x, y, n) BANNED(_mbsncat)
#undef _mbsncat_l
#define _mbsncat_l(x, y, n) BANNED(_mbsncat_l)

// _Itoa, and _itoa are the same functions, the only difference is in the name
#undef _itoa
#define _itoa(x, y, n) BANNED(_itoa)
#undef _Itoa
#define _Itoa(x, y, n) BANNED(_Itoa)
#undef _itow
#define _itow(x, y, n) BANNED(_itow)
#undef _Itow
#define _Itow(x, y, n) BANNED(_Itow)
#undef ultow
#define ultow(x, y, n) BANNED(ultow)
#undef i64toa
#define i64toa(x, y, n) BANNED(i64toa)
#undef ui64toa
#define ui64toa(x, y, n) BANNED(ui64toa)

// more banned sprint functions
#undef snprintf
#define snprintf(...) BANNED(snprintf)
#undef sprintf
#undef vsprintf
#define sprintf(...) BANNED(sprintf)
#define vsprintf(...) BANNED(vsprintf)

#undef gmtime
#define gmtime(t) BANNED(gmtime)
#undef localtime
#define localtime(t) BANNED(localtime)
#undef ctime
#define ctime(t) BANNED(ctime)
#undef ctime_r
#define ctime_r(t, buf) BANNED(ctime_r)
#undef asctime
#define asctime(t) BANNED(asctime)
#undef asctime_r
#define asctime_r(t, buf) BANNED(asctime_r)

#endif /* BANNED_H */

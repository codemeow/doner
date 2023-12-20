/*
 * "Doner" - Easing functions tables generator
 *
 *  Copyright (C) https://github.com/codemeow 2023
 *
 *  This file is part of Project "Doner".
 *
 *  Project "Doner" is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Project "Doner" is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with Project "Doner". If not, see <http://www.gnu.org/licenses/>.
 */

#include "../util/dnr_util_platform.h"

#include <stdio.h>
#include <stdlib.h>

#if defined(DNR_PLATFORM_WIN)
#   include <windows.h>
#   include <wchar.h>
#endif

#include "../util/dnr_util_print.h"

/*! \brief Initializes required printing attributes */
__attribute__((constructor))
static void _init(void) {
#if defined(DNR_PLATFORM_WIN)
    /* Without disabled buffering cmd buffers line by 1024 bytes,
     * sometimes tearing UTF-8 characters */
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    /* Enabling UTF-8 page */
    SetConsoleOutputCP(65001);
#endif
}

#if defined(DNR_PLATFORM_WIN)
/*! \brief Converts UTF-8 string to windows-wide char
 * \param[in] wstr Unicode string
 * \return Allocated converted string */
static LPWSTR _stringa2w(const char * str) {
    const int wstr_size = MultiByteToWideChar(
        CP_UTF8, 
        MB_ERR_INVALID_CHARS, 
        str, 
        -1, 
        NULL, 
        0
    );
    if (wstr_size == 0)
        return NULL;

    LPWSTR wstr = malloc(wstr_size * sizeof(wstr[0]));

    if (MultiByteToWideChar(
            CP_UTF8, 
            MB_ERR_INVALID_CHARS, 
            str, 
            -1, 
            wstr, 
            wstr_size
        ) == 0
    ) {
        free(wstr);
        return NULL;
    }

    return wstr;
}
#endif

/*! \brief Prints provided text with platform-depended function
 * \param[in] fmt Printf-formatter string
 * \param[in] args provided printf-arguments */
static void _voutput(const char * fmt, va_list args) {
#if defined(DNR_PLATFORM_NIX)
    vprintf(fmt, args);


#elif defined(DNR_PLATFORM_WIN)
    // https://www.youtube.com/watch?v=GeNey4E7wBU

    va_list copy;
    va_copy(copy, args);
    int size = vsnprintf(NULL, 0, fmt, copy);
    va_end(copy);

    char * str = malloc(size + 1);
    vsprintf(str, fmt, args);

    LPWSTR wstr = _stringa2w(str);
    if (!wstr) {
        free(str);
        fprintf(stderr, "Cannot convert wide string\n");
        abort();
    }

    DWORD nwritten = 0;
    WriteConsoleW(
        GetStdHandle(STD_OUTPUT_HANDLE), 
        wstr, 
        wcslen(wstr), 
        &nwritten, 
        NULL
    );

    free(wstr);
    free(str);

#else
#   error Unsupported platform. Provide printing function that supports UTF-8
#endif
}

/*! \brief System-dependently outputs the text
 * \param[in] fmt Printf-formatter string
 * \param[in] ... provided printf-arguments
 * \note I hate windows */
__attribute__((format(printf, 1, 2)))
void dnr_util_print(const char * fmt, ...) {
    va_list args;
    va_start(args, fmt);
    _voutput(fmt, args);
    va_end(args);
}


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

#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "../util/dnr_util_term.h"
#include "../util/dnr_util_size.h"

/*! \brief Returns current terminal's size
 * \note If the terminal is not present, some standard size is returned
 * \note If the terminal size is less than some size the minimum allowed size
 *       is returned instead
 *
 * \param[out] width Terminal's width
 * \param[out] height Terminal's height */
void dnr_util_term(unsigned short * width, unsigned short * height) {
    static const unsigned short stdwidth  = 80;
    static const unsigned short stdheight = 24;
    static const unsigned short minwidth  = 20;
    static const unsigned short minheight = 8;

    struct winsize ws;

    errno = 0;
    int res = ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    if (res == 0) {
        *height = DNR_MAX(ws.ws_row, minheight);
        *width  = DNR_MAX(ws.ws_col, minwidth);

    } else if (errno == ENOTTY) {
        *height = stdheight;
        *width  = stdwidth;

    } else {
        fprintf(
            stderr,
            "Unexpected error (%s / %d) at %s\n",
            strerror(errno),
            errno,
            __FUNCTION__
        );
        exit(EXIT_FAILURE);
    }
}

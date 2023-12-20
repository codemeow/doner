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

#ifndef DNR_UTIL_FMT_H
#define DNR_UTIL_FMT_H

#include <stdbool.h>
#include "../table/list/dnr_nmod_list.h"

/*! \brief Parses and assigns the fmt string, checking for printf-allowed fmt
 * \param[out] nmod Assigns the NMOD value for this string
 * \param[out] fmt Assigns the fmt string
 * \param[in] value The string to parse 
 * \return True if both nmod and fmt assigned successfully */
bool dnr_set_fmt(
    enum dnr_nmod_list * nmod, 
    const char ** fmt, 
    const char * value
);

#endif

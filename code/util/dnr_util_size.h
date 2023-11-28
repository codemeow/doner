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

#ifndef DNR_UTIL_SIZE_H
#define DNR_UTIL_SIZE_H

/*! \brief Returns number of elements in the static array 
 * \param[in] x Static array 
 * \return Number of elements */
#define DNR_SIZE(x) ((size_t)(sizeof(x) / sizeof((x)[0])))

/*! \brief Returns the minimum of two numbers
 * \note Be advised that both x and y are calculated twice
 * \param[in] x First number
 * \param[in] y Second number
 * \return The lesser of [x, y] */
#define DNR_MIN(x, y) ((x) < (y) ? (x) : (y))

/*! \brief Returns the maximum of two numbers
 * \note Be advised that both x and y are calculated twice
 * \param[in] x First number
 * \param[in] y Second number
 * \return The greater of [x, y] */
#define DNR_MAX(x, y) ((x) > (y) ? (x) : (y))

#endif

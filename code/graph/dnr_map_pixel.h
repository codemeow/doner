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

#include <stddef.h>
#include <unistd.h>
#include "../graph/dnr_map_type.h"

/*! \brief Sets the selected pixel value for bitmap
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position
 * \param[in] value Value to set */
__attribute__((nonnull(1)))
void dnr_map_set(
    struct dnr_map_type * map, 
    ssize_t x, 
    ssize_t y, 
    unsigned char value
);

/*! \brief Get the selected pixel value for bitmap
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position 
 * \return Value */
__attribute__((nonnull(1)))
unsigned char dnr_map_get(
    struct dnr_map_type * map, 
    ssize_t x, 
    ssize_t y
);


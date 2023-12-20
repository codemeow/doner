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

#include "../graph/dnr_map_pixel.h"
#include "../graph/dnr_map_util.h"

/*! \brief Calculates the byte to pick for these coordinates
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position
 * \return Byte, where these coordinates are coded by */
static size_t _calc_byte(struct dnr_map_type * map, ssize_t x, ssize_t y) {
    return (x + y * map->width) / (dnr_braille_width * dnr_braille_height);
}

/*! \brief Calculates the bit to pick for these coordinates
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position
 * \return Bit, where these coordinates are coded by */
static size_t _calc_bit(struct dnr_map_type * map, ssize_t x, ssize_t y) {
    return (x + y * map->width) % (dnr_braille_width * dnr_braille_height);
}

/*! \brief Sets the selected pixel value for bitmap
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position
 * \param[in] value Value to set */
void dnr_map_set(
    struct dnr_map_type * map, 
    ssize_t x, 
    ssize_t y, 
    unsigned char value
) {
    if (x < 0 || y < 0 || (size_t)x >= map->width || (size_t)y >= map->height)
        return;

    size_t Bi = _calc_byte(map, x, y);
    size_t bi = _calc_bit (map, x, y);

    if (value) 
         map->data[Bi] |=  (1 << bi);
    else map->data[Bi] &= ~(1 << bi);
}

/*! \brief Get the selected pixel value for bitmap
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position 
 * \return Value */
unsigned char dnr_map_get(
    struct dnr_map_type * map, 
    ssize_t x, 
    ssize_t y
) {
    if (x < 0 || y < 0 || (size_t)x >= map->width || (size_t)y >= map->height)
        return 0;

    size_t Bi = _calc_byte(map, x, y);
    size_t bi = _calc_bit (map, x, y);

    return 1 & (map->data[Bi] >> bi);
}

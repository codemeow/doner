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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../graph/dnr_map_alloc.h"

/*! \brief Creates new bitmap
 * \param[in] width Width of bitmap
 * \param[in] height Height of bitmap
 * \return Allocated bitmap */
struct dnr_map_type * dnr_map_alloc(size_t width, size_t height) {
    const size_t size = width * height;

    struct dnr_map_type * map = malloc(sizeof(*map));
    if (!map) {
        fprintf(stderr, "Allocation error: %zu bytes\n", sizeof(*map));
        exit(EXIT_FAILURE);
    }

    map->width  = width;
    map->height = height;
    map->max    = 0.0;
    map->min    = 0.0;
    map->data   = malloc(size);
    if (!map->data) {
        fprintf(stderr, "Allocation error: %zu bytes\n", size);
        exit(EXIT_FAILURE);
    }
    
    memset(map->data, 0, size);

    return map;
}

/*! \brief Frees provided bitmap
 * \param[in] map Provided bitmap */
void dnr_map_free(struct dnr_map_type * map) {
    if (!map)
        return;

    free(map->data);
    free(map);
}

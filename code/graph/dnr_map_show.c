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

#include "../graph/dnr_map_show.h"
#include "../util/dnr_util_size.h"
#include "../graph/dnr_map_pixel.h"
#include "../graph/dnr_map_util.h"
#include "../easy/data/dnr_easy_data.h"
#include "../args/dnr_args_vars.h"
#include "../util/dnr_util_print.h"

#define DNR_BRAILLE_COUNT (256)

/*! \brief Braille table characters */
char dnr_brl_map[DNR_BRAILLE_COUNT][4];

/*! \brief Initializes Braille table */
static void _brl_init(void) {
    for (size_t i = 0; i < DNR_SIZE(dnr_brl_map); i++) {
        dnr_brl_map[i][0] = 0xe2;
        dnr_brl_map[i][1] = (0xa0 + (i >> 6));
        dnr_brl_map[i][2] = ((i & 0x0f) + ((i % 0x40) & 0xf0) + 0x80);
        dnr_brl_map[i][3] = '\0';
    }
}

/*! \brief Module initializer */
__attribute__((constructor))
static void _init(void) {
    _brl_init();
}

/*! \brief Return the index of the braille character in the `dnr_brl_map`
 * \param[in] map Provided bitmap
 * \param[in] x X position
 * \param[in] y Y position
 * \return The index in `dnr_brl_map` */
static unsigned char _brl_char(struct dnr_map_type * map, size_t x, size_t y) {
    return dnr_map_get(map, x + 0, y + 0) << 0 |
           dnr_map_get(map, x + 0, y + 1) << 1 |
           dnr_map_get(map, x + 0, y + 2) << 2 |
           dnr_map_get(map, x + 1, y + 0) << 3 |
           dnr_map_get(map, x + 1, y + 1) << 4 |
           dnr_map_get(map, x + 1, y + 2) << 5 |
           dnr_map_get(map, x + 0, y + 3) << 6 |
           dnr_map_get(map, x + 1, y + 3) << 7;
}

/*! \brief Shows map's info
 * \param[in] map Bitmap */
static void _map_info(struct dnr_map_type * map) {
    dnr_util_print("Easing:\n");
    dnr_util_print("    %s\n", dnr_easy_data[dnr_set_easy].name);
    dnr_util_print("Graph :\n");
    dnr_util_print("    Min: %8.3f\n", map->min);
    dnr_util_print("    Max: %8.3f\n", map->max);
    dnr_util_print("\n");
}

/*! \brief Prints map's data
 * \param[in] map Bitmap */
static void _map_show(struct dnr_map_type * map) {
    for (size_t y = 0; y < map->height; y += dnr_braille_height) {
        for (size_t x = 0; x < map->width; x += dnr_braille_width) {
            dnr_util_print("%s", dnr_brl_map[_brl_char(map, x, y)]);
        }
        dnr_util_print("\n");
    }
}

/*! \brief Draws provided map as Braille dots
 * \param[in] map */
void dnr_map_show(struct dnr_map_type * map) {
    _map_info(map);
    _map_show(map);
}

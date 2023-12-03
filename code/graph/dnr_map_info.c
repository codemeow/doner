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

#include <stdio.h>
#include "../graph/dnr_map_info.h"
#include "../args/dnr_args_process.h"
#include "../easy/data/dnr_easy_data.h"

/*! \brief Shows map's info
 * \param[in] map Bitmap */
void dnr_map_info(struct dnr_map_type * map) {
    printf("Easing: %s\n", dnr_easy_data[dnr_set_easy].name);
    printf("Graph :\n");
    printf("    Min: %8.3f\n", map->min);
    printf("    Max: %8.3f\n", map->max);
    printf("\n");
}

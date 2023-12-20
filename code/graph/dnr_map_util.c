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

#include "../graph/dnr_map_util.h"

/*! \brief Number of X braille dots per char */
const size_t dnr_braille_width = 2;
/*! \brief Number of Y braille dots per char */
const size_t dnr_braille_height = 4;

/*! \brief Converts terminal width to map width
 * \param[in] width Terminal width
 * \return Map width */
size_t dnr_map_termw2mapw(size_t width) {
    return width * dnr_braille_width;
}

/*! \brief Converts terminal height to map width
 * \param[in] height Terminal height
 * \return Map height */
size_t dnr_map_termh2maph(size_t height) {
    return height * dnr_braille_height;
}

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
#include "../util/dnr_util_conv.h"

/*! \brief Converts string value to double
 * \param[out] Value to set
 * \param[in] str String to convert
 * \return True if the conversion was successfull */
bool dnr_set_dvalue(double * value, const char * str) {
    char * end = NULL;
    *value = strtod(str, &end);
    return end && *end == '\0';
}

/*! \brief Converts string value to size_t
 * \param[out] Value to set
 * \param[in] str String to convert
 * \return True if the conversion was successfull */
bool dnr_set_svalue(size_t * value, const char * str) {
    char * end = NULL;
    *value = strtol(str, &end, 10);
    return end && *end == '\0';
}

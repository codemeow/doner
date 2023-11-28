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

#ifndef DNR_MMOD_DATA_H
#define DNR_MMOD_DATA_H

#include "../../graph/list/dnr_mmod_list.h"

/*! \brief Map mod function template
 * \param[in] X input value in the range of [0..1]
 * \return Output value */
typedef double (* dnr_mmod_func)(double x);

/*! \brief The information about each Map mod function */
struct dnr_mmod_data {
    dnr_mmod_func func;     /*!< Implementation function    */
    const char *  name;     /*!< Map mod name               */
};

/*! \brief Instance of mods' data */
extern const struct dnr_mmod_data dnr_mmod_data[];

/*! \brief Converts string name to mapmod element
 * \param[in] name String representation
 * \return Enum element or dnr_mapmod_list::DNR_MAPMOD_COUNT */
enum dnr_mmod_list dnr_mmod_name2list(const char * name);

#endif

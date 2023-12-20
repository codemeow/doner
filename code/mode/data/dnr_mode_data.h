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

#ifndef DNR_MODE_DATA_H
#define DNR_MODE_DATA_H

#include "../../mode/list/dnr_mode_list.h"

/*! \brief Mode function template */
typedef void (* dnr_mode_func)(void);

/*! \brief The information about each mode function */
struct dnr_mode_data {
    dnr_mode_func func;     /*!< Implementation function    */
    const char *  name;     /*!< Easing name                */
};

/*! \brief Instance of modes' data */
extern const struct dnr_mode_data dnr_mode_data[];

/*! \brief Find mode enum by provided mode list
 * \param[in] name Name to find ("graph", "table", etc)
 * \return Mode enum or dnr_mode_list::DNR_MODE_COUNT on fail */
enum dnr_mode_list dnr_mode_name2list(const char * name);

#endif

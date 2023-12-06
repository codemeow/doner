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

#ifndef DNR_NMOD_DATA_H
#define DNR_NMOD_DATA_H

#include "../../table/list/dnr_nmod_list.h"

/*! \brief Numeric mode function template
 * \param[in] fmt Selected formatter
 * \param[in] Y function output value */
typedef void (* dnr_nmod_func)(const char * fmt, double y);

/*! \brief The information about each numeric mode function */
struct dnr_nmod_data {
    dnr_nmod_func func;     /*!< Implementation function    */
};

/*! \brief Instance of numeric modes' data */
extern const struct dnr_nmod_data dnr_nmod_data[];

#endif

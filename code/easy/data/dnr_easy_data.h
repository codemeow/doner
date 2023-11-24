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

#ifndef DNR_EASY_DATA_H
#define DNR_EASY_DATA_H

/*! \brief Easing function template
 * \param[in] X input value in the range of [0..1]
 * \return Output value */
typedef double (* dnr_easy_func)(double x);

/*! \brief The information about each easing function */
struct dnr_easy_data {
    dnr_easy_func func;     /*!< Implementation function    */
    const char *  name;     /*!< Easing name                */
};

/*! \brief Instance of easings' data */
extern const struct dnr_easy_data dnr_easy_data[];

#endif

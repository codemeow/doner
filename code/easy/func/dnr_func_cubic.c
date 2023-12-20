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

#include <math.h>
#include "../../easy/func/dnr_func_cubic.h"

/*! \brief InCubic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_incubic(double x) {
    return pow(x, 3.0);
}

/*! \brief OutCubic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outcubic(double x) {
    return 1.0 - pow(1.0 - x, 3.0);
}

/*! \brief InOutCubic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutcubic(double x) {
    return x < 0.5 ? 
        4.0 * pow(x, 3.0) : 
        1.0 - pow(-2.0 * x + 2.0, 3.0) / 2.0;
}


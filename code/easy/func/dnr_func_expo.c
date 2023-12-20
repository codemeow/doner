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

#include <float.h>
#include <math.h>
#include "../../easy/func/dnr_func_expo.h"

/*! \brief InExpo easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inexpo(double x) {
    return fabs(x) < DBL_EPSILON ? 
        0.0 : 
        pow(2.0, 10.0 * x - 10.0);
}

/*! \brief OutExpo easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outexpo(double x) {
    return fabs(x - 1.0) < DBL_EPSILON ? 
        1.0 : 
        1.0 - pow(2.0, -10.0 * x);
}

/*! \brief InOutExpo easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutexpo(double x) {
    return fabs(x) < DBL_EPSILON ?
        0.0
        : fabs(x - 1.0) < DBL_EPSILON ? 
            1.0 : 
            x < 0.5 ? 
                pow(2.0, 20.0 * x - 10.0) / 2.0 : 
                (2.0 - pow(2.0, -20.0 * x + 10.0)) / 2.0;
}


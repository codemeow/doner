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
#include "../../easy/func/dnr_func_elastic.h"

/* \brief Math factor c4 */
static const double c4 = (2.0 * M_PI) / 3.0;
/* \brief Math factor c5 */
static const double c5 = (2.0 * M_PI) / 4.5;

/*! \brief InElastic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inelastic(double x) {
    return fabs(x) < DBL_EPSILON ? 
        0.0 : 
        fabs(x - 1.0) < DBL_EPSILON ? 
            1.0 : 
            -pow(2.0, 10.0 * x - 10.0) * sin((x * 10.0 - 10.75) * c4);
}

/*! \brief OutElastic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outelastic(double x) {
    return fabs(x) < DBL_EPSILON ? 
        0.0 : 
        fabs(x - 1.0) < DBL_EPSILON ? 
            1.0 : 
            pow(2.0, -10.0 * x) * sin((x * 10.0 - 0.75) * c4) + 1.0;
}

/*! \brief InOutElastic easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutelastic(double x) {
    return fabs(x) < DBL_EPSILON ? 
        0.0 : 
        fabs(x - 1.0) < DBL_EPSILON ? 
            1.0 : 
            x < 0.5 ? 
                -(pow(2.0, 20.0 * x - 10.0) * sin((20.0 * x - 11.125) * c5)) / 2.0 : 
                (pow(2.0, -20.0 * x + 10.0) * sin((20.0 * x - 11.125) * c5)) / 2.0 + 1.0;
}


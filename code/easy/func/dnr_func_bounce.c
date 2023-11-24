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
#include "../../easy/func/dnr_func_bounce.h"

/*! \brief InBounce easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inbounce(double x) {
    return 1.0 - dnr_func_outbounce(1.0 - x);
}

/*! \brief OutBounce easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outbounce(double x) {
    static const double n1 = 7.5625;
    static const double d1 = 2.75;

    if (x < (1.0 / d1)) {
        return n1 * pow(x, 2.0);

    } else if (x < (2.0 / d1)) {
        x -= (1.5 / d1);
        return n1 * pow(x, 2.0) + 0.75;

    } else if (x < (2.5 / d1)) {
        x -= (2.25 / d1);
        return n1 * pow(x, 2.0) + 0.9375;

    } else {
        x -= (2.625 / d1);
        return n1 * pow(x, 2.0) + 0.984375;
    }
}

/*! \brief InOutBounce easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutbounce(double x) {
    return x < 0.5 ? 
        (1.0 - dnr_func_outbounce(1.0 - 2.0 * x)) / 2.0 : 
        (1.0 + dnr_func_outbounce(2.0 * x - 1.0)) / 2.0;
}


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
#include "../../easy/func/dnr_func_back.h"

/*! \brief Math factor c1 */
static const double c1 = 1.70158;
/*! \brief Math factor c2 */
static const double c2 = c1 * 1.525;

/*! \brief InBack easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inback(double x) {
    return (c1 + 1.0) * pow(x, 3.0) - c1 * pow(x, 2.0);
}

/*! \brief OutBack easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outback(double x) {
    return 1.0 + dnr_func_inback(x - 1.0);
}

/*! \brief InOutBack easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutback(double x) {
    return x < 0.5 ? 
        (pow(2.0 * x, 2.0) * ((c2 + 1.0) * 2.0 * x - c2)) / 2.0 : 
        (pow(2.0 * x - 2.0, 2.0) * ((c2 + 1.0) * (x * 2.0 - 2.0) + c2) + 2.0) / 2.0;
}


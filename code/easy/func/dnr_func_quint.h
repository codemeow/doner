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

#ifndef DNR_FUNC_QUINT_H
#define DNR_FUNC_QUINT_H

/*! \brief InQuint easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inquint(double x);

/*! \brief OutQuint easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_outquint(double x);

/*! \brief InOutQuint easing function
 * \param[in] x Input value, [0..1]
 * \return Output value */
double dnr_func_inoutquint(double x);

#endif

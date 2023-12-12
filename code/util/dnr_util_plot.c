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

#include "../util/dnr_util_plot.h"
#include "../args/dnr_args_vars.h"

#include "../graph/data/dnr_mmod_data.h"
#include "../easy/data/dnr_easy_data.h"

/*! \brief Plots the point of the currently selected function according to the
 * provided plot width and x point
 * \param[in] width Plot width (how many points there should be between [0, 1])
 * \param[in] x Current position
 * \return Calculated final value of F(x) */
double dnr_util_plot(size_t width, double x) {
    double fx = x * (1.0 / (width - 1));
    fx = dnr_mmod_data[dnr_set_xmod].func(fx);

    double fy = dnr_easy_data[dnr_set_easy].func(fx);
    fy = dnr_mmod_data[dnr_set_ymod].func(fy);

    fy *= dnr_set_kmult;
    fy += dnr_set_kshift;

    const double wide = dnr_set_otop - dnr_set_obottom;

    if (fy > dnr_set_otop) {
        fy = fmod(fy - dnr_set_obottom, wide) + dnr_set_obottom;
    }

    if (fy < dnr_set_obottom) {
        fy = fmod(fy - dnr_set_obottom, wide) + dnr_set_otop;
    }

    return fy;
}

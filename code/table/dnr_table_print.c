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

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "../table/dnr_table_print.h"
#include "../table/dnr_table_util.h"
#include "../easy/data/dnr_easy_data.h"
#include "../graph/data/dnr_mmod_data.h"
#include "../table/data/dnr_nmod_data.h"
#include "../args/dnr_args_process.h"

/*! \brief Prints the table values */
void dnr_table_print(void) {
    for (size_t x = 0; x < dnr_set_tcount; x++) {
        double fx = (double)x * (1.0 / (dnr_set_tcount - 1));
        fx = dnr_mmod_data[dnr_set_xmod].func(fx);

        double fy = dnr_easy_data[dnr_set_easy].func(fx);
        fy = dnr_mmod_data[dnr_set_ymod].func(fy);
        fy *= dnr_set_kmult;

        ///@todo Move to /core/ with map_plot
        const double wide = dnr_set_otop - dnr_set_obottom;
        if (fy >= dnr_set_otop) {
            fy = fmod(fy, wide) + dnr_set_obottom;
        }
        if (fy <= dnr_set_obottom) {
            fy = dnr_set_otop + fmod(fy, wide);
        }

        if (x % dnr_set_twidth == 0) {
            if (dnr_set_ffcell)
                 dnr_nmod_data[dnr_set_fnmod].func(dnr_set_ffcell, fy);
            else dnr_nmod_data[dnr_set_mnmod].func(dnr_set_fmcell, fy);

        } if (x % dnr_set_twidth == dnr_set_twidth - 1) {
            if (dnr_set_flcell)
                 dnr_nmod_data[dnr_set_lnmod].func(dnr_set_flcell, fy);
            else dnr_nmod_data[dnr_set_mnmod].func(dnr_set_fmcell, fy);

        } else {
            dnr_nmod_data[dnr_set_mnmod].func(dnr_set_fmcell, fy);
        }

        if (x % dnr_set_twidth == dnr_set_twidth - 1)
            printf("\n");
    }
    printf("\n");
}

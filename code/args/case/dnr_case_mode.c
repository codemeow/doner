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
#include <getopt.h>

#include "../../args/case/dnr_case_mode.h"
#include "../../args/dnr_args_vars.h"
#include "../../mode/data/dnr_mode_data.h"
#include "../../util/dnr_util_help.h"

/*! \brief Selects work mode for the program */
void dnr_args_mode(void) {
    dnr_set_mode = dnr_mode_name2list(optarg);
    if (dnr_set_mode == DNR_MODE_COUNT) {
        fprintf(stderr, "Unknown mode: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

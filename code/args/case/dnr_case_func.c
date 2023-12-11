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

#include "../../args/case/dnr_case_func.h"
#include "../../args/dnr_args_vars.h"
#include "../../mode/data/dnr_mode_data.h"
#include "../../easy/data/dnr_easy_data.h"
#include "../../graph/data/dnr_mmod_data.h"
#include "../../util/dnr_util_help.h"
#include "../../util/dnr_util_conv.h"

/*! \brief Processes easing selection */
static void _args_func_easy(void) {
    dnr_set_easy = dnr_easy_name2list(optarg);
    if (dnr_set_easy == DNR_EASY_COUNT) {
        fprintf(stderr, "Unknown easing: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes X-modifier selection */
static void _args_func_xmod(void) {
    dnr_set_xmod = dnr_mmod_name2list(optarg);
    if (dnr_set_xmod == DNR_MMOD_COUNT) {
        fprintf(stderr, "Unknown X modifier: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes Y-modifier selection */
static void _args_func_ymod(void) {
    dnr_set_ymod = dnr_mmod_name2list(optarg);
    if (dnr_set_ymod == DNR_MMOD_COUNT) {
        fprintf(stderr, "Unknown Y modifier: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes top overflow border selection */
static void _args_func_otop(void) {
    if (!dnr_set_dvalue(&dnr_set_otop, optarg)) {
        fprintf(stderr, "Bad value for top overflow border: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes bottom overflow border selection */
static void _args_func_obottom(void) {
    if (!dnr_set_dvalue(&dnr_set_obottom, optarg)) {
        fprintf(stderr, "Bad value for bottom overflow border: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes multiplying ratio for the function */
static void _args_func_kmult(void) {
    if (!dnr_set_dvalue(&dnr_set_kmult, optarg)) {
        fprintf(stderr, "Bad value for multiply ratio: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes shifting ratio for the function */
static void _args_func_kshift(void) {
    if (!dnr_set_dvalue(&dnr_set_kshift, optarg)) {
        fprintf(stderr, "Bad value for shift ratio: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes arguments meant for function-related things
 * \param[in] c Args-character */
void dnr_args_func(int c) {
    switch (c) {
        case 'e': _args_func_easy();
                  break;
        case 'x': _args_func_xmod();
                  break;
        case 'y': _args_func_ymod();
                  break;
        case 't': _args_func_otop();
                  break;
        case 'b': _args_func_obottom();
                  break;
        case 'K': _args_func_kmult();
                  break;
        case 'S': _args_func_kshift();
                  break;
    }
}



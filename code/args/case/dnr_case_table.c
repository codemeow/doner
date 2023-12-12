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

#include "../../args/case/dnr_case_table.h"
#include "../../args/dnr_args_vars.h"
#include "../../args/dnr_args_opts.h"
#include "../../mode/data/dnr_mode_data.h"
#include "../../util/dnr_util_help.h"
#include "../../util/dnr_util_conv.h"
#include "../../util/dnr_util_fmt.h"

/*! \brief Processes width of the table */
static void _args_table_twidth(void) {
    if (!dnr_set_svalue(&dnr_set_twidth, optarg)) {
        fprintf(stderr, "Bad value for table width: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes formatter for first cell of the table */
static void _args_table_ffcell(void) {
    if (!dnr_set_fmt(&dnr_set_fnmod, &dnr_set_ffcell, optarg)) {
        fprintf(stderr, "Bad value for first table cell formatter: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes formatter for middle cells of the table */
static void _args_table_fmcell(void) {
    if (!dnr_set_fmt(&dnr_set_mnmod, &dnr_set_fmcell, optarg)) {
        fprintf(stderr, "Bad value for middle table cells formatter: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes formatter for last cell of the table */
static void _args_table_flcell(void) {
    if (!dnr_set_fmt(&dnr_set_lnmod, &dnr_set_flcell, optarg)) {
        fprintf(stderr, "Bad value for last table cell formatter: %s\n", optarg);
        dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes number of elements of the table */
static void _args_table_tcount(void) {
    if (!dnr_set_svalue(&dnr_set_tcount, optarg)) {
         fprintf(stderr, "Bad value for table elements count: %s\n", optarg);
         dnr_util_help(EXIT_FAILURE);
    }
}

/*! \brief Processes arguments meant for table-related things
 * \param[in] c Args-character */
void dnr_args_table(int c) {
    switch (c) {
        case DNR_OPTC_TWDT : _args_table_twidth();
                             break;
        case DNR_OPTC_TCNT : _args_table_tcount();
                             break;

        case DNR_OPTC_FCLL : _args_table_ffcell();
                             break;
        case DNR_OPTC_MCLL : _args_table_fmcell();
                             break;
        case DNR_OPTC_LCLL : _args_table_flcell();
                             break;
    }
}

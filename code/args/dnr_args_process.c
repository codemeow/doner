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

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <stdbool.h>

#include "../args/dnr_args_process.h"
#include "../easy/data/dnr_easy_data.h"
#include "../mode/data/dnr_mode_data.h"
#include "../graph/data/dnr_mmod_data.h"
#include "../table/data/dnr_nmod_data.h"
#include "../table/dnr_table_util.h"

/*! \brief Selected work mode */
enum dnr_mode_list dnr_set_mode = DNR_MODE_GRAPH;
/*! \brief Selected easing */
enum dnr_easy_list dnr_set_easy = DNR_EASY_INSINE;
/*! \brief Selected X mod */
enum dnr_mmod_list dnr_set_xmod = DNR_MMOD_ORIG;
/*! \brief Selected Y mod */
enum dnr_mmod_list dnr_set_ymod = DNR_MMOD_ORIG;

/*! \brief Top overflow border */
double dnr_set_otop = DBL_MAX;
/*! \brief Bottom overflow border */
double dnr_set_obottom = -DBL_MAX;

/*! \brief Cell value multiplier */
double dnr_set_kmult = 1.0;

/*! \brief Print help and exit 
 * \param[in] code Exit code */
__attribute__((noreturn))
static void _args_help(int code) {
    // @todo Print help
    printf("Printing help\n");

    exit(code);
}

///@todo First cell, middle cell, last cell formatters

///@todo Conversion functions to one module

/*! \brief Converts string value to double
 * \param[out] Value to set
 * \param[in] str String to convert
 * \return True if the conversion was successfull */
static bool _set_dvalue(double * value, const char * str) {
    char * end = NULL;
    *value = strtod(str, &end);
    return end && *end == '\0';
}

/*! \brief Process input program arguments
 * \param[in] argc Number of arguments
 * \param[in] argv List of arguments */
void dnr_args_process(int argc, char * argv[]) {
    static struct option options[] = {
        { "help",       no_argument,        NULL, 'h'   },
        { "mode",       required_argument,  NULL, 'm'   },

        { "easy",       required_argument,  NULL, 'e'   },
        { "xmod",       required_argument,  NULL, 'x'   },
        { "ymod",       required_argument,  NULL, 'y'   },
        { "overtop",    required_argument,  NULL, 't'   },
        { "overbottom", required_argument,  NULL, 'b'   },

        { "fcell",      required_argument,  NULL, 'f'   },
        { "mcell",      required_argument,  NULL, 'c'   },
        { "lcell",      required_argument,  NULL, 'l'   },

        { "kmult",      required_argument,  NULL, 'k'   },
        { "width",      required_argument,  NULL, 'w'   },

        { NULL,         0,                  NULL, 0     }
    };

    while (1) {
        int c = getopt_long(argc, argv, "he:m:x:y:w:f:c:l:k:t:b:", options, NULL);
        if (c == -1)
            break;
        
        switch (c) {
            case 'h' :
                _args_help(EXIT_SUCCESS);
            
            case 'e' :
                dnr_set_easy = dnr_easy_name2list(optarg);
                if (dnr_set_easy == DNR_EASY_COUNT) {
                    fprintf(stderr, "Unknown easing: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'm' :
                dnr_set_mode = dnr_mode_name2list(optarg);
                if (dnr_set_mode == DNR_MODE_COUNT) {
                    fprintf(stderr, "Unknown mode: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'x' :
                dnr_set_xmod = dnr_mmod_name2list(optarg);
                if (dnr_set_xmod == DNR_MMOD_COUNT) {
                    fprintf(stderr, "Unknown X modifier: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'y' :
                dnr_set_ymod = dnr_mmod_name2list(optarg);
                if (dnr_set_ymod == DNR_MMOD_COUNT) {
                    fprintf(stderr, "Unknown Y modifier: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'w' :
                if (!dnr_table_setwidth(optarg)) {
                    fprintf(stderr, "Bad value for table width: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'f' :
                if (!dnr_table_setfcell(optarg)) {
                    fprintf(stderr, "Bad value for first table cell formatter: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;
            case 'c' :
                if (!dnr_table_setmcell(optarg)) {
                    fprintf(stderr, "Bad value for middle table cells formatter: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;
            case 'l' :
                if (!dnr_table_setlcell(optarg)) {
                    fprintf(stderr, "Bad value for last table cell formatter: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'k' :
                if (!_set_dvalue(&dnr_set_kmult, optarg)) {
                    fprintf(stderr, "Bad value for multiply ratio: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 't' :
                if (!_set_dvalue(&dnr_set_otop, optarg)) {
                    fprintf(stderr, "Bad value for top overflow border: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            case 'b' :
                if (!_set_dvalue(&dnr_set_obottom, optarg)) {
                    fprintf(stderr, "Bad value for bottom overflow border: %s\n", optarg);
                    _args_help(EXIT_FAILURE);
                }
                break;

            default :
                fprintf(stderr, "Unknown option: %s\n", optarg);
                _args_help(EXIT_FAILURE);
        }
    }

    dnr_mode_data[dnr_set_mode].func();
}

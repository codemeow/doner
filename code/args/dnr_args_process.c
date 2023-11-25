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
#include "../args/dnr_args_process.h"
#include "../easy/data/dnr_easy_data.h"
#include "../mode/data/dnr_mode_data.h"

/*! \brief Selected work mode */
enum dnr_mode_list dnr_set_mode = DNR_MODE_GRAPH;
/*! \brief Selected easing */
enum dnr_easy_list dnr_set_easy = DNR_EASY_INSINE;

/*! \brief Print help and exit 
 * \param[in] code Exit code */
__attribute__((noreturn))
static void _args_help(int code) {
    // @todo Print help
    printf("Printing help\n");

    exit(code);
}

/*! \brief Process input program arguments
 * \param[in] argc Number of arguments
 * \param[in] argv List of arguments */
void dnr_args_process(int argc, char * argv[]) {
    static struct option options[] = {
        { "help",   no_argument,        NULL, 'h'   },
        { "easy",   required_argument,  NULL, 'e'   },
        { "mode",   required_argument,  NULL, 'm'   },
        { NULL,     0,                  NULL, 0     }
    };

    while (1) {
        int c = getopt_long(argc, argv, "he:m:", options, NULL);
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

            default :
                fprintf(stderr, "Unknown option: %s\n", optarg);
                _args_help(EXIT_FAILURE);
        }
    }

    dnr_mode_data[dnr_set_mode].func();
}

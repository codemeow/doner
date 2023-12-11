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
#include "../util/dnr_util_help.h"

#include "../args/case/dnr_case_help.h"
#include "../args/case/dnr_case_mode.h"
#include "../args/case/dnr_case_func.h"
#include "../args/case/dnr_case_table.h"

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
        { "kmult",      required_argument,  NULL, 'K'   },
        { "kshift",     required_argument,  NULL, 'S'   },

        { "fcell",      required_argument,  NULL, 'f'   },
        { "mcell",      required_argument,  NULL, 'c'   },
        { "lcell",      required_argument,  NULL, 'l'   },
        { "width",      required_argument,  NULL, 'w'   },
        { "count",      required_argument,  NULL, 'n'   },

        { NULL,         0,                  NULL, 0     }
    };

    while (1) {
        int c = getopt_long(
            argc, 
            argv,
            "h" "m:" "e:x:y:t:b:K:S:" "f:c:l:w:n:", 
            options, 
            NULL
        );
        if (c == -1)
            break;
        
        switch (c) {
            case 'h' : dnr_args_help();
                       break;
            case 'm' : dnr_args_mode();
                       break;
            case 'e' :
            case 'x' :
            case 'y' :
            case 't' :
            case 'b' :
            case 'K' :
            case 'S' : dnr_args_func(c);
                       break;
            case 'w' :
            case 'f' :
            case 'c' :
            case 'l' :
            case 'n' : dnr_args_table(c);
                       break;

            default :
                fprintf(stderr, "Unknown option: %s\n", optarg);
                dnr_util_help(EXIT_FAILURE);
        }
    }
}

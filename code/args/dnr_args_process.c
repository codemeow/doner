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
#include "../args/dnr_args_opts.h"
#include "../util/dnr_util_help.h"

#include "../args/case/dnr_case_help.h"
#include "../args/case/dnr_case_mode.h"
#include "../args/case/dnr_case_func.h"
#include "../args/case/dnr_case_table.h"

/*! \brief Process input program arguments
 * \param[in] argc Number of arguments
 * \param[in] argv List of arguments */
void dnr_args_process(int argc, char * argv[]) {
    static struct option options_tbl[] = {
        /* Service */
        { DNR_OPTL_HELP, no_argument,        NULL, DNR_OPTC_HELP },
        /* Mode */
        { DNR_OPTL_MODE, required_argument,  NULL, DNR_OPTC_MODE },
        /* Global */
        { DNR_OPTL_EASY, required_argument,  NULL, DNR_OPTC_EASY },
        { DNR_OPTL_XMOD, required_argument,  NULL, DNR_OPTC_XMOD },
        { DNR_OPTL_YMOD, required_argument,  NULL, DNR_OPTC_YMOD },
        { DNR_OPTL_OTOP, required_argument,  NULL, DNR_OPTC_OTOP },
        { DNR_OPTL_OBOT, required_argument,  NULL, DNR_OPTC_OBOT },
        { DNR_OPTL_RMUL, required_argument,  NULL, DNR_OPTC_RMUL },
        { DNR_OPTL_RADD, required_argument,  NULL, DNR_OPTC_RADD },
        /* Table */
        { DNR_OPTL_FCLL, required_argument,  NULL, DNR_OPTC_FCLL },
        { DNR_OPTL_MCLL, required_argument,  NULL, DNR_OPTC_MCLL },
        { DNR_OPTL_LCLL, required_argument,  NULL, DNR_OPTC_LCLL },
        { DNR_OPTL_TWDT, required_argument,  NULL, DNR_OPTC_TWDT },
        { DNR_OPTL_TCNT, required_argument,  NULL, DNR_OPTC_TCNT },

        { NULL, 0, NULL, 0 }
    };

    static const char * options_fmt =
        /* Service */
        DNR_OPTS_HELP
        /* Mode */
        DNR_OPTS_MODE DNR_OPT_REQUIRED
        /* Global */
        DNR_OPTS_EASY DNR_OPT_REQUIRED
        DNR_OPTS_XMOD DNR_OPT_REQUIRED
        DNR_OPTS_YMOD DNR_OPT_REQUIRED
        DNR_OPTS_OTOP DNR_OPT_REQUIRED
        DNR_OPTS_OBOT DNR_OPT_REQUIRED
        DNR_OPTS_RMUL DNR_OPT_REQUIRED
        DNR_OPTS_RADD DNR_OPT_REQUIRED
        /* Table */
        DNR_OPTS_FCLL DNR_OPT_REQUIRED
        DNR_OPTS_MCLL DNR_OPT_REQUIRED
        DNR_OPTS_LCLL DNR_OPT_REQUIRED
        DNR_OPTS_TWDT DNR_OPT_REQUIRED
        DNR_OPTS_TCNT DNR_OPT_REQUIRED
    ;

    while (1) {
        int c = getopt_long(argc, argv, options_fmt, options_tbl, NULL);
        
        switch (c) {
            case DNR_OPTC_HELP : dnr_args_help();
                                 break;

            case DNR_OPTC_MODE : dnr_args_mode();
                                 break;

            case DNR_OPTC_EASY :
            case DNR_OPTC_XMOD :
            case DNR_OPTC_YMOD :
            case DNR_OPTC_OTOP :
            case DNR_OPTC_OBOT :
            case DNR_OPTC_RMUL :
            case DNR_OPTC_RADD : dnr_args_func(c);
                                 break;

            case DNR_OPTC_FCLL :
            case DNR_OPTC_MCLL :
            case DNR_OPTC_LCLL :
            case DNR_OPTC_TWDT :
            case DNR_OPTC_TCNT : dnr_args_table(c);
                                 break;

            case -1 :
                return;

            default :
                fprintf(stderr, "Unknown option: %s\n", optarg);
                dnr_util_help(EXIT_FAILURE);
        }
    }
}

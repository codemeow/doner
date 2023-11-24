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


/*! \note Great thanks to 
 *   - Andrey Sitnik (https://github.com/ai)
 *   - Ivan Soloviev (https://github.com/gosolivs)
 * for systematization of it at https://easings.net/ */

#include <stdlib.h>

#include "args/dnr_args_process.h"
#include "easy/dnr_easy_process.h"

/*! \brief Entry point
 * \param[in] argc Number of arguments
 * \param[in] argv List of arguments
 * \return Program exit code */
int main(int argc, char * argv[]) {
    dnr_args_process(argc, argv);
    dnr_easy_process();

    return EXIT_SUCCESS;
}

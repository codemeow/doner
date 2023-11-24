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

#include "../args/dnr_args_process.h"
#include "../easy/dnr_easy_process.h"
#include "../easy/mode/dnr_mode_help.h"
#include "../easy/mode/dnr_mode_table.h"

/*! \brief Executes the selected mode function */
void dnr_easy_process(void) {
    typedef void (* dnr_mode_call)(void);
    static const dnr_mode_call mode[] = {
        [DNR_MODE_HELP  ] = dnr_mode_help,
        [DNR_MODE_TABLE ] = dnr_mode_table
    };

    mode[dnr_set_mode]();
}

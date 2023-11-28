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

#include <string.h>

#include "../../mode/data/dnr_mode_data.h"
#include "../../mode/list/dnr_mode_xlist.h"
#include "../../mode/list/dnr_mode_list.h"
#include "../../util/dnr_util_size.h"

#include "../../mode/func/dnr_mode_graph.h"
#include "../../mode/func/dnr_mode_table.h"


#define DNR_X(X, x)                                     \
    [DNR_MODE_ ## X   ] = { dnr_mode_ ## x, #x,   },

/*! \brief Instance of modes' data */
const struct dnr_mode_data dnr_mode_data[] = {
    DNR_MODE_XLIST
};

#undef DNR_X

/*! \brief Find mode enum by provided mode list
 * \param[in] name Name to find ("graph", "table", etc)
 * \return Mode enum or dnr_mode_list::DNR_MODE_COUNT on fail */
enum dnr_mode_list dnr_mode_name2list(const char * name) {
    for (size_t i = 0; i < DNR_SIZE(dnr_mode_data); i++) {
        if (strcmp(dnr_mode_data[i].name, name) == 0)
            return i;
    }
    return DNR_MODE_COUNT;
}


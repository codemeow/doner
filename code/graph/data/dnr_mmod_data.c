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

#include <stddef.h>
#include <string.h>
#include "../../graph/data/dnr_mmod_data.h"
#include "../../util/dnr_util_size.h"

#include "../../graph/func/dnr_mmod_orig.h"
#include "../../graph/func/dnr_mmod_inv.h"

#define DNR_X(X, x)                            \
    [DNR_MMOD_ ## X] = { dnr_mmod_ ## x, #x },

/*! \brief Instance of mods' data */
const struct dnr_mmod_data dnr_mmod_data[] = {
    DNR_MMOD_XLIST
};

#undef DNR_X

/*! \brief Converts string name to mapmod element
 * \param[in] name String representation
 * \return Enum element or dnr_mapmod_list::DNR_MAPMOD_COUNT */
enum dnr_mmod_list dnr_mmod_name2list(const char * name) {
    for (size_t i = 0; i < DNR_SIZE(dnr_mmod_data); i++) {
        if (strcmp(dnr_mmod_data[i].name, name) == 0)
            return i;
    }
    return DNR_MMOD_COUNT;
}

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

#ifndef DNR_MMOD_LIST_H
#define DNR_MMOD_LIST_H

#include "../../mmod/list/dnr_mmod_xlist.h"

#define DNR_X(X, x) \
    DNR_MMOD_ ## X,

/*! \brief List of available graph mods */
enum dnr_mmod_list {
    DNR_MMOD_XLIST
    DNR_MMOD_COUNT
};

#undef DNR_X

#endif

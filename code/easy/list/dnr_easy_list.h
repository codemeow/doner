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

#ifndef DNR_EASY_LIST_H
#define DNR_EASY_LIST_H

#include "../../easy/list/dnr_easy_xlist.h"

#define DNR_X(X, x)         \
    DNR_EASY_IN ## X,       \
    DNR_EASY_OUT ## X,      \
    DNR_EASY_INOUT ## X,    

/*! \brief List of available easings */
enum dnr_easy_list {
    DNR_EASY_XLIST
    DNR_EASY_COUNT
};

#undef DNR_X

#endif

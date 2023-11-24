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

#include "../../easy/data/dnr_easy_data.h"
#include "../../easy/list/dnr_easy_xlist.h"
#include "../../easy/list/dnr_easy_list.h"

#include "../../easy/func/dnr_func_sine.h"
#include "../../easy/func/dnr_func_quad.h"
#include "../../easy/func/dnr_func_cubic.h"
#include "../../easy/func/dnr_func_quart.h"
#include "../../easy/func/dnr_func_quint.h"
#include "../../easy/func/dnr_func_expo.h"
#include "../../easy/func/dnr_func_circ.h"
#include "../../easy/func/dnr_func_back.h"
#include "../../easy/func/dnr_func_elastic.h"
#include "../../easy/func/dnr_func_bounce.h"

#define DNR_X(X, x)                                                 \
    [DNR_EASY_IN ## X   ] = { dnr_func_in ## x,       "in" #x,   }, \
    [DNR_EASY_OUT ## X  ] = { dnr_func_out ## x,      "out" #x,  }, \
    [DNR_EASY_INOUT ## X] = { dnr_func_inout ## x,    "inout" #x },

/*! \brief Instance of easings' data */
const struct dnr_easy_data dnr_easy_data[] = {
    DNR_EASY_XLIST
};

#undef DNR_X

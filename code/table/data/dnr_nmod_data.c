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

#include "../../table/data/dnr_nmod_data.h"
#include "../../table/list/dnr_nmod_xlist.h"
#include "../../table/list/dnr_nmod_list.h"

#include "../../table/func/dnr_nmod_u8.h"
#include "../../table/func/dnr_nmod_i8.h"
#include "../../table/func/dnr_nmod_u16.h"
#include "../../table/func/dnr_nmod_i16.h"
#include "../../table/func/dnr_nmod_u32.h"
#include "../../table/func/dnr_nmod_i32.h"
#include "../../table/func/dnr_nmod_u64.h"
#include "../../table/func/dnr_nmod_i64.h"
#include "../../table/func/dnr_nmod_f64.h"

#define DNR_X(X, x)                       \
    [DNR_NMOD_ ## X   ] = { dnr_nmod_ ## x },

/*! \brief Instance of numeric modes' data */
const struct dnr_nmod_data dnr_nmod_data[] = {
    DNR_NMOD_XLIST
};

#undef DNR_X


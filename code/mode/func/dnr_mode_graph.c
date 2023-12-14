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

#include <stdio.h>
#include "../../mode/func/dnr_mode_graph.h"
#include "../../util/dnr_util_term.h"
#include "../../graph/dnr_map_type.h"
#include "../../graph/dnr_map_show.h"
#include "../../graph/dnr_map_plot.h"
#include "../../graph/dnr_map_info.h"
#include "../../graph/dnr_map_util.h"


/*! \brief Show selected easing's graph */
void dnr_mode_graph(void) {
    unsigned short term_w;
    unsigned short term_h;

    dnr_util_term(&term_w, &term_h);

    struct dnr_map_type * map = dnr_map_alloc(
        dnr_map_termw2mapw(term_w),
        dnr_map_termh2maph(term_h)
    );

    dnr_map_plot(map);
    dnr_map_info(map);
    dnr_map_show(map);
    dnr_map_free(map);
}

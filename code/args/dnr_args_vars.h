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

#ifndef DNR_ARGS_VARS_H
#define DNR_ARGS_VARS_H

#include <stdlib.h>
#include <stdbool.h>

#include "../mode/list/dnr_mode_list.h"
#include "../easy/list/dnr_easy_list.h"
#include "../mmod/list/dnr_mmod_list.h"
#include "../table/list/dnr_nmod_list.h"

/*! \brief Selected work mode */
extern enum dnr_mode_list dnr_set_mode;
/*! \brief Selected easing */
extern enum dnr_easy_list dnr_set_easy;
/*! \brief Selected X mod */
extern enum dnr_mmod_list dnr_set_xmod;
/*! \brief Selected Y mod */
extern enum dnr_mmod_list dnr_set_ymod;
/*! \brief Selected numeric representation mode */
extern enum dnr_nmod_list dnr_set_nmod;

/*! \brief Top overflow border */
extern double dnr_set_otop;
/*! \brief Bottom overflow border */
extern double dnr_set_obottom;

/*! \brief Cell value multiplier */
extern double dnr_set_kmult;
/*! \brief Cell value shifter */
extern double dnr_set_kshift;

/*! \brief Number of elements in one line */
extern size_t dnr_set_twidth;
/*! \brief Number of elements in the table */
extern size_t dnr_set_tcount;

/*! \brief Printf-like formatting string for first cell rendering */
extern const char * dnr_set_ffcell;
/*! \brief Printf-like formatting string for middle cells rendering */
extern const char * dnr_set_fmcell;
/*! \brief Printf-like formatting string for last cell rendering */
extern const char * dnr_set_flcell;

/* !\ brief Cell type, according to format for the first cell */
extern enum dnr_nmod_list dnr_set_fnmod;
/* !\ brief Cell type, according to format for middle cells */
extern enum dnr_nmod_list dnr_set_mnmod;
/* !\ brief Cell type, according to format for the last cell */
extern enum dnr_nmod_list dnr_set_lnmod;

/*! \brief Difference between cells */
extern bool dnr_set_diff;

#endif

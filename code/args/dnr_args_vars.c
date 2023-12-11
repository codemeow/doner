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

#include <float.h>
#include "../args/dnr_args_vars.h"

/*! \brief Selected work mode */
enum dnr_mode_list dnr_set_mode = DNR_MODE_GRAPH;
/*! \brief Selected easing */
enum dnr_easy_list dnr_set_easy = DNR_EASY_INSINE;
/*! \brief Selected X mod */
enum dnr_mmod_list dnr_set_xmod = DNR_MMOD_ORIG;
/*! \brief Selected Y mod */
enum dnr_mmod_list dnr_set_ymod = DNR_MMOD_ORIG;

/*! \brief Top overflow border */
double dnr_set_otop = DBL_MAX;
/*! \brief Bottom overflow border */
double dnr_set_obottom = -DBL_MAX;

/*! \brief Cell value multiplier */
double dnr_set_kmult = 1.0;

/*! \brief Cell value shifter */
double dnr_set_kshift = 0.0;

/*! \brief Number of elements in one line */
size_t dnr_set_twidth = 16;

/*! \brief Number of elements in the table */
size_t dnr_set_tcount = 64;

/*! \brief Printf-like formatting string for first cell rendering */
const char * dnr_set_ffcell = NULL;

/*! \brief Printf-like formatting string for middle cells rendering */
const char * dnr_set_fmcell = "%8.2f ";

/*! \brief Printf-like formatting string for last cell rendering */
const char * dnr_set_flcell = NULL;

/* !\ brief Cell type, according to format for the first cell */
enum dnr_nmod_list dnr_set_fnmod = DNR_NMOD_F64;
/* !\ brief Cell type, according to format for middle cells */
enum dnr_nmod_list dnr_set_mnmod = DNR_NMOD_F64;
/* !\ brief Cell type, according to format for the last cell */
enum dnr_nmod_list dnr_set_lnmod = DNR_NMOD_F64;


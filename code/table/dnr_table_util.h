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

#ifndef DNR_TABLE_UTIL_H
#define DNR_TABLE_UTIL_H

#include <stdbool.h>
#include <stdlib.h>

#include "../table/list/dnr_nmod_list.h"

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

/*! \brief Sets the number of elements in one line
 * \param[in] value String value to parse
 * \return True if the value was successfully parsed */
bool dnr_table_setwidth(const char * value);

/*! \brief Sets the printf-like formatting string for first cell rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setfcell(const char * value);

/*! \brief Sets the printf-like formatting string for middle cells rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setmcell(const char * value);

/*! \brief Sets the printf-like formatting string for last cell rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setlcell(const char * value);

/*! \brief Sets the number of elements in the table
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setcount(const char * value);

#endif

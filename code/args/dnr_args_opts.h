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

#ifndef DNR_ARGS_OPTS_H
#define DNR_ARGS_OPTS_H

/*! \note Unfortunately we should use `define` directives as const values in C
 *  aren't really const and cannot be used in switch-case constructions
 * neither be compile-time merged */

/*! \brief "Required option value" flag for getopt */
#define DNR_OPT_REQUIRED ":"

/*! \brief Long option for help */
#define DNR_OPTL_HELP "help"
/*! \brief Short option for help */
#define DNR_OPTS_HELP "h"
/*! \brief Char option for help */
#define DNR_OPTC_HELP 'h'

/*! \brief Long option for mode */
#define DNR_OPTL_MODE "mode"
/*! \brief Short option for mode */
#define DNR_OPTS_MODE "m"
/*! \brief Char option for mode */
#define DNR_OPTC_MODE 'm'

/*! \brief Long option for easing  selection */
#define DNR_OPTL_EASY "easing"
/*! \brief Short option for easing selection */
#define DNR_OPTS_EASY "e"
/*! \brief Char option for easing selection */
#define DNR_OPTC_EASY 'e'

/*! \brief Long option for X-modifier */
#define DNR_OPTL_XMOD "x-mod"
/*! \brief Short option for X-modifier */
#define DNR_OPTS_XMOD "x"
/*! \brief Char option for X-modifier */
#define DNR_OPTC_XMOD 'x'

/*! \brief Long option for Y-modifier */
#define DNR_OPTL_YMOD "y-mod"
/*! \brief Short option for Y-modifier */
#define DNR_OPTS_YMOD "y"
/*! \brief Char option for Y-modifier */
#define DNR_OPTC_YMOD 'y'

/*! \brief Long option for top overflow border */
#define DNR_OPTL_OTOP "overflow-top"
/*! \brief Short option for top overflow border */
#define DNR_OPTS_OTOP "t"
/*! \brief Char option for top overflow border */
#define DNR_OPTC_OTOP 't'

/*! \brief Long option for bottom overflow border */
#define DNR_OPTL_OBOT "overflow-bottom"
/*! \brief Short option for bottom overflow border */
#define DNR_OPTS_OBOT "b"
/*! \brief Char option for bottom overflow border */
#define DNR_OPTC_OBOT 'b'

/*! \brief Long option for result multiplier ratio */
#define DNR_OPTL_RMUL "result-multiplier"
/*! \brief Short option for result multiplier ratio */
#define DNR_OPTS_RMUL "k"
/*! \brief Char option for result multiplier ratio */
#define DNR_OPTC_RMUL 'k'

/*! \brief Long option for result addend */
#define DNR_OPTL_RADD "result-addend"
/*! \brief Short option for result addend */
#define DNR_OPTS_RADD "a"
/*! \brief Char option for result addend */
#define DNR_OPTC_RADD 'a'

/*! \brief Long option for first cell formatter */
#define DNR_OPTL_FCLL "first-cell-fmt"
/*! \brief Short option for first cell formatter */
#define DNR_OPTS_FCLL "f"
/*! \brief Char option for first cell formatter */
#define DNR_OPTC_FCLL 'f'

/*! \brief Long option for middle cells formatter */
#define DNR_OPTL_MCLL "cell-fmt"
/*! \brief Short option for middle cells formatter */
#define DNR_OPTS_MCLL "c"
/*! \brief Char option for middle cells formatter */
#define DNR_OPTC_MCLL 'c'

/*! \brief Long option for last cell formatter */
#define DNR_OPTL_LCLL "last-cell-fmt"
/*! \brief Short option for last cell formatter */
#define DNR_OPTS_LCLL "l"
/*! \brief Char option for last cell formatter */
#define DNR_OPTC_LCLL 'l'

/*! \brief Long option for table width */
#define DNR_OPTL_TWDT "table-width"
/*! \brief Short option for table width */
#define DNR_OPTS_TWDT "w"
/*! \brief Char option for table width */
#define DNR_OPTC_TWDT 'w'

/*! \brief Long option for table's number of elements */
#define DNR_OPTL_TCNT "table-size"
/*! \brief Short option for table's number of elements */
#define DNR_OPTS_TCNT "s"
/*! \brief Char option for table's number of elements */
#define DNR_OPTC_TCNT 's'

/*! \brief Long option for "difference" mode.
 * In this mode:
 * - No actual values will be printed
 * - Instead the difference between values is shown
 *
 * This mode is useful for the cases when one wants to move the object
 * relatively and not by the absolute positioning. For instance when
 * there is two objects on different starting positions but the movement
 * should be the same.
 * Ex.L [0, 5, 18, 14] will convert into [0, 5, 13, -4] 
 *
 * The main principce of the calculation of this mode is
 * ~~~
 * round(A[n]) - round(A[n-1])
 * ~~~
 * 'thanks to https://github.com/truebluepl user */
#define DNR_OPTL_TDFF "difference"
/*! \brief Short option for diff mode */
#define DNR_OPTS_TDFF "d"
/*! \brief Char option for diff mode */
#define DNR_OPTC_TDFF 'd'

#endif

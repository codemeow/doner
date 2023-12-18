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

#include <stdlib.h>
#include <stdio.h>

#include "../util/dnr_util_help.h"
#include "../util/dnr_util_size.h"

static const char * dnr_help_string[] = {
    "DONER - Easing tables generator\n", 
    "HOW TO USE\n", 
    "\n", 
    "Help\n", 
    "\n", 
    "    `-h` or `--help` to print this text\n", 
    "\n", 
    "    Ex.:\n", 
    "        doner --help\n", 
    "\n", 
    "Mode\n", 
    "\n", 
    "    This program supports two modes: `graph` mode and `table` mode.\n", 
    "    The `graph` mode allows to see the resulting table values as a graph\n", 
    "    in the terminal. The UTF-8 Braille characters will be used so the terminal\n", 
    "    requires UTF-8 support. This does not apply to the `table` mode to work.\n", 
    "\n", 
    "    Graph also shows Y = 0 line as solid line and Y = 1 as dotted line for\n", 
    "    convinience. The size of the graph depends on the terminal size or defaults\n", 
    "    to 80x24 when the terminal size is not available. The graph also includes\n", 
    "    header with min and max values info.\n", 
    "\n", 
    "    `-m` or `--mode` to select mode\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          \"graph\" for graph mode\n", 
    "          \"table\" for table mode\n", 
    "\n", 
    "        Default value is \"graph\"\n", 
    "\n", 
    "    Ex.:\n", 
    "        doner -m graph\n", 
    "        doner --mode=table\n", 
    "\n", 
    "GENERAL OPTIONS\n", 
    "    These options are applicable for all modes\n", 
    "\n", 
    "Easing\n", 
    "\n", 
    "    Easing functions specify the rate of change of the value over time. In\n", 
    "    this program the generated function is plotted from 0.0 to 1.0 with the\n", 
    "    selected level of discretization. The Y values are *usually* 0..1 but some\n", 
    "    exceptions exist.\n", 
    "\n", 
    "    `-e xxx` or `--easy=xxx` to select easing function\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          \"insine\",    \"inquad\",    \"incubic\",    \"inquart\",      \"inquint\", \n", 
    "          \"inexpo\",    \"incirc\",    \"inback\",     \"inelastic\",    \"inbounce\",\n", 
    "          \"outsine\",   \"outquad\",   \"outcubic\",   \"outquart\",     \"outquint\", \n", 
    "          \"outexpo\",   \"outcirc\",   \"outback\",    \"outelastic\",   \"outbounce\",\n", 
    "          \"inoutsine\", \"inoutquad\", \"inoutcubic\", \"inoutquart\",   \"inoutquint\", \n", 
    "          \"inoutexpo\", \"inoutcirc\", \"inoutback\",  \"inoutelastic\", \"inoutbounce\"\n", 
    "\n", 
    "        Default value is \"insine\"\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -e outquart\n", 
    "        doner --easy=inoutquint\n", 
    "\n", 
    "X/Y Mods\n", 
    "\n", 
    "    There are two additional submodes for the function - inversion of X or Y\n", 
    "    values. These are added for the scenario when one needs to reverse the\n", 
    "    generated values instead of doing it in the processing code.\n", 
    "\n", 
    "    `-x xxx` or `--xmod=xxx` to select X modifier in `y = F(x)`\n", 
    "    `-y xxx` or `--ymod=xxx` to select Y modifier in `y = F(x)`\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          \"orig\" to keep the original values\n", 
    "          \"inv\" to invers selected value (multiply by -1)\n", 
    "\n", 
    "        Default values are \"orig\"\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -m graph -e inelastic\n", 
    "        doner -m graph -e inelastic -x orig\n", 
    "        doner -m graph -e inelastic -y orig\n", 
    "\n", 
    "⠀⠀⡆⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠁\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣾⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠙⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠊⠀⠀⠀⠑⠄⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀\n", 
    "⠈⠉⡏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠭⠭⠭⠝⠋⠉⠉⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⠀⠀⠄⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⡐⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "        doner -m graph -e inelastic -x inv\n", 
    "\n", 
    "⠀⠀⡆⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀\n", 
    "⠀⢁⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣾⢱⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⢄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠙⠊⠀⠀⠀⠀⠀⠀⠀⠔⠁⠀⠀⠈⠒⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠈⠉⡏⠉⠉⠍⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉⠉⠉⠉⠉⠛⠭⠭⠭⠝⠛⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉\n", 
    "⠀⠀⡇⠀⠀⢀⠀⠀⠀⠀⠀⡈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠄⠀⠀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠐⡀⠀⡐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠈⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "        doner -m graph -e inelastic -y inv\n", 
    "\n", 
    "⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠉⢂⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠄⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⠀⠀⠀⠀⠠⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡈⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀\n", 
    "⠀⠒⡗⠒⠓⠒⠒⠒⠓⠒⠒⠉⠉⠉⠉⠉⠉⠑⠒⠒⠓⠒⠒⠒⠓⠊⠉⠁⠁⠀⠀⠀⠉⠒⢄⠀⠁⠀⠀⠀⠕⠀⠀⠀⠁⠀⠀⠀⠁⠀⠀⠀⠁\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⠢⠤⠤⠊⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣴⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀\n", 
    "⠀⠀⡇⠀⠻⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀\n", 
    "⠐⠒⠗⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒\n", 
    "\n", 
    "        doner -m graph -e inelastic -y inv -x inv\n", 
    "\n", 
    "⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⢀⠊⠑⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠄⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠠⠀⠀⠀⠀⠈⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⡀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⢄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠁⠀⠀⠀⠁⠀⠀⠀⠑⠄⠀⠀⠁⠀⢀⠔⠋⠁⠀⠀⠁⠀⠉⠉⠓⠒⠒⠒⠓⠒⠒⠒⠉⠉⠉⠉⠉⠉⠑⠒⠓⠒⠒⠒⠓⠒⠒⠒⠃\n", 
    "⠀⠀⡇⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠈⠢⠤⠤⠒⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠐⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣴⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠐⡇⠀⠻⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠐⠒⠗⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒\n", 
    "\n", 
    "Overflow\n", 
    "\n", 
    "    When generating output values it is sometimes vital to fit in an interval,\n", 
    "    defined by limitations of the platform, limitations of the variable type or\n", 
    "    the DOM element size. There is a way to set these borders in the output.\n", 
    "    It is highly recommended to set both of the borders at once as the values\n", 
    "    will overflow on the other size and without set border the overflowed values\n", 
    "    will be too small or too high.\n", 
    "\n", 
    "    `-t xxx` or `--overflow-top=xxx` for the top overflow border\n", 
    "    `-b xxx` or `--overflow-bottom=xxx` for the bottom overflow border\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          Anything that could be parsed by libc's `strtod`. Some examples are:\n", 
    "          \"123.456\", \"1.23456e2\", \"0x453.34p-2\"\n", 
    "\n", 
    "        Default values are +MAX_DBL and -MAX_DBL respectively\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -m graph -e inback\n", 
    "\n", 
    "Easing:\n", 
    "    inback\n", 
    "Graph :\n", 
    "    Min:   -0.100\n", 
    "    Max:    1.000\n", 
    "\n", 
    "⠀⠀⡆⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠁\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠌⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠌⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠁⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⢀⣀⣇⣀⣈⣁⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣔⣊⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n", 
    "⠀⠀⡇⠀⠀⠉⠉⠉⠑⠒⠒⠢⠤⠤⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⡠⠤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠑⠒⠒⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "        doner -m graph -e inback -t 0.5 -b -0.5\n", 
    "\n", 
    "Easing:\n", 
    "    inback\n", 
    "Graph :\n", 
    "    Min:   -0.469\n", 
    "    Max:    0.499\n", 
    "\n", 
    "⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠊⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠌⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠔⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣿⢸⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠤⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⢀⣀⣇⣀⣈⣁⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣠⣔⣁⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀\n", 
    "⠀⠀⡇⠀⠀⠉⠉⠉⠒⠒⠢⠤⠤⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠤⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠒⠒⠒⠒⠒⠒⠒⠒⠒⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠂⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡐⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠁⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠁⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "    Some useful application of this mode is to fit the graph values into limited\n", 
    "    variable (using the table mode). For example, in NES the X could have values\n", 
    "    [0..255]. Imagine the following code:\n", 
    "\n", 
    "        lda table, x ; Load the value from our generated table\n", 
    "        clc          ; Clear overflow bit\n", 
    "        adc start_x  ; Add extracted value to the initial animation position\n", 
    "        sta player_x ; Write final value to the player X position\n", 
    "\n", 
    "    As the screen width is limited by 255 only one byte is provided to store\n", 
    "    the player position. This leads to the situation when the sum value could\n", 
    "    be bigger than 255 but will overflow to `N MOD 255`. This can also be used\n", 
    "    to make animation with negative direction. For example, the `inelastic`:\n", 
    "\n", 
    "        doner -m graph -e inelastic\n", 
    "\n", 
    "Easing:\n", 
    "    inelastic\n", 
    "Graph :\n", 
    "    Min:   -0.373\n", 
    "    Max:    1.000\n", 
    "\n", 
    "⠀⠀⡆⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀⠀⠀⠀⡀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠁\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣾⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠙⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠊⠀⠀⠀⠑⠄⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀\n", 
    "⠈⠉⡏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠭⠭⠭⠝⠋⠉⠉⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⠀⠀⠄⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⡐⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⠀⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "    Let's multiplicate the final values by 40 to make it produce values [0..40]:\n", 
    "\n", 
    "        doner -m graph -e inelastic -k 40\n", 
    "\n", 
    "Easing:\n", 
    "    inelastic\n", 
    "Graph :\n", 
    "    Min:  -47.684\n", 
    "    Max:  128.000\n", 
    "\n", 
    "⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠁\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣾⢱⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠤⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠙⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠔⠊⠀⠀⠀⠑⠄⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀\n", 
    "⠈⠉⡏⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠙⠛⠭⠭⠭⠝⠋⠉⠉⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉⠉⠉⠍⠉⠉⠉⠉\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⠀⠀⠄⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⡀⠀⡐⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠊⠀⠀⠀⠀⠀⠀⠀\n", 
    "\n", 
    "    As could be seen there are negative values that will prevent the correct\n", 
    "    convertation to [0..255] limits. Let's apply the borders:\n", 
    "\n", 
    "        doner -m graph -e inelastic -k 40 -b 0 -t 255\n", 
    "\n", 
    "Easing:\n", 
    "    inelastic\n", 
    "Graph :\n", 
    "    Min:    0.000\n", 
    "    Max:  254.987\n", 
    "\n", 
    "⠀⠀⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠈⡇⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠈⠉⠒⠒⠒⠒⠒⠊⠀⠀⠀⠀⠀⠀⠀⠀⢂⠀⠀⠀⠀⠀⠀⠂⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠡⠀⠀⠀⠀⡐⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠑⢄⣀⡐⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠂⠀⠀\n", 
    "⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀\n", 
    "⠀⠀⡇⠀⣴⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀\n", 
    "⠀⠀⡇⠀⠻⠜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠔⠒⠒⢄⠀⠀⠀⠀⠀⠀⠀⠀⠠⠀⠀⠀⠀\n", 
    "⠐⠒⠗⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠓⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠚⠓⠒⠒⠒⠒⠒⠓⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒⠒\n", 
    "\n", 
    "    Thus making generated values correctly overflow when summing with some\n", 
    "    starting position:\n", 
    "\n", 
    "        lda table, x ; Load value 250\n", 
    "        clc\n", 
    "        adc start_x  ; Add value 40. \n", 
    "        ; The resulting value will be (250 + 40) % 255 = 34\n", 
    "        ; On the screen this will look as -6 pixels from the starting point.\n", 
    "\n", 
    "Multiplier\n", 
    "\n", 
    "    As mentioned earlier, the resulting value can be multiplied for the case\n", 
    "    when it cannot be done (or undesirable) in the executing code. For example\n", 
    "    for the case when the platform cannot operate with floating values. The\n", 
    "    assigned value will multiply the input value:\n", 
    "\n", 
    "    y = F(x * k)\n", 
    "\n", 
    "    `-k xxx` or `--result-multiplier=xxx`to assign multiplier value\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          Anything that could be parsed by libc's `strtod`.\n", 
    "\n", 
    "        Default value is 1.0\n", 
    "\n", 
    "Addend\n", 
    "\n", 
    "    In some cases shifting the resulting value is required. This can be achieved\n", 
    "    width another option:\n", 
    "\n", 
    "    y = F (x) + a\n", 
    "\n", 
    "    `-a xxx` or `--result-addend=xxx` to assign shifting value\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          Anything that could be parsed by libc's `strtod`.\n", 
    "\n", 
    "        Default value is 0.0\n", 
    "\n", 
    "TABLE OPTIONS\n", 
    "    These options are specific for the `table` mode.\n", 
    "\n", 
    "Cell formatting\n", 
    "\n", 
    "    As the program could be used to generate output for a variety of platforms\n", 
    "    the output format isn't fixed and could be reassigned to meet the required\n", 
    "    standard.\n", 
    "\n", 
    "    `-f xxx` or `--first-cell-fmt=xxx` to set first cell's format\n", 
    "    `-c xxx` or `--cell-fmt=xxx` to set middle cells format\n", 
    "    `-l xxx` or `--last-cell-fmt` to set last cell's format\n", 
    "\n", 
    "    If the `-f` or `-l` are omitted, the `-c` formatter will be used instead for\n", 
    "    corner cases.\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          Formatter string for `printf`-function family. Some examples are:\n", 
    "          \"%4d, \", \"%8.0f\", \"%hhu\". The output value will be automatically\n", 
    "          converted to meet the desired output format. Floating values will\n", 
    "          be rounded (not truncated).\n", 
    "\n", 
    "        Default value values are \"%8.2f \"\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -m table -e inelastic\n", 
    "\n", 
    "    0.00     0.00    -0.00     0.00     0.00     0.00     0.00  <...>\n", 
    "   -0.01    -0.01    -0.01    -0.01    -0.00    -0.00     0.00  <...>\n", 
    "   -0.02    -0.02    -0.03    -0.04    -0.05    -0.05    -0.04  <...>\n", 
    "    0.05     0.05    -0.01    -0.09    -0.18    -0.26    -0.33  <...>\n", 
    "\n", 
    "        doner -m table -e insine \\\n", 
    "            -c \"%3hhu \" -k 100\n", 
    "\n", 
    "  0   0   0   0   0   0   1   1   2   2   3   3   4   4   5   6   7 \n", 
    "  8   8   9  10  11  12  13  15  16  17  19  20  22  23  25  27  28 \n", 
    " 30  30  32  34  36  38  40  42  44  46  48  50  52  54  57  59  61 \n", 
    " 63  63  66  68  71  73  75  78  80  83  85  88  90  93  95  98 100 \n", 
    "\n", 
    "        (6502 assembly format)\n", 
    "        doner -m table -e insine \\\n", 
    "            -f \"   .byte $%02x, \" -c \"$%02x, \" -l \"$%02x\" -k 255\n", 
    "\n", 
    "   .byte $00, $00, $00, $00, <...> $0b, $0d, $0f, $12\n", 
    "   .byte $14, $14, $17, $19, <...> $3c, $40, $44, $48\n", 
    "   .byte $4d, $4d, $52, $56, <...> $8b, $90, $96, $9c\n", 
    "   .byte $a2, $a2, $a8, $ae, <...> $ec, $f2, $f9, $ff\n", 
    "\n", 
    "        (C static constant format)\n", 
    "        doner -m table -e insine \\\n", 
    "            -f \"   [ %f, \" -c \"%f, \" -l \"%f ],\"\n", 
    "\n", 
    "   [ 0.000000, 0.000000, 0.000311, <...> 0.052073, 0.060307, 0.069126 ],\n", 
    "   [ 0.078524, 0.078524, 0.088494, <...> 0.250219, 0.266948, 0.284133 ],\n", 
    "   [ 0.301763, 0.301763, 0.319827, <...> 0.566116, 0.588713, 0.611565 ],\n", 
    "   [ 0.634659, 0.634659, 0.657980, <...> 0.950154, 0.975069, 1.000000 ],\n", 
    "\n", 
    "Table width\n", 
    "\n", 
    "    For the convinience the output table width can be adjusted with the \n", 
    "    following option:\n", 
    "\n", 
    "    `-w xxx` or `--table-width=xxx` to set output table width (in elements)\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "          Any possible integer value from 1 to UINT64_MAX\n", 
    "\n", 
    "        Default value is 16\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -m table -e insine -w 4\n", 
    "\n", 
    "    0.00     0.00     0.00     0.00     0.00 \n", 
    "    0.00     0.00     0.01     0.01     0.02 \n", 
    "    0.02     0.02     0.03     0.03     0.04 \n", 
    "<...>\n", 
    "    0.73     0.73     0.75     0.78     0.80 \n", 
    "    0.83     0.83     0.85     0.88     0.90 \n", 
    "    0.93     0.93     0.95     0.98     1.00 \n", 
    "\n", 
    "Table size\n", 
    "\n", 
    "    By default the table is produced for 64 values with the loop where input \n", 
    "    X values are 0..1 with the increment of 1/64. To change this there is an\n", 
    "    additional option:\n", 
    "\n", 
    "    `-s xxx` or `--table-size=xxx`\n", 
    "\n", 
    "        Allowed values:\n", 
    "\n", 
    "            Any possible integer value from 1 to UINT64_MAX\n", 
    "\n", 
    "        Default value is 64\n", 
    "\n", 
    "    Ex.:\n", 
    "\n", 
    "        doner -m table -e insine -w 4 -s 16\n", 
    "\n", 
    "    0.00     0.00     0.01     0.02     0.05 \n", 
    "    0.09     0.09     0.13     0.19     0.26 \n", 
    "    0.33     0.33     0.41     0.50     0.59 \n", 
    "    0.69     0.69     0.79     0.90     1.00 \n", 
    "\n", 
    "        doner -m table -e insine -w 6 -s 20 -c \"%f, \"\n", 
    "\n", 
    "0.000000, 0.000000, 0.003416, 0.013639, 0.030600, 0.054183, 0.084227, \n", 
    "0.120526, 0.120526, 0.162834, 0.210859, 0.264276, 0.322718, 0.385787, \n", 
    "0.453052, 0.453052, 0.524053, 0.598305, 0.675301, 0.754515, 0.835405, \n", 
    "0.917421, 0.917421, 1.000000, \n"
};

/*! \brief Print help and exit 
 * \param[in] code Exit code */
__attribute__((noreturn))
void dnr_util_help(int code) {
    for (size_t i = 0; i < DNR_SIZE(dnr_help_string); i++) {
        printf("%s", dnr_help_string[i]);
    }

    exit(code);
}

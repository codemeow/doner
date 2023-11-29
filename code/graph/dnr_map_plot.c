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

#include <stdbool.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>

#include "../graph/dnr_map_plot.h"
#include "../graph/dnr_map_pixel.h"
#include "../graph/data/dnr_mmod_data.h"
#include "../easy/data/dnr_easy_data.h"
#include "../args/dnr_args_process.h"
#include "../util/dnr_util_size.h"

/*! \brief Bottom X axis padding */
static const size_t dnr_map_axisx = 4;
/*! \brief Left Y axis padding */
static const size_t dnr_map_axisy = 2;
/*! \brief Both axises line paddings */
static const size_t dnr_map_axisp = 1;

/*! \brief Top limit of working zone */
static const double dnr_map_yt = 0.05;
/*! \brief Bottom limit of working zone */
static const double dnr_map_yb = 0.95;

/*! \brief Plots the function graph in the selected bitmap
 * \param[in] map Bitmap to use
 * \param[out] width Calculated width of the graph
 * \param[out] min Global minimum of the function
 * \param[out] max Global maximum of the function
 * \return Array of values of the width `width` */
static double * _map_plot(
    struct dnr_map_type * map, 
    size_t * width,
    double * min, 
    double * max
) {
    *width = map->width - dnr_map_axisy - dnr_map_axisp;
    *max = DBL_MIN;
    *min = DBL_MAX;
    double * yvalues = malloc(*width * sizeof(double));

    for (size_t x = 0; x < *width; x++) {
        double fx = (double)x * (1.0 / (*width - 1));
        fx = dnr_mmod_data[dnr_set_xmod].func(fx);

        yvalues[x] = dnr_easy_data[dnr_set_easy].func(fx);
        yvalues[x] = dnr_mmod_data[dnr_set_ymod].func(yvalues[x]);

        if (*max < yvalues[x])
            *max = yvalues[x];
        if (*min > yvalues[x])
            *min = yvalues[x];
    }

    return yvalues;
}

/*! \brief Plot the Y axis on the graph
 * \param[in] map Bitmap to use */
static void _map_axisy(struct dnr_map_type * map) {
    for (size_t y = dnr_map_axisp; y < map->height - dnr_map_axisp; y++)
        dnr_map_set(map, dnr_map_axisx, y, 1);
}

/*! \brief Draws 0 or 1 on the desired position
 * \param[in] map Bitmap to use
 * \param[in] px X position
 * \param[in] py Y position
 * \param[in] index 0 or 1 
 * \param[in] above Draw it above proveded Y? */
static void _map_char(
    struct dnr_map_type * map, 
    size_t px, 
    size_t py, 
    size_t index,
    bool   above
) {
    static const size_t pad = 2;
    static const unsigned char chars[2][6][4] = {
        {   { 0, 1, 1, 0 },
            { 1, 1, 0, 1 },
            { 1, 1, 0, 1 },
            { 1, 1, 0, 1 },
            { 1, 1, 0, 1 },
            { 0, 1, 1, 0 }},

        {   { 0, 1, 1, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 1, 0 },
            { 1, 1, 1, 1 }}
    };

    const size_t ch = DNR_SIZE(chars[0]);
    const size_t cw = DNR_SIZE(chars[0][0]);

    for (size_t y = 0; y < ch; y++) {
        for (size_t x = 0; x < cw; x++) {
            dnr_map_set(
                map, 
                px + cw + pad + x, 
                above ?
                    py - pad - ch + y :
                    py + pad +  1 + y, 
                chars[index][y][x]
            );
        }
    }
}

/*! \brief Plot the X axis on the graph
 * \param[in] map Bitmap to use
 * \param[in] min Global minimum of the function
 * \param[in] max Global maximum of the function
 * \param[out] map0 0-level of the axis in pixels */
void _map_axisx(
    struct dnr_map_type * map, 
    double min, 
    double max, 
    size_t * map0
) {
    const double mapmin = map->height * dnr_map_yt;
    const double mapmax = map->height * dnr_map_yb;
    const double height = mapmax - mapmin;
    size_t map1;

    *map0 = round((height * -min) / (max - min) + mapmin);
     map1 = round((height *  1.0) / (max - min) + *map0 );
    
    /* Note, that we invert the positions as the above plot's Y grows up
     * and screen Y grows down */
    for (size_t x = dnr_map_axisp; x < map->width - dnr_map_axisp; x++) {
        dnr_map_set(map, x, map->height - *map0, 1);
        if (x % 8 == 0)
            dnr_map_set(map, x, map->height - map1, 1);
    }

    _map_char(map, dnr_map_axisy, map->height - *map0, 0, true );
    _map_char(map, dnr_map_axisy, map->height - map1,  1, false);
}

/*! \brief Plots the graph, selected by args
 * \param[in] map Provided bitmap */
void dnr_map_plot(struct dnr_map_type * map) {
    const size_t mapmin  = map->height * dnr_map_yt;
    const size_t mapmax  = map->height * dnr_map_yb;
    const size_t mapwide = mapmax - mapmin;
    size_t       map0;

    size_t       plotwidth;
    double       plotmin;
    double       plotmax;

    double * yvalues = _map_plot(map, &plotwidth, &plotmin, &plotmax);

    _map_axisy(map);
    _map_axisx(map, plotmin, plotmax, &map0);

    for (size_t x = 0; x <= plotwidth; x++) {
        ssize_t y = round(yvalues[x] * (mapwide)/(plotmax - plotmin));
        dnr_map_set(map, x + dnr_map_axisy, map->height - y - map0, 1);
    }

    free(yvalues);
}

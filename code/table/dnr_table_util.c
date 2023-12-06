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
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

#include "../table/dnr_table_util.h"
#include "../util/dnr_util_platform.h"
#include "../util/dnr_util_size.h"

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

/*! \brief Sets the number of elements in one line
 * \param[in] value String value to parse
 * \return True if the value was successfully parsed */
bool dnr_table_setwidth(const char * value) {
    char * end = NULL;
    dnr_set_twidth = strtol(value, &end, 10);
    return end && *end == '\0';
}

static const char * _format_flag(const char * fmt) {
    if (!fmt)
        return NULL;

    while (
        *fmt == '#'  ||
        *fmt == '0'  ||
        *fmt == '-'  ||
        *fmt == ' '  ||
        *fmt == '+'  ||
        *fmt == '\'' ||
        *fmt == 'I'
    ) {
        fmt++;
    }

    return fmt;
}

static const char * _format_exp(const char * fmt) {
    while (*fmt != '\0' && *fmt != '%')
        fmt++;
    if (*fmt == '\0')
        return NULL;
    /* Skip first '%' */
    return fmt + 1;
}

static const char * _format_width(const char * fmt) {
    if (!fmt)
        return NULL;

    char * end = NULL;
    errno = 0;
    strtod(fmt, &end);
    if (errno != 0)
        return NULL;

    return end;
}

static const char * _format_type(
    const char * fmt, 
    enum dnr_nmod_list * mode,
    size_t * match
) {
    static const struct {
        const char * type;
        enum dnr_nmod_list mode;
    } table[] = {
        /* 8 bit */
        { "hhd",    DNR_NMOD_I8 },  { "hhi",    DNR_NMOD_I8 }, 
        { "hho",    DNR_NMOD_U8 },  { "hhu",    DNR_NMOD_U8 }, 
        { "hhx",    DNR_NMOD_U8 },  { "hhX",    DNR_NMOD_U8 },
        /* 16 bit */
        { "hd",     DNR_NMOD_I16 }, { "hi",     DNR_NMOD_I16 }, 
        { "ho",     DNR_NMOD_U16 }, { "hu",     DNR_NMOD_U16 }, 
        { "hx",     DNR_NMOD_U16 }, { "hX",     DNR_NMOD_U16 },
        /* 32 bit */
        { "d",      DNR_NMOD_I32 }, { "i",      DNR_NMOD_I32 }, 
        { "o",      DNR_NMOD_U32 }, { "u",      DNR_NMOD_U32 }, 
        { "x",      DNR_NMOD_U32 }, { "X",      DNR_NMOD_U32 },
#if defined(DNR_PLATFORM_NIX)
        /* long int => 64 bit */
        { "ld",     DNR_NMOD_I64 }, { "li",     DNR_NMOD_I64 }, 
        { "lo",     DNR_NMOD_U64 }, { "lu",     DNR_NMOD_U64 }, 
        { "lx",     DNR_NMOD_U64 }, { "lX",     DNR_NMOD_U64 },
#elif defined(DNR_PLATFORM_WIN)
        /* long int => 32 bit */
        { "ld",     DNR_NMOD_I32 }, { "li",     DNR_NMOD_I32 }, 
        { "lo",     DNR_NMOD_U32 }, { "lu",     DNR_NMOD_U32 }, 
        { "lx",     DNR_NMOD_U32 }, { "lX",     DNR_NMOD_U32 },
#else
#   error Unsupported platform. Provide required platform check and expand this table
#endif
        /* 64 bit */
        { "lld",    DNR_NMOD_I64 }, { "lli",    DNR_NMOD_I64 }, 
        { "llo",    DNR_NMOD_U64 }, { "llu",    DNR_NMOD_U64 }, 
        { "llx",    DNR_NMOD_U64 }, { "llX",    DNR_NMOD_U64 },
        { "qd",     DNR_NMOD_I64 }, { "qi",     DNR_NMOD_I64 }, 
        { "qo",     DNR_NMOD_U64 }, { "qu",     DNR_NMOD_U64 }, 
        { "qx",     DNR_NMOD_U64 }, { "qX",     DNR_NMOD_U64 },
        { "jd",     DNR_NMOD_I64 }, { "ji",     DNR_NMOD_I64 }, 
        { "jo",     DNR_NMOD_U64 }, { "ju",     DNR_NMOD_U64 }, 
        { "jx",     DNR_NMOD_U64 }, { "jX",     DNR_NMOD_U64 },
        { "zd",     DNR_NMOD_I64 }, { "zi",     DNR_NMOD_I64 }, 
        { "zo",     DNR_NMOD_U64 }, { "zu",     DNR_NMOD_U64 }, 
        { "zx",     DNR_NMOD_U64 }, { "zX",     DNR_NMOD_U64 },
        /* double */
        { "a",      DNR_NMOD_F64 }, { "A",      DNR_NMOD_F64 },
        { "e",      DNR_NMOD_F64 }, { "E",      DNR_NMOD_F64 },
        { "f",      DNR_NMOD_F64 }, { "F",      DNR_NMOD_F64 },
        { "g",      DNR_NMOD_F64 }, { "G",      DNR_NMOD_F64 },
        { "La",     DNR_NMOD_F64 }, { "LA",     DNR_NMOD_F64 },
        { "Le",     DNR_NMOD_F64 }, { "LE",     DNR_NMOD_F64 },
        { "Lf",     DNR_NMOD_F64 }, { "LF",     DNR_NMOD_F64 },
        { "Lg",     DNR_NMOD_F64 }, { "LG",     DNR_NMOD_F64 },
        /* Reject */
        { "%",      DNR_NMOD_COUNT }
    };

    if (!fmt)
        return NULL;

    for (size_t i = 0; i < DNR_SIZE(table); i++) {
        if (strncmp(fmt, table[i].type, strlen(table[i].type)) == 0) {
            if (table[i].mode != DNR_NMOD_COUNT) {
                 *mode  = table[i].mode;
                 *match = *match + 1;
            }
            
            return fmt + strlen(table[i].type);
        }
    }

    return NULL;
}

/*! \brief Parses the `fmt` string as printf-like one. Detects if
 * only one formatter value is present and assignes the type of the value
 * to the `mode` variable
 * \param[out] mode Resulting type
 * \param[in] fmt Formatter string
 * \return True is only one value is required and the type is 
 * successfully parsed */
bool dnr_format_parse(enum dnr_nmod_list * mode, const char * fmt) {
    size_t matches = 0;
    while (fmt) {
        fmt = _format_exp  (fmt);
        fmt = _format_flag (fmt);
        fmt = _format_width(fmt);
        fmt = _format_type (fmt, mode, &matches);
    }
    return matches == 1;
}

/*! \brief Sets the printf-like formatting string for first cell rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setfcell(const char * value) {
    dnr_set_ffcell = value;
    return dnr_format_parse(&dnr_set_fnmod, value);
}

/*! \brief Sets the printf-like formatting string for middle cells rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setmcell(const char * value) {
    dnr_set_fmcell = value;
    return dnr_format_parse(&dnr_set_mnmod, value);
}

/*! \brief Sets the printf-like formatting string for last cell rendering
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setlcell(const char * value) {
    dnr_set_flcell = value;
    return dnr_format_parse(&dnr_set_lnmod, value);
}

/*! \brief Sets the number of elements in the table
 * \param[in] value String value to parse
 * \return True if the value was successfully applied */
bool dnr_table_setcount(const char * value) {
    char * end = NULL;
    dnr_set_tcount = strtol(value, &end, 10);
    return end && *end == '\0';
}

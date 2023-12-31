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

#ifndef DNR_UTIL_PLATFORM_H
#define DNR_UTIL_PLATFORM_H

#if defined(__gnu_linux__)  || defined(__unix__) || defined(__unix) || \
    defined(TARGET_NIX)

#   define DNR_PLATFORM_NIX

#elif defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || \
    defined(__TOS_WIN__) || defined(__WINDOWS__) || \
    defined(TARGET_WIN)

#   define DNR_PLATFORM_WIN

#else
#   error Unsupported platform. Provide required platform check
#endif

#if defined(DNR_PLATFORM_NIX)
#   define PRIuz "zu"

#elif defined(DNR_PLATFORM_WIN)
#   define PRIuz "Iu"

#else
#   error Unsuported platform. Provide "size_t" printing fmt definition

#endif

#endif 

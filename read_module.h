/*
 * Copyright (c) 2025 [Afanasiev Mihaile]. All rights reserved.
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from
 * the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#ifndef READ_MODULE_H
#define READ_MODULE_H

#include "stddef.h"

#define EPSILON 1e-8

/*
    read input as pairs of floats from stdin.

    voltage - current - arrays to fill.
    max_length - maximum 
    
    return 1 if there is error in scanf.
    return 2 if there is more data in input than given max_length.
    return 0 on success
*/
int read_input(float *voltage, float *current, size_t max_length, size_t *read_length);

/*
    fill resistance from voltage and current arrays.

    length - length of both voltage and current arrays.

    return 1 if there was division on zero. [current[i] ~= 0]
    return 0 on success
*/
int calculate_resistance(float *resistance, float *voltage, float *current, size_t length);

#endif

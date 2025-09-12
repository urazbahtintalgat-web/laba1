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

#include "stdio.h"
#include "stddef.h"

#include "resistanse.h"

int read_input(float *voltage, float *current, size_t max_length, size_t *read_length)
{
    size_t i = 0;
    while (i < max_length)
    {
        if (fscanf(stdin, "%g%g", voltage + i, current + i) != 2)
        {
            if (ferror(stdin))
            {
                return 1;
            }
            *read_length = i;
            return 0;
        }
        i++;
    }
    return 2;
}

int calculate_resistance(float *resistance, float *voltage, float *current, size_t length)
{
    for (size_t i = 0; i < length; ++i)
    {
        if (current[i] < EPSILON)
        {
            return 1;
        }
        resistance[i] = voltage[i] / current[i];
    }
    return 0;
}


#include "stdio.h"
#include "stddef.h"

#include "read_module.h"

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


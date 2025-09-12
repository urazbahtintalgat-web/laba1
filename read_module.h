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

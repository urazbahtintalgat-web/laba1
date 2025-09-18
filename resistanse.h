#ifndef RESISTANCE_H
#define RESISTANCE_H

#include "stddef.h"

extern const float EPSILON;

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

int data_select(int M, float resistance[]);

float result(int K, float* resistance);

int check(int n, float* resistance, float resistance_final);


#endif // RESISTANCE_H

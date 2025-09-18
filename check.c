#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "resistanse.h"

int check(int n, float* resistance, float resistance_final)
{
    assert(resistance != NULL);

    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += fabs(resistance[i] - resistance_final);
    }
    return fabsf(sum / n) < 1e-2; // Так как число с плавающей точкой
}

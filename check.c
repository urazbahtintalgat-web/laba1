#include <stdio.h>
#include <math.h>
#include "resistanse.h"

int check(int n, float* resistance, float resistance_final) {
    assert(resistance != NULL);

    float sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += resistance[i];
    }
    return abs(sum / n) < EPSILON;
}

#include "resistanse.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

const float EPSILON = 1e-7;

int data_select(int M, float resistance[]) {
    assert(M > 0);
    assert(resistance);

    int K = M;
    float average = 0;
    for (int i = 0; i < M; i++) {
        average += resistance[i];
    }
    average /= M;
    for (int i = 0; i < M; i++) {
    // TODO: 0.03 лучше вынести в переменную, например, константную
        if (fabs(resistance[i] - average) / average > 0.03){
            K--;
            resistance[i] = -1;
        }
    }
    for (int i = 0; i < M - 1; i++){
        if (resistance[i] == -1){
            resistance[i] = resistance[i+1];
            resistance[i+1] = -1;
        }
    }
    return K;
}

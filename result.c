#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

float result(int K, float* resistance) {
    assert( resistance != NULL );


    float res_f_sum = 0,
          resistance_final = 0,
          dev_sum = 0,
          deviation = 0;

    // calculation resistance_final
    for (int i = 0; i < K; ++i) {
        res_f_sum += resistance[i];
    }
    if (K == 0) {
        printf("no valid data\n");
        exit(1);
    }
    resistance_final = res_f_sum / K;

    // calculation deviation
    for (int i = 0; i < K; ++i) {
        dev_sum += pow((resistance[i] - resistance_final), 2.0);
    }
    deviation = sqrt(dev_sum) / K;

    printf("resistance final: %lf; deviation = %lf\n", resistance_final, deviation);

    return resistance_final;
}

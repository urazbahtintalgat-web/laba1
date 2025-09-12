#include <stdio.h>
#include <math.h>


#define assert(expression) \
    expression ? (void)0 : printAssert(__FILE__, __LINE__, __func__, #expression)

void printAssert(const char* file, int line, const char* func, const char* expression) {
    fprintf(stderr, "%s:%d: %s: Assertoin %s failed\n", file, line, func, expression);
    abort();
}

float result(int K, float* resistance) {
    assert( resistance != NULL );


    float res_f_sum = 0,
          resistance_final = 0,
          dev_sum = 0,
          deviation = 0;

    // calculation resistance_final
    for (int i=0; i<K-1; ++i) {
        res_f_sum += resistance[i];
    }
    resistance_final = res_f_sum/K;
    
    // calculation deviation
    for (int i=0; i<K-1; ++i) {
        dev_sum += pow((resistance[i] - resistance_final), 2);
    }
    deviation = sqrt(dev_sum)/K;

    printf("%lf : %lf\n", resistance_final, deviation);

    return resistance_final;
}


int main(){
    // float resistance[3] = {1.2, 2.3, 3.4};
    // result(3, resistance);

    return 0;
}

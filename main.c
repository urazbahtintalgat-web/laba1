#include "stdio.h"

#include "read_module.h"


#define arraylength(V) (sizeof(V) / sizeof(*(V)))

int main()
{
    float V[100];
    float I[100];
    float R[100];
    size_t read_count = 0;

    if (read_input(V, I, arraylength(V), &read_count))
    {
        printf("Input error\n");
        return 1;
    }
    
    if (calculate_resistance(R, V, I, read_count))
    {
        printf("Initial processing error\n");
    }

    #error TODO

    return 0;
}

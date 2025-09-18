#include "stdio.h"
#include "resistanse.h"


#define arraylength(V) (sizeof(V) / sizeof(*(V)))

int main()
{
    float V[100];
    float I[100];
    float R[100];
    size_t cnt_read = 0;

    if (read_input(V, I, arraylength(V), &cnt_read))
    {
        printf("Input error\n");
        return 1;
    }
    //printf("Read %d rows\n", (int)cnt_read);

    if (calculate_resistance(R, V, I, cnt_read))
    {
        printf("Initial processing error\n");
    }

    int cnt_select = data_select(cnt_read, R);

    float resistance_final = result(cnt_select, R); // Это будет работать не корректно:(

    if (!check(cnt_select, R, resistance_final)) 
    {
        printf("Not slay\n");
    }

    // TODO: добавить функции толгата, амира и мои
    return 0;
}

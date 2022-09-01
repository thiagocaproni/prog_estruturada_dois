#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned int)time(NULL));

    float a = 100.0;
    for (int i=0;i<144;i++)
        printf("%.1f\n", ((float)rand()/(float)(RAND_MAX))*a);
    return 0;
}
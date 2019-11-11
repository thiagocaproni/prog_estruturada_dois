#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Vetor{
    float *x;
    float *y;
    float *z;
};

int main(){
    struct Vetor vet;
    float dist;
    int i;

    vet.x = malloc(2*sizeof(float));
    vet.y = malloc(2*sizeof(float));
    vet.z = malloc(2*sizeof(float));

    for(i=0; i<2;i++){
        scanf("%f", &vet.x[i]);
        scanf("%f", &vet.y[i]);
        scanf("%f", &vet.z[i]);
    }
    
    dist = sqrt( pow((vet.x[1] - vet.x[0]), 2) + 
                 pow((vet.y[1] - vet.y[0]),2) + 
                 pow((vet.z[1] - vet.z[0]),2)    );

    printf("\n A distancia dos dos pontos eh: %f", dist);
    
    free(vet.x);
    free(vet.y);
    free(vet.z);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
 
/* void somaNumeros(int *a, int *b, int *c){
    int i;
    for(i=0;i<3;i++, a++, b++, c++)
        *c = *a + *b;
}*/
/*void somaNumeros(int *a, int *b, int *c){
    int i;
    for(i=0;i<3;i++)
        c[i] = a[i] + b[i];
}*/

/* void somaNumeros(int *a, int *b, int *c){
    int i;
    for(i=0;i<3;i++)
        *(c+i) = *(a+i) + *(b+i); 
}*/

int* somaNumeros(int a[], int b[], int c[]){
    int i;
    for(i=0;i<3;i++)
        *(c+i) = *(a+i) + *(b+i);

    return c; 
}

int main(){ 
    int v1[] = {1, 2, 3};
    int v2[] = {1, 2, 3};
    int soma[3], i;
    somaNumeros(v1, v2, soma);

    for(i = 0; i<3;i++)
        printf("\nsoma[%d]: %d", i, soma[i]);


    return 0;
}
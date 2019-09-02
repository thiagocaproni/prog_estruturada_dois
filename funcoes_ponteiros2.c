#include <stdio.h>
#include <stdlib.h>

int* somaNumeros(int a[], int b[]){
    int i;
    int *c = malloc(3*sizeof(int));
    for(i=0;i<3;i++){
        c[i] = a[i] + b[i];
     }

    return c;
}

int main(){
    int v1[] = {1, 2, 3};
    int v2[] = {1, 2, 3};
    int i, *s;
    
    s = somaNumeros(v1, v2);

    for(i = 0; i<3;i++)
        printf("\nsoma[%d]: %d ", i, s[i]);

    return 0;
}
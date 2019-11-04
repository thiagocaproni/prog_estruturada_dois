#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void maior(int *v, int tam, int *m, int *cont);

int main(){
    int n, *v, i, m, cont=0;
    scanf("%d", &n);
    v = malloc(n*sizeof(int));
    if(v == NULL){
        printf("Erro de memoria!");
        return 1;
    }

    for(i=0; i<n; i++)
        scanf("%d", &v[i]);

    maior(v, n, &m, &cont);

    printf("O numero %d apareceu %d vezes\n", m, cont);

    return 0;
}

void maior(int *v, int tam, int *m, int *cont){
    int i;
    *m = v[0];
    for(i=1; i<tam; i++)
        if(v[i] > *m)
            *m = v[i];

    for(i=0; i<tam; i++)
        if(v[i] == *m)
            (*cont)++;
}
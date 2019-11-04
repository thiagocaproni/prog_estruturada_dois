#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maior(int *v, int tam, int *qtd);

int main(){
    int *v, i, n, qtd=0, m;
    
    scanf("%d", &n);
    v = malloc(n*sizeof(int));

    for(i=0; i < n;i++)
        scanf("%d",&v[i]);

    m = maior(v, n, &qtd);
    printf("Nro %d apareceu %d vezes. \n", m, qtd);
    return 0;
}

int maior(int *v, int tam, int *qtd){
    int i,m;
    m = v[0];
    for(i=1; i < tam;i++)
        if(v[i]>m)
            m = v[i];

    for(i=0; i < tam; i++)
        if(v[i] == m)
            *qtd = *qtd + 1;
    
    return m;
}
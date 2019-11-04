#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *calcula_situacao(float n1, float n2, float n3, float *media);

int main(){
    float n1, n2, n3, media;
    char *sit;
    scanf("%f%f%f", &n1, &n2, &n3);
    sit = calcula_situacao(n1, n2, n3, &media);
    printf("Aluno %s com media %.2f\n", sit, media);
    return 0;
}

char *calcula_situacao(float n1, float n2, float n3, float *media){
    char *sit = malloc(20*sizeof(12));
    *media = (n1+n2+n3)/3;
    if(*media >= 6)
        strcpy(sit, "aprovado");
    else if(*media < 4)
        strcpy(sit, "Reprovado");
    else
        strcpy(sit, "Recuperacao");
    
    return sit;
}
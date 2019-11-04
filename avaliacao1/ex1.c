#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *calcula_situacao(float n1, float n2, float n3, float *media);

int main(){
    float i, n1, n2, n3, media;
    int n;
    char *sit;

    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%f%f%f", &n1, &n2, &n3);
        sit = calcula_situacao(n1, n2, n3, &media);
        if(sit == NULL){
            printf("Erro de memoria!!!");
            return 1;
        }

        printf("O aluno foi %s com media %.2f", sit, media);
    }

    free(sit);
    return 0;
}

char *calcula_situacao(float n1, float n2, float n3, float *media){
    char *sit = malloc(12 * sizeof(char));
    if(sit == NULL)
        return NULL;
    *media = (n1+n2+n3) / 3;
    if(*media >= 6)
        strcpy(sit, "Aprovado");
    else if(*media < 4)
        strcpy(sit, "Reprovado");
    else 
        strcpy(sit, "Recuperacao");
    
    return sit;
}
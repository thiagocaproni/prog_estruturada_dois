#include <stdio.h>

typedef struct p{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

int main(){
    FILE *fp1;
    int i;
    Pessoa pessoas[3];

    for(i = 0; i<3; i++){
        scanf(" %50[0-9a-zA-Z ]", pessoas[i].nome);
        scanf("%d", &pessoas[i].idade);
        scanf("%f", &pessoas[i].altura);
    }

    fp1 = fopen("pessoas.txt", "w");
    if(fp1 == NULL ){
        printf("Nao foi possivel criar os arquvios!!!");
        return 1;
    }

    for(i = 0; i<3; i++){
        fprintf(fp1, "Nome: %s", pessoas[i].nome);
        fprintf(fp1, " Idade: %d", pessoas[i].idade);
        fprintf(fp1, " Altura: %f\n", pessoas[i].altura);   
    }

    fclose(fp1);
    return 0;
}
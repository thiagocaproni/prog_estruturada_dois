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

    fp1 = fopen("pessoas.dat", "wb");
    if(fp1 == NULL ){
        printf("Nao foi possivel criar os arquvios!!!");
        return 1;
    }

    for(i = 0; i<3; i++){
        //fprintf(fp1, "%s %d %f", pessoas[i].nome, pessoas[i].idade, pessoas[i].altura );
        fwrite(&pessoas[i], sizeof(Pessoa), 1, fp1);
    }

    fclose(fp1);
    return 0;
}
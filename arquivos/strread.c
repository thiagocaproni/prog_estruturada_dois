#include <stdio.h>

typedef struct p{
    char nome[50];
    int idade;
    float altura;
}Pessoa;

int main(){
    FILE *fp1;
    int i=0;
    Pessoa pessoas[3];

    fp1 = fopen("pessoas.dat", "rb");
    if(fp1 == NULL ){
        printf("Nao foi possivel criar os arquvios!!!");
        return 1;
    }

    if(fread(pessoas, sizeof(Pessoa), 3, fp1) == 3){
        for(i=0; i<3;i++){
            printf("\nNome: %s", pessoas[i].nome);
            printf("\nIdade: %d", pessoas[i].idade);
            printf("\nAltura: %f", pessoas[i].altura);    
        }
    }
    
    /*while(fread(&pessoas[i], sizeof(Pessoa), 1, fp1) == 1){
        printf("\nNome: %s", pessoas[i].nome);
        printf("\nIdade: %d", pessoas[i].idade);
        printf("\nAltura: %f", pessoas[i].altura);
        i++;
    }*/  

    fclose(fp1);
    return 0;
}
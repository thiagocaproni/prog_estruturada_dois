#include <stdio.h>
#include <string.h>

typedef struct pes{
    char nome[30];
    int idade;
    float altura;
}pessoa;

int main(int argc, char *argv[]){

    if(argc == 2){
        FILE *fb;
        int nr,i;
        pessoa vet[10];
        pessoa var;
        fb = fopen(argv[1],"rb+");

        nr = fread(vet, sizeof(pessoa), 10, fb);

        if(nr != 10){
            printf("Erro");
            return 1;
        }

        for(i=0; i<10;i++){
            printf("\nPessoa: %d", i);
            printf("\n\tNome: %s", vet[i].nome);
            printf("\n\tAltura: %f", vet[i].altura);
            printf("\n\tIdade: %d", vet[i].idade);
        }

        rewind(fb);
        strcpy(var.nome, "teste");
        var.altura = 1.9;
        var.idade = 25;

        fwrite(&var, sizeof(pessoa), 1, fb);

        fclose(fb);
    }
}
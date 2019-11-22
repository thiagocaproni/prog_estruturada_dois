#include <stdio.h>
#include <string.h>

typedef struct pes{
    char nome[30];
    int idade;
    float altura;
}pessoa;

int main(int argc, char *argv[]){

    if(argc == 2){
        FILE *fb = fopen(argv[1], "wb");
        int i, nw;
        if(fb == NULL){
            printf("Erro");
            return 1;
        }

        pessoa vet[10];

        for(i=0; i<10; i++){
            strcpy(vet[i].nome, "aaaaaa");
            vet[i].altura = 1.7 + i * 0.2;
            vet[i].idade = 18 + i;
        }

        nw = fwrite(vet, sizeof(pessoa), 10, fb);
        printf("\nGravado: %d bytes\n", nw);

        fclose(fb);
    }
}
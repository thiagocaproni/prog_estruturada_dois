#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fil{
    char nome[100];
    int ano;
    int duracao;
}Filme;

typedef struct dir{
    char nome[20];
    int  qtdFilmes;
    Filme *filmes;
}Diretor;

void recebe(Diretor *diretores, int tam);
void mostraDiretores(Diretor *diretores, int tam);
void mostraDiretor(Diretor *dir, int i);

int main(){
    int n, i;
    char nome[20];
    Diretor *diretores;

    scanf("%d", &n);
    diretores = malloc(n*sizeof(Diretor));

    recebe(diretores, n);

    do{
        scanf(" %20[0-9a-zA-Z ]", nome);
        if(strcmp(nome, "000") != 0) {
            for(i=0; i<n;i++){
                if(strcmp(nome, diretores[i].nome) == 0) {
                    mostraDiretor(&diretores[i], i);
                }
            }
        }
    }while(strcmp(nome, "OOO") != 0);

    //mostraDiretores(diretores, n);

    return 0;
}

void recebe(Diretor *diretores, int tam){
    int i, j;
    for(i=0; i<tam; i++){
        printf("\nNome do diretor %d: ", i+1);
        scanf(" %20[0-9a-zA-Z ]", diretores[i].nome);
        printf("\nQtd de Filmes: ");
        scanf("%d", &diretores[i].qtdFilmes);
        diretores[i].filmes = malloc(diretores[i].qtdFilmes * sizeof(Filme));
        for(j = 0; j < diretores[i].qtdFilmes; j++){
            printf("\nNome do Filme %d: ", j+1);
            scanf(" %100[0-9a-zA-Z ]", diretores[i].filmes[j].nome);
            printf("\nAno do Filme %d: ", j+1);
            scanf("%d", &diretores[i].filmes[j].ano);
            printf("\nDuracao do Filme %d: ", j+1);
            scanf("%d", &diretores[i].filmes[j].duracao);
        }
    }
}

void mostraDiretor(Diretor *dir, int i){
    int j;
    
    printf("\nNome do diretor %d: %s", i+1, dir->nome);
    printf("\nQtd de Filmes: %d", dir->qtdFilmes);

    for(j = 0; j < dir->qtdFilmes; j++){
        printf("\nNome do Filme %d: %s", j+1, dir->filmes[j].nome);
        printf("\nAno do Filme %d: %d", j+1, dir->filmes[j].ano);
        printf("\nDuracao do Filme %d: %d", j+1, dir->filmes[j].duracao);
    }
    printf("\n");
}

void mostraDiretores(Diretor *diretores, int tam){
    int i, j;
    for(i=0; i<tam; i++){
        printf("\nNome do diretor %d: %s", i+1, diretores[i].nome);
        printf("\nQtd de Filmes: %d", diretores[i].qtdFilmes);
        for(j = 0; j < diretores[i].qtdFilmes; j++){
            printf("\nNome do Filme %d: %s", j+1, diretores[i].filmes[j].nome);
            printf("\nAno do Filme %d: %d", j+1, diretores[i].filmes[j].ano);
            printf("\nDuracao do Filme %d: %d", j+1, diretores[i].filmes[j].duracao);
        }
        printf("\n");
    }
}
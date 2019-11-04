#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    float n1;
    float n2;
    float media;
}nota;

typedef struct al{
    char nome[100];
    char matricula[20];
    char codDisciplina[20];
    nota notas;
}aluno;

void recebe(aluno *alunos, int tam);
int calculaMedia(aluno *alunos, int tam);
void mostraAlunos(aluno *alunos, int tam);
void ordena(aluno *alunos, int tam);
void preecheVetores(aluno *alunos, int tam, aluno *apr, aluno *rep);

int main(){
    int n, capr;
    aluno *apr, *rep;
    scanf("%d", &n);

    aluno *alunos;
    alunos = malloc(n*sizeof(aluno));

    recebe(alunos, n);
    capr = calculaMedia(alunos, n);
    ordena(alunos, n);
    
    printf("\nTodos os alunos:");
    mostraAlunos(alunos, n);

    apr = malloc(capr*sizeof(aluno));
    rep = malloc((n-capr)*sizeof(aluno));

    if(apr == NULL || rep == NULL){
        printf("Erro de alocacao de memoria");
        return 1;
    }

    preecheVetores(alunos, n, apr, rep);

    printf("\nTodos os alunos aprovados:");
    mostraAlunos(apr, capr);

    printf("\nTodos os alunos reprovados:");
    mostraAlunos(rep, (n-capr));

    free(alunos);
    free(apr);
    free(rep);

    return 0;
}

void recebe(aluno *alunos, int tam){
    int i;
    for(i=0; i<tam; i++){
        scanf(" %100[0-9a-zA-Z ]", alunos[i].nome);
        scanf(" %20[0-9a-zA-Z ]", alunos[i].matricula);
        scanf(" %20[0-9a-zA-Z ]", alunos[i].codDisciplina);
        scanf("%f", &alunos[i].notas.n1);
        scanf("%f", &alunos[i].notas.n2);
    }
}

int calculaMedia(aluno *alunos, int tam){
    int i, cont = 0;
    for(i=0; i<tam; i++){
        alunos[i].notas.media = (alunos[i].notas.n1 + alunos[i].notas.n2) / 2.0;
        if(alunos[i].notas.media >= 6)
            cont++;
    }
    return cont;
}

void mostraAlunos(aluno *alunos, int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("\nNome: %s Media: %f", alunos[i].nome, alunos[i].notas.media);
    }
}

void ordena(aluno *alunos, int tam){
    int i, j;
    aluno aux;

    for(i=0; i<tam; i++){
        for(j=1; j<tam-i; j++){
            if(alunos[j-1].notas.media > alunos[j].notas.media){
                aux = alunos[j-1];
                alunos[j-1] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

void preecheVetores(aluno *alunos, int tam, aluno *apr, aluno *rep){
    int i, capr, crep;
    for(i=0, capr=0, crep =0; i < tam; i++){
        if(alunos[i].notas.media < 6){
            rep[crep] = alunos[i];
            crep++;
        }else{
            apr[capr] = alunos[i];
            capr++;
        }
    }
}
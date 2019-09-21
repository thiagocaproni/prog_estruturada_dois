#include <stdio.h>

int main(int argc, char *argv[]){

    printf("\nQtd de parametros: %d", argc);
    printf("\nNome programa: %s", argv[0]);
    printf("\nPrimeiro parametro: %s\n", argv[1]);

    return 0;
}
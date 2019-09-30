
#include <stdio.h>
#include <stdlib.h>

int soma(int x, int y);

int main(int argc, char *argv[]){
    int a, b;

    if(argc != 3){
        printf("Qtd de parametros invalida!\n");
        return 0;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    printf("%d\n", soma(a,b));

    return 0;
}

int soma(int x, int y){
    return (x+y);
}
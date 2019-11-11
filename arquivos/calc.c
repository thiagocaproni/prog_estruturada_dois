#include <stdio.h>

float calc(float n1, char op, float n2);

int main(){
    FILE *fp1;
    FILE *fp2;
    float n1, n2, res;
    int erro;
    char op;

    fp1 = fopen("calc.in", "r");
    fp2 = fopen("calc.res", "w");

    if(fp1 == NULL || fp2 == NULL){
        printf("Nao foi possivel abrir ou criar os arquvios!!!");
        return 1;
    }

    while(!feof(fp1)){
        erro = fscanf(fp1, "%f %c %f", &n1, &op, &n2);
        if(erro != EOF){
            res = calc(n1, op, n2);
            fprintf(fp2, "%.2f\n", res);
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}

float calc(float n1, char op, float n2){
    float res;
    switch (op)
    {
        case '+': res = n1 + n2;
                break;
        case '/': res = n1 / n2;
                break;
        case '*': res = n1 * n2;
                break;
        case '-': res = n1 - n2;
                break;
    }
    return res;
}
#include <stdio.h>

const int MAXLIN=12;
const int MAXCOL=12;

void lerMatriz(float m[][MAXCOL]){
    int i, j;
    for(i=0; i<MAXLIN; i++)
        for(j=0; j<MAXCOL; j++)
            scanf("%f", &m[i][j]);
}

float soma(float m[][MAXCOL], int l){
    int j;
    float soma=0;
    for(j=0; j<MAXCOL; j++)
        soma = soma + m[l][j];
    return soma;
}

int main() {
    float mat[MAXLIN][MAXCOL];
    int l;
    char op;
    scanf("%d ", &l);
    scanf("%c", &op);

    lerMatriz(mat);
    
    switch (op)
    {
        case 'S':
                printf("%.1f", soma(mat, l));
            break;
        case 'M':
                printf("%.1f", soma(mat, l)/MAXCOL);
            break;
        default:
            break;
    }
    
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct p{
    float x;
    float y;
}Ponto;

typedef struct tri{
    Ponto *pontos;
}Triangulo;

float calcDist(Ponto a, Ponto b);
void classificaTriangulo(Triangulo tr);

int main(){
    Triangulo triangulo;
    
    triangulo.pontos = malloc(3*sizeof(Ponto));

    scanf("%f %f", &triangulo.pontos[0].x, &triangulo.pontos[0].y);
    scanf("%f %f", &triangulo.pontos[1].x, &triangulo.pontos[1].y);
    scanf("%f %f", &triangulo.pontos[2].x, &triangulo.pontos[2].y);

    classificaTriangulo(triangulo);

    return 0;
}

float calcDist(Ponto a, Ponto b){
    return sqrt( pow(b.x-a.x, 2) + pow(b.y-a.y, 2) );
}

void classificaTriangulo(Triangulo tr){
    float d1, d2, d3;
    d1 = calcDist(tr.pontos[0], tr.pontos[1]);
    d2 = calcDist(tr.pontos[0], tr.pontos[2]);
    d3 = calcDist(tr.pontos[1], tr.pontos[2]);

    if(d1 == d2 && d2 == d3){
        printf("Equilatero: %.2f %.2f %.2f", d1, d2, d3);
    }else if(d1 == d2 || d1==d3 || d2==d3){
        printf("Isosceles: %.2f %.2f %.2f", d1, d2, d3);
    }else{
        printf("Escaleno: %.2f %.2f %.2f", d1, d2, d3);
    }
}
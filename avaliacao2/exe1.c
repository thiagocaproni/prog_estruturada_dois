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
    Triangulo t;

	t.pontos = malloc(3 * sizeof(Ponto));
	scanf("%f %f", &t.pontos[0].x, &t.pontos[0].y);
	scanf("%f %f", &t.pontos[1].x, &t.pontos[1].y);
	scanf("%f %f", &t.pontos[2].x, &t.pontos[2].y);
	
	classificaTriangulo(t);

    return 0;
}

float calcDist(Ponto a, Ponto b){
    return sqrt( pow(a.x-b.x, 2) + pow(a.y-b.y, 2)  );
}

void classificaTriangulo(Triangulo tr){
    float distA, distB, distC;

    distA = calcDist(tr.pontos[0], tr.pontos[1]);
    distB = calcDist(tr.pontos[0], tr.pontos[2]);
    distC = calcDist(tr.pontos[1], tr.pontos[2]);

    if(distA == distB && distB == distC){
        printf("Equilatero: %.2f %.2f %.2f",distA,distB,distC);
    }else if(distA == distB || distA == distC || distC == distB){
        printf("Isosceles: %.2f %.2f %.2f",distA,distB,distC);
    }else{
        printf("Escaleno: %.2f %.2f %.2f",distA,distB,distC);
    }
}
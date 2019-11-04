#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct r{
    double x1;
    double x2;
}raizes;

typedef struct coef{
    double a;
    double b;
    double c;
}coeficientes;

/*
raizes calcula2Grau(coeficientes *coef){
    raizes res;
    double delta;
    delta = pow(coef->b, 2) - (4*coef->a*coef->c);
    res.x1 = ((-coef->b) + sqrt(delta)) / (2*coef->a);
    res.x2 = ((-coef->b) - sqrt(delta)) / (2*coef->a);  

    return res; 
}

raizes calcula2Grau(coeficientes coef){
    raizes res;
    double delta;
    delta = pow(coef.b, 2) - (4*coef.a*coef.c);
    res.x1 = ((-coef.b) + sqrt(delta)) / (2*coef.a);
    res.x2 = ((-coef.b) - sqrt(delta)) / (2*coef.a);  

    return res; 
}*/

raizes* calcula2Grau(coeficientes coef){
    raizes r;
    raizes *res = malloc(sizeof(raizes));
    raizes **vet = malloc(10*sizeof(raizes *));
   
    double delta;

    vet[0] = &r;
    vet[0]->x1 = 10;

    delta = pow(coef.b, 2) - (4*coef.a*coef.c);
    res->x1 = ((-coef.b) + sqrt(delta)) / (2*coef.a);
    res->x2 = ((-coef.b) - sqrt(delta)) / (2*coef.a);  

    return res; 
}

int main()
{
    coeficientes cf;
    raizes *r;

    scanf("%lf %lf %lf", &cf.a, &cf.b, &cf.c);
    r = calcula2Grau(cf);

    printf("x1: %lf x2: %lf", r->x1, r->x2);

    return 0;
}
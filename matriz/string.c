#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bit 100

int main(){

    char bits[bit] = {0};
    int contador = 0;

    fgets(bits,sizeof(bits), stdin);
    //bits[strlen(bits)-1] = '\0';
    

    for (int i = 0; i < bit; i++)
    {
        if(bits[i] == '1') contador++; 
    }
    
    if (contador % 2 == 0)
    {
        bits[strlen(bits)] = '0';
        printf("%s", bits);
    }
    else
    {
        bits[strlen(bits)] = '1';
        printf ("%s", bits);
    }
    return 0;
}
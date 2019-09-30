#include <stdio.h>

void count(int n);

int main(){
    count(8)
    return 0;
}

void count(int n){
    if(n == 1){
        printf("%d ", n);
    }
    
    count(n-1);
    printf("%d ", n);    
}

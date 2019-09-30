#include <stdio.h>

int fat(int n);

int main(){
    int x, res;
    scanf("%d", &x);
    res = fat(x);
    printf("%d\n", res);
    return 0;
}

int fat(int n){
    int vfat, i;
    if(n == 0){
        return 1;
    }else{
        vfat=1;
        for(i = n; i > 1; i--)
            vfat = vfat * i;
    }
    return vfat;
}

int fat(int n){
    if(n<=1)
        return 1;
    return n * fat(n - 1);
}
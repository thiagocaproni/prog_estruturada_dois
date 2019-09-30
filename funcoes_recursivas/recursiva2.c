#include <stdio.h>
 
int f1(int m, int n)
{
    if(n == 0)
        return 0;
    else
        return (m + f1(m,n-1));
}
 
int main()
{
    printf("Soma: %d\n", f1(3,3));
}
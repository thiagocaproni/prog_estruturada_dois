#include <stdio.h>
#include <stdlib.h>

void converteBinario(int n){
	if(n !=0){
		converteBinario(n/2);
		printf("%d", n%2);
	}
	
	
}

int main(){
	int n;
	scanf("%d",&n);
	converteBinario(n);
	
	return 0;
	
}
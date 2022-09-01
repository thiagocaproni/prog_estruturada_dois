#include <stdio.h>


int main() {
 
	float m[4][5];
	int i, j, count=0;
	
    for(i = 0; i < 4; ++i)
		for(j = 0; j < 5; ++j)
			scanf("%f",&m[i][j]);
    
 	for(i = 0; i < 4; ++i)
		for(j = 0; j < 5; ++j)
			if(m[i][j] >10)
                count++;

    printf("%d",count);
	return 0;
}

#include <stdio.h>

#define MAX 12

float soma(float m[][MAX]);
float media(float m[][MAX]);
void compor(float m[][MAX]);

int main() {
 
	float m[MAX][MAX];
	char c;
	
	
	scanf("%c", &c);
	switch(c){
		case 'S': compor(m);
			  printf("%.1f\n", soma(m));
			  break;
		case 'M': compor(m);
			  printf("%.1f\n", media(m));
			  break;
	}

  
 		
	return 0;
}

void compor(float m[][MAX]){
	int i, j;
	for(i = 0; i < MAX; ++i)
		for(j = 0; j < MAX; ++j)
			scanf("%f",&m[i][j]);

}

float soma(float m[][MAX]){
	int i, j;
	float s = 0.0;
	for(i = 0; i < MAX; ++i)
		for(j = i+1; j < MAX; ++j)
			s += m[i][j];
	return s;
}

float media(float m[][MAX]){

	int i, j, qtd = 0;
	float s = 0.0;
	for(i = 0; i < MAX; ++i)
		for(j = i+1; j < MAX; ++j){
			s += m[i][j];
			qtd++;
		}
	return s/qtd;
}
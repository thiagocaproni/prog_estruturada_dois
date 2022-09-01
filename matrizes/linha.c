#include <stdio.h>
#include <ctype.h>

#define MAX 12

float soma(float m[][MAX], int l);
float media(float m[][MAX], int l);
void compor(float m[][MAX]);

int main() {
 
	float m[MAX][MAX];
	int l;
	char c;
	
	scanf("%d\n", &l);
	fflush(stdin);
	if(l >= 0 && l < MAX){
		scanf("%c", &c);
		switch(c){
			case 'S': compor(m);
				  printf("%.1f\n", soma(m, l));
				  break;
			case 'M': compor(m);
				  printf("%.1f\n", media(m, l));
				  break;
		}

	}   
 		
	return 0;
}

void compor(float m[][MAX]){
	int i, j;
	for(i = 0; i < MAX; ++i)
		for(j = 0; j < MAX; ++j)
			scanf("%f",&m[i][j]);

}

float soma(float m[][MAX], int l){
	int j;
	float s = 0.0;
	for(j = 0; j < MAX; ++j){
		s += m[l][j];
 	}
	return s;
}

float media(float m[][MAX], int l){

	int j;
	float s = 0.0;
	for(j = 0; j < MAX; ++j){
		s += m[l][j];
 	}
	return s/MAX;
}
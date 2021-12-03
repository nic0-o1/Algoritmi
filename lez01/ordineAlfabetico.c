#include <stdio.h>
#include <ctype.h>

int main(void){
	char c1,c2;	
	
	printf("Inserisci primo carettere: ");
	scanf("%c %c", &c1, &c2);
	
	//printf("Inserisci secondo carettere: ");
	//scanf("%c", &c2);
	
	if(c1 > c2){
		printf("Distanza: %d", c1-c2) +1;
	}else{
		printf("Distanza: %d", c2-c1) +1;
	}
	
	return 0;
}

#include <stdio.h>

int main(void){
	
	int hh,mm;	
	
	printf("Inserisci l'ora nel formato 24H");
	printf("Ore: ");
	scanf("%d", &hh);
	
	printf("\nMinuti: ");
	scanf("%d", &mm);
	
	if(hh > 12){
		printf("Ore formato AM: %d:%d", hh-12,mm);
	}		
		
	return 0;
}

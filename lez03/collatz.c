#include <stdio.h>
	
int CollatzSuccessivo(int n){
	if( n % 2 == 0)
		return n/2;
		
	return (n * 3)+1;
}

void EstraiSequenza(int n){
	int next = n;
	int lun = 1;
	
	printf("%d ",n);
	do{
		next = CollatzSuccessivo(next);
		printf("%d ",next);
		lun++;
	}while(next != 1);
	
	printf("\nLunghezza: %d", lun);
}
	
int main(void){
	int n;
	
	printf("Inserisci un numero: ");
	scanf("%d", &n);
	
	EstraiSequenza(n);
	
}



#include <stdio.h>

int main(void){
	
	int num,tot;
	int primo = 1;
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	
	printf("Divisori: ");
	printf("%d ",num);
	for(int i = num -1; i>1; i--){
		if(num%i == 0){
			printf("%d ",i);
			tot++;
			primo = 0;
		}
	
	}
	printf("%d",1);
	printf("\nTotale divisori: %d",tot+2);
	printf("\nPrimo: %s", primo == 1 ? "si" : "no");
	return 0;
}

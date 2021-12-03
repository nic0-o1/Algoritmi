#include <stdio.h>
	
int PotenzaRicorsiva(int b, int e){
	if(e == 1)
		return b;
		
	return b * PotenzaRicorsiva(b,e-1);
}
	
int main(void){
	int b,e;
	
	printf("Inserisci la base: ");
	scanf("%d",&b);
	
	printf("Inserisci l'esponente: ");
	scanf("%d", &e);
	
	printf("%d\n", PotenzaRicorsiva(b,e));
       
        return 0;
}



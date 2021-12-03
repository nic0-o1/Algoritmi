#include <stdio.h>


int main(void){

	int hhIn,mmIn,ssIn;
	int hhFin,mmFin,ssFin;
	
	int hhTot,mmTot,ssTot;
	
	printf("ORARIO INIZIALE \n");
	
	printf("Inserisci l'ora: ");
	scanf("%d", &hhIn);
	
	printf("\nInserisci i minuti: ");
	scanf("%d", &mmIn);
	
	printf("\nInserisci i secondi: ");
	scanf("%d", &ssIn);
	
	
	printf("ORARIO FINALE\n");
	
	printf("Inserisci l'ora: ");
	scanf("%d", &hhFin);
	
	printf("\nInserisci i minuti: ");
	scanf("%d", &mmFin);
	
	printf("\nInserisci i secondi: ");
	scanf("%d", &ssFin);
	
	//secondi
	ssTot = ssIn -ssFin;
	//ore
	hhTot= hhIn - hhFin;
	//minuti
	mmTot= mmIn -mmFin;
	
	if(hhIn < hhFin)
		hhTot += 24;	
	
	if(ssTot < 0){
		mmTot --;
		ssTot +=60;
		}
	else if(ssTot >60){
		mmTot ++;
		ssTot -= 60;
	}
	
	
	
	if(mmTot < 0){
		hhTot --;
		mmTot +=60;
		}
	else if(mmTot >60){
		hhTot ++;
		mmTot -= 60;
	}
	
	if(hhTot< 0)
		hhTot+= 24;
	
	
	printf("\n\nIntervallo di tempo: \nOre: %d \nMinuti:%d:\nSecondi:%d\n", hhTot, mmTot,ssTot);
	
	
		
	
	
	return 0;
}

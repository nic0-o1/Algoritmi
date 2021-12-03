#include <stdio.h>


typedef struct {
	int dd;
	int mm;
	int yy;
	} Data;

int main(void){
	Data date[100];
	Data confronto;
	int dateTot, i,tmp;
	
	
	do {
		printf("Inserisci una data separata da /(Termina con 00/00/0000): ");
		scanf("%d/%d/%d", &date[dateTot].dd,&date[dateTot].mm,&date[dateTot].yy);	
		dateTot++;
		
	} while(date[dateTot-1].dd != 00);	
	
	printf("Inserici la data da confrontare: ");
	scanf("%d/%d/%d", &confronto.dd,&confronto.mm,&confronto.yy);
	
	
	while(date[i].dd != 00) {
		if (date[i].yy < confronto.yy || (date[i].yy == confronto.yy && date[i].mm < confronto.mm) || (date[i].yy == confronto.yy && date[i].mm == confronto.mm && date[i].dd < confronto.dd)){
			printf("%02d/%02d/%d\n", date[i].dd,date[i].mm,date[i].yy);
		} 
		
		
		i++;
	} 
	return 0;
}




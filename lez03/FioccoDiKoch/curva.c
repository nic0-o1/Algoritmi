#include <stdio.h>
#include "libpsgraph.h"

void CurvaDiKock(int, int);

void FioccoDiKock(int, int);
	
int main(void){
	int i,len;
	
	printf("Inserisci un ordine e una lunghezza in millimetri: ");
	scanf("%d %d",&i, &len);
	
	//start("curva.ps");
    	
    	start("fiocco.ps");
	FioccoDiKock(i,len);
	end();
       
        return 0;
}

void CurvaDiKock(int i, int len){
	
	if( i == 0){
		draw(len);
		
	}
	else{
		CurvaDiKock(len, i-1);
		turn(-60);
		CurvaDiKock(len, i-1);
		turn(120);
		CurvaDiKock(len, i-1);
		turn(-60);
		CurvaDiKock(len, i-1);
	}
}

void FioccoDiKock(int i, int len){
	turn(-60);
	
	CurvaDiKock(i,len);
	
	turn(120);
	CurvaDiKock(i,len);
	
	turn(120);
	CurvaDiKock(i,len);
	

}



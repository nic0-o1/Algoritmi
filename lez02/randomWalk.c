#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

#define COL 10 
#define ROW 10     


typedef enum { false, true } bool;

bool GIU (int rigaCorrente,int colCorrente ,int currentLetter, char *tab[ROW][COL])
{
	if (currentLetter < 90 && rigaCorrente-1 > 0 && (*tab[rigaCorrente-1][colCorrente] == '.')){
		rigaCorrente--;
		currentLetter++;
		*tab[rigaCorrente][colCorrente] = currentLetter;
		return true;
	}
	return false;
}


	
int main(void){

	char tab[ROW][COL];
       	int currentLetter = 65;
       	int rigaCorrente = 5, colCorrente = 5;
       	bool abort = false;
       
       srand(time(NULL));
       
       //rand() % (max_number + 1 - minimum_number) + minimum_number
              
       for (int i = 0; i < ROW; i++)
  	for (int j = 0; j < COL; j++)
    		tab[i][j] = '.';
    		
      tab[5][5] = currentLetter;

	do {
		int candidatePosition = rand() % (4 + 1);
		printf("RAND: %d ", candidatePosition);
		switch(candidatePosition){
			case 0: //SU
				printf("SU: lettera da inserire: %c (%d)  Riga ins: %d Col ins: %d\n",currentLetter+1,currentLetter+1,rigaCorrente-1,colCorrente); 
				if(!GIU(rigaCorrente,colCorrente,currentLetter,&tab)){
				
				}
				else{
					break;
					//abort = true;
					
					}
				
				
			case 1: //GIU
				printf("GIU: lettera da inserire: %c (%d) Riga ins: %d Col ins: %d\n",currentLetter+1,currentLetter+1,rigaCorrente+1,colCorrente); 
				if (currentLetter < 90 &&  rigaCorrente+1 < ROW && tab[rigaCorrente-1][colCorrente] == '.' ){
					rigaCorrente++;
					currentLetter++;
					tab[rigaCorrente][colCorrente] = currentLetter;
					break;
				}
				//else
					//abort = true;
				
				
			case 2: //DESTRA
				printf("DX: lettera da inserire: %c (%d) Riga ins: %d Col ins: %d\n",currentLetter+1,currentLetter+1,rigaCorrente,colCorrente+1); 
				if (currentLetter < 90 &&  colCorrente +1 < COL && tab[rigaCorrente][colCorrente+1] == '.'){
					colCorrente++;
					currentLetter++;
					tab[rigaCorrente][colCorrente] = currentLetter;
					
				}
				//else
					//abort = true;
				
				
			case 3: //SINISTRA
				printf("SX: lettera da inserire: %c (%d) Riga ins: %d Col ins: %d\n",currentLetter+1,currentLetter+1,rigaCorrente,colCorrente-1); 
				if (currentLetter < 90 &&  colCorrente -1 > 0 && tab[rigaCorrente][colCorrente-1] == '.' ){
					colCorrente--;
					currentLetter++;
					tab[rigaCorrente][colCorrente] = currentLetter;
					break;
				}
				else
					abort = true;
				
				
		}
	} while(!abort);

	for (int r = 0; r < ROW ; r ++ ){
		for (int c = 0; c < COL ; c ++ ){
			printf(" %c", tab[r][c]);
		}
		
		printf("\n");
		
	}

       
        return 0;

}

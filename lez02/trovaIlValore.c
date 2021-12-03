#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
    


typedef enum { false, true } bool;



	
int main(void){
	int val[100];
	int tot,tmp= 0;
	
	
	printf("Inserisci n:");
	scanf("%d",&tot);
	
	do{
		scanf("%d", &val[tmp]);
		tmp++;

       } while(tmp < tot-1);
       
       //trova il mancante
       
       for(int i = 0;i<tot;i++){
       	if(i < val[i]){
       		printf("%d",i);
       		break;
       	}
       }
       
       
       
       
       
       
        return 0;
}



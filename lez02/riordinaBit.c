#include <stdio.h>
	
int main(void){
	int val[100];
	int tot,tmp= 0;
	
	
	printf("Inserisci n:");
	scanf("%d",&tot);
	
	do{
		scanf("%d", &val[tmp]);
		tmp++;

       } while(tmp < tot);
       
       for(int i=0; i<tot;i++){
       	if(val[i] == 1){
       		for(int j = i; j<tot; j++){
       			if(val[j] == 0){
       				tmp = val[i];
       				val[i]= val[j];
       				val[j] = tmp;
       				break;
       			}
       		}
       	} 
       }
       
       for(int i = 0; i< tot; i++){
       	printf("%d ",val[i]);
       }
       printf("\n");
       
        return 0;
}



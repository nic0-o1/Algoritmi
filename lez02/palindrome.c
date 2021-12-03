#include <stdio.h>
#include <string.h>

typedef enum { false, true } bool;

int main(void){
	//Lettura stringa terminata con . e dire se è palindroma
	char parola[256];
	int len;
	int j;
	bool palindroma = true;
	
	printf("Inserisci una parola terminata da . : ");
	scanf("%s", parola);
	
	len = strlen(parola); 
	
	if(parola[len-1] != '.'){
		printf("Formato non valido\n");
	}	
	else{
		j = len-2;
		for(int i = 0; i< len-2/2;i++){
			if(parola[i] != parola[j]){
				palindroma = false;
				break;
			}
			j--;
		}
		if(palindroma == true)
			printf("Palindroma");
		else
			printf("Non palindroma");
	}
	return 0;
}

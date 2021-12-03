#include <stdio.h>
#include  <ctype.h>


typedef enum { false, true } bool;



int main(void){

	int occorrenzaPrimo[26] ={0}; 
	int occorrenzaSecondo[26] ={0}; 
	
	int ch,index;
	bool anagramma = true;
	
	printf("Inserisci la prima parola. Termina con . ");
	
	while((ch = getchar()) != '.') {
			if(isalpha(ch)){
				ch = toupper(ch);
				index = ch - 65;
				occorrenzaPrimo[index]++;
			}
		}	
		
	printf("Inserisci la seconda parola. Termina con . ");
	
	while((ch = getchar()) != '.') {
			if(isalpha(ch)){
				ch = toupper(ch);
				index = ch - 65;
				occorrenzaSecondo[index]++;
			}
		}	
		
	
		
		
	for (int i = 0; i < sizeof(occorrenzaPrimo)/sizeof(occorrenzaPrimo[0]); i++){
		if(occorrenzaPrimo[i] != occorrenzaSecondo[i]){
			anagramma = false;
			break;
		}
	}	
	
	anagramma ? printf("Sono anagrammi\n") : printf("Non sono anagrammi\n");
	return 0;
}




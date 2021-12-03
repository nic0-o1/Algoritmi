#include <stdio.h>
#include  <ctype.h>

void repeat (char c , int count )
{
	printf("%c :",c);
	
	for (int i = 0; i<count;i++){
		printf(" %c", '*');
	}
	
	printf("\n");
}


int main(void){

	int occorrenza[26] ={0}; 
	
	int ch,index;
	
	while((ch = getchar()) != '.') {
			if(isalpha(ch)){
				ch = toupper(ch);
				index = ch - 65;
				occorrenza[index]++;
			}
		}	
		
		for (int i = 0; i < sizeof(occorrenza)/sizeof(occorrenza[0]); i++){
			if(occorrenza[i] != 0)
				repeat(i+65,occorrenza[i]);
		}	
	return 0;
}




#include <stdio.h>
#include <string.h>

int smallest_word_index( char *s[], int n );



int main (void) {

	char *dict[] = { "ciao", "mondo", "come", "funziona", "bene", "a", "programma" };
	int lun = 7, pos;
	
	printf("Indice minore: %d\n", smallest_word_index(dict, lun));
}

int smallest_word_index( char *s[], int n ) {
	
	int minIndex = 0;
	
	for(int i = 1; i < n; i++) {
		if (strcmp(s[i],s[minIndex]) <0 ){
			minIndex = i;
		}
			
	}
	return minIndex;
}


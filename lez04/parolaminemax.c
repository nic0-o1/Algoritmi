#include <stdio.h>
#include <string.h>

void smallest_largest (char *s[], int n, char **smallest, char **largest );



int main (void) {

	char *dict[] = { "ciao", "mondo", "come", "funziona", "bene", "a", "programma" };
	int lun = 7;
	
	char **smallest; 
	char **largest;
	
	
	//printf("Indirizzo array: %d\n", &dict);
	
	smallest_largest(dict, lun, smallest,largest);
	
	printf("Min: %c Max: %s\n",*smallest, *largest);
}

void smallest_largest (char *s[], int n, char **smallest, char **largest ) {
	
	//printf("Indirizzo array: %d\n", &s);
	
	int minIndex = 0, maxIndex = 0;
	
	for(int i = 1; i < n; i++) {
		if (strcmp(s[i],s[minIndex]) < 0 ){
			minIndex = i;
			smallest = &s[i];
		}
		else if (strcmp(s[i],s[minIndex]) > 0 ){
			maxIndex = i;
			largest = &s[i];
		}
			
	}
	printf("Min: %s Max: %s\n",*smallest, *largest);
	
}


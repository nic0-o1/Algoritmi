#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *read_line( char c );

char *read_word( void );

int main( void ) {
 printf("\n%s\n", read_line('i'));
}

char *read_line( char c ) {
	char *p, in;
	int n = 0, size = 2;
	
	p = malloc(size);
	
	if(p == NULL) {
		printf("Erorre malloc");
		exit(EXIT_FAILURE);
	}
	
	while(( in = getchar()) != c) {
	
		if( n >= size) {
			size *=2;
			p = realloc(p,size);
			
			if(p == NULL) {
				printf("Erorre realloc");
				exit(EXIT_FAILURE);
			}
			
			if ( in == c)  {
				p[n] = '\0';
				break;
			}
		}
		p[n++] = in;
	}
	return p;
}

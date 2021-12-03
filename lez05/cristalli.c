#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int latoCristallo( int t );
void cristallo( char **m, int l);
char **creaMatrice( int n );
void stampaMatrice( char **m, int n );
void  crist( char **m, int r0, int c0, int l );


int main( void ){

	char** matrix;
	int t, lato;
	
	scanf( "%d", &t );//  legge il tempo
	
	if( t >= 0 ) {
		lato = latoCristallo( t );// dimensione della matrice
		
		matrix = creaMatrice( lato );// crea matrice per rappresentare il cristallo
		cristallo( matrix , lato );// costruisce il cristallo avente lato assegnato
		
		stampaMatrice( matrix , lato );// stampa la matrice
	
	}
	return 0;
}

int latoCristallo( int t ) {
	if (t == 0)
		return 1;
	
	return 1 + 2 * latoCristallo(t-1);
}

void stampaMatrice( char **m, int n ) {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			printf("%c",m[r][c]);
		}
		printf("\n");
	}

}

char **creaMatrice( int n ){
	char **m;
	int r, c;

	m = malloc( n * sizeof( char * ) );
	
	for ( r = 0; r < n; r++ ) {
		*(m+r) = malloc( n * sizeof( char ) );
	}

	for ( r = 0; r < n; r++ )
		for ( c = 0; c < n; c++ )
	  		m[r][c] = '.';
	  		
	return m;
}

void  crist( char **m, int r0, int c0, int l ) {
	if ( l == 1)
		m[r0][c0] = '*';
	else {
		m[r0+l/2][c0+l/2] = '*';
		crist(m,r0,c0,l/2);
		crist(m,r0,c0 + l/2 +1, l/2);
		crist(m,r0 + l/2 + 1, c0, l/2);
		crist(m,r0 + l/2 +1, c0 + l/2 + 1, l/2);
		
	}		
		
}		
		
void cristallo( char **m, int l) {
	crist(m,0 , 0, l);
} 		



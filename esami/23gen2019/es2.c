#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *createJumps( int, int );


int main() {
	int r, c; 
	scanf( "%d %d", &r, &c);  //spazio
	
	printf("%d %d\n", r,c);
	
	int *jump = createJumps( r, c );

	int n = r*c ;
	printf( "%d\n", n );
	for ( int i = 1; i <= n; i++ )	
		printf( "%d ", jump[i] );
	printf( "\n" );
	
	return 0;
}

int *createJumps( int r, int c ){
	int n = r * c;
	int *jump = malloc( n * sizeof(int *) ); 
	
	int s, m, t;
	scanf( "%d", &s );
	
	while ( s > 0) {	  //serpenti
		scanf( "%d %d", &m, &t );//spazio
		//printf("%d %d\n", m,t);
		jump[m] = t; //invertito bocca - coda
		s--; //dec
	}

	//scale
	int l, start, len;
	scanf( "%d", &l );
	
	for (int i = 0; i < l; i++ ) {	
	
		scanf( "%d %d", &start, &len ); //space
		
		int row, col, end;
		
		
		row = r - 1 - (start-1)/c;
		col = (start-1) % c;
		
		
		if ( ( row  ) % 2 != 0 ) 
			col = c - col -1;

		
		row = row - len + 1;
		end = c * ( r - row );
		
		if ( ( row + r ) % 2 == 0  )
			end -= col;
		else 
			end += col - c + 1;
			
		//printf("AFTER Row: %d col: %d\n" ,row, col);
		
		jump[start] = end;
	}

	return jump;
}










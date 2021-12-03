#include<stdio.h>
#include<stdlib.h>

typedef struct {
	float x, y;
} Punto;

typedef struct {
	Punto p1;
	Punto p2;
} Rettangolo;

Rettangolo *nuovoRettangolo(float b1, float h1, float b2, float h2) {
	Rettangolo *r;
	
	r = malloc(sizeof(Rettangolo));
	
	r-> p1.x = b1;
	r -> p1.y = h1;
	
	r -> p2.x = b2;
	r -> p2.y = h2;
	
	return r;
}


int main( void ){

	float ba, h, area, duep;
	Rettangolo *r;
	
	float a,b,c,d;

	printf( "RETTANGOLO:\n" );
	printf( "Inserisci le coordinate del punto in basso a sinistra\n" );
	scanf( "%f%f" , &a, &b );
	printf( "Inserisci le coordinate del punto in alto a destra\n" );
	scanf( "%f%f", &c, &d );
	
	r = nuovoRettangolo(a,b,c,d);
	
	ba = r -> p2.x - r  -> p1.x;
	h = r  -> p2.y - r  -> p1.y;
	area = ba * h;
	duep = 2 * ( ba + h );
	printf( "L'area del rettangolo vale %.2f, il perimetro vale %.2f\n", area, duep );

	return 0;
}

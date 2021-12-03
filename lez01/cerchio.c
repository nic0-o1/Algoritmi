#include <stdio.h>
#include <math.h>

int main(void){
	float raggio;
	printf("Inserisci il raggio del cerchio: ");
	scanf("%f", &raggio);

	printf("Area del cerchio: %.1f\n", M_PI*raggio*raggio);
	return 0;
}

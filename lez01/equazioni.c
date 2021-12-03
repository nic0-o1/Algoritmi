#include <stdio.h>
#include <math.h>

int main(void){
	double a,b,c;
	printf("Inserisci A: ");
	scanf("%lf", &a);
	
	printf("Inserisci B: ");
	scanf("%lf", &b);
	
	printf("Inserisci C: ");
	scanf("%lf", &c);
	
	double delta = b*b - (4*a*c); 
	
	float sol1 = (-b + sqrt(delta))/(2*a);
	float sol2 = (-b - sqrt(delta))/(2*a);
	
	printf("Le soluzioni sono\n");
	printf("X1: %.1lf\n", sol1);
	printf("X2: %.1lf\n", sol2);
	
	return 0;
}

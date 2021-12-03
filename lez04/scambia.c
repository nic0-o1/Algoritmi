#include <stdio.h>

void scambia( int *p, int *q );

int main( void ) {
  int a,b;
  
  printf("Inserisci due valori da scambiare: ");
  scanf("%d %d", &a, &b);
  
  scambia(&a, &b);
  
  printf("\nValori scambiati: %d %d\n", a,b);
  return 0;
}

void scambia (int *p, int*q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

#include <stdio.h>
	
int hanoi( int n, int from, int temp, int to );
	
int main(void){
	int n;
	
	printf("Inserisci l'altezza della pila della torre: ");
	scanf("%d", &n);
	
	printf("Mosse totali: %d\n", hanoi(n,0,1,2));
	
}
int count = 0;

int hanoi( int n, int from, int temp, int to ){
	
	
	if(n == 1){
		printf("%d -> %d\n",from,to);
		count++;
		return count;
	}
	
	hanoi(n-1,from,to,temp);
	
	count++;
	printf("%d -> %d\n",from,to);
		
	hanoi(n-1,temp,from,to);
	
}



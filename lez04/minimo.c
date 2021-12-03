#include <stdio.h>
#include <string.h>

int *smallest( int a[], int n );



int main( int argc, char *argv[]) {
	
	int n,temp;
	int a[100];
	
	printf("Quanti valori vuoi inserire ?: ");
	scanf("%d", &n);
	
	while(temp < n){
	
		printf("\nInserisci valore: ");
		scanf("%d", &a[temp]);
		temp++;
	}
	
	
    printf("Valore minimo: %d\n", *smallest( a, n ));

    return 0;

}

int *smallest( int a[], int n ) {
	int *min = &a[0];
	
	for(int i = 1; i< n; i++){
		if ( a[i] < *min)
			min = &a[i];
	}
	return min;

}


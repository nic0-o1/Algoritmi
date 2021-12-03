#include <stdio.h>
#define N 10

void stampa ( int a[] , int lung );
void scambia ( int a[] , int i , int j );
void selectionsort ( int a[] , int n );
void mergesort ( int a[] , int sx , int dx );
void merge(int a[],int sx, int half, int dx);


int main ( void ) {
	int a[N];
	int n = 0;
	
	while(n<N){
		scanf("%d",&a[n]);
		n++;
	}
	
	/* lettura di un array di interi da standard input */
	/* scegliere uno dei due algoritmi:
	selectionsort( a, N);
	mergesort( a, 0, N);
	*/
	
	mergesort(a,0,N);
	stampa(a, N);
	return 0;
}

void stampa ( int a[] , int lung ){
	for(int i = 0; i < lung; i++)
     		printf("%d ", a[i]);
 	printf("\n");
}

void scambia ( int a[] , int i , int j ){
	/*a[i] = a[i] + a[j]; 
    	a[j] = a[i] - a[j]; 
    	a[i] = a[i] - a[j];*/
    	
    	int tmp = a[i];
    	a[i] = a[j];
        a[j] = tmp;
		
}

void selectionsort ( int a[] , int n ) {
	if(n == 0 || n == 1) return;
	
	//max
	int max = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[max]){
			max = i;
		}
	}
	printf("MAX: %d\n", a[max]); 
	scambia(a,max,n-1);
	selectionsort(a, n-1);
}


void mergesort ( int a[] , int sx , int dx ) {

	if(sx - dx == 0 || sx -dx == 1) return;
	
	int half = (sx+dx)/2;
	
	mergesort(a,sx,half);
	
	mergesort(a,half+1,N);
	
	merge(a, sx, half,dx);

}

void merge(int a[],int sx, int half, int dx) {
	int i = sx,j = half + 1, k = 0;
	int out[N];
	
	while(i <= half && j <= dx) {
		if(a[i] < a[j]){
			out[k] = a[i];
			i++;
		} 
		else {
			out[k] = a[j];
			j++;

		}
		k++;
	}
	
	while( i<= half) {
		out[k] = a[i];
		k++;
		i++;
		
	}
	
	while( j <= dx) {
		out[k] = a[j];
		k++;
		j++;
		
	}
	
	for(int k = sx; k <= dx; k++) {
		a[k] = out[k - sx];
	}


} 







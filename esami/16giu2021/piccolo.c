#include <stdio.h>


int h( int A[], int B[], int n, int m);

int main(void) {

	int A[] = {1,5,5};
	int B[] = {6,5};
	
	int r = h(A,B,3,2);
	
	printf("%d\n",r);
}

int h( int A[], int B[], int n, int m) {
	printf("Ricevuto: n %d e m %d\n",n,m);
	if( n == 0 && m == 0) {
		if (A[n] < B[n])
			return 1;
		else
			return 0;
	}
	
	if(n == 0) {
		h(A, B, n,  m-1);
	
	}
	
	if( m == 0) {
		h(A, B, n-1,  m);
	}
	
	h(A, B, n-1,  m-1);	


}

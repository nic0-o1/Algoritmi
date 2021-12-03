#include <stdio.h>

unsigned long f_riter(unsigned long a,unsigned long b,int n ){
	if( n == 2 ) {
		return a;
	}
	if( n == 1 ) {
		return b;
	}
	return f_riter( a + b, a, n - 1 );
}

unsigned long f_rec(int n){
	if( n == 1 || n == 2 ){
		return 1;
		
	} 
	return f_rec( n - 1 ) + f_rec( n - 2 );
}

int main(){
	printf("%d ",f_riter(1,1,7));
	
	printf("\n%d\n", f_rec(7));
	
	return 0;
}

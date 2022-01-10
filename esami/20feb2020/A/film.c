#include <stdio.h>


int main(void) {
	int n;
	
	scanf("%d", &n);


	int P[n];
	for(int i = 0; i < n; i++) {
		scanf("%d", &P[i]);
	}
	
	int max = 1;
	int currentMax = 1;
	for(int i = 1; i < n; i++) {
		if(P[i] >= P[i -1]) {
			currentMax++;
		}
		else {
			currentMax = 1;
		}
		if(currentMax > max) 
				max = currentMax;
	}
	
	printf("%d\n",max);
	
	
	return 0;
}

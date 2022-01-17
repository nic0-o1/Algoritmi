#include <stdio.h>

int main(void) {
	int n;
	
	scanf("%d", &n);
		
	int val[n];
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &val[i]); 
	}
	
	for(int i= 0, k = n -1; i < n, k > 0;) {
		if(i >= k || k <= i)
			break;
			
		if(val[k] == 1) {
			k--;
		}
		
		if(val[i] == 0) {
			i++;
		}
		
		if(val[i] == 1 && val[k] == 0){
			int tmp = val[k];
			val[k] = val[i];
			val[i] = tmp;
			
		} 
		
	}
	
	for(int i = 0; i < n; i++) {
		printf("%d ", val[i]); 
	}
	printf("\n%d\n",x);
	
	
	return 0;
}

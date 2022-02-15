#include <stdio.h>

int valoreMancante(int[], int, int);

int main(void) {
	int n;
	int count = 0;
	
	scanf("%d", &n);
	
	int val[n];
	
	while(count < n) {
		scanf("%d", &val[count++]);
	}
	 
    printf("%d\n", valoreMancante(val, 0, n-1));
 
	return 0;
}


int valoreMancante(int nums[], int low, int high)
{
    if (low > high) {
        return low;
    }
 
    int mid = low + (high - low) / 2;
 
    if (nums[mid] == mid) {
        return valoreMancante(nums, mid + 1, high);
    }
    else {
        return valoreMancante(nums, low, mid - 1);
    }
}









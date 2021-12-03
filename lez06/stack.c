#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

int main(void){
	push(1);
	print_stack();
	push(3);
	print_stack();
	printf("%d\n", get_top());
	printf("%d\n", pop());
	print_stack();
	printf("empty");
	make_empty();
	print_stack();
}

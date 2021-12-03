#include <stdlib.h>
#include "Stack.h"
#include <stdio.h>

int main(void){

	Stack *p = create_stack();
	Stack *q = create_stack();
	Stack *r = create_stack();

	push(p,5);
	push(p,9);
	push(p,6);
	push(p,10);
	push(p,3);
	print_stack(p);
	
	push(q,11);
	push(q,5);
	push(q,16);
	push(q,9);
	push(q,2);
	print_stack(q);
	
	for(int i = p->top; i > 0; i--){
		for(int j = q->top; j > 0; j--){
			if(p->array[i] == q->array[j]){
				push(r, p->array[i]);
			}
		}
	}
	
	print_stack(r);
}

#include <stdlib.h>
#include "stack.h"
#include <stdio.h>
#include <ctype.h>

int main(void){
	char token[10];
	int i,a,b;
	
	while(scanf("%10s", token) != EOF){
		if(isdigit(token[0])){
			sscanf(token, "%d", &i);
			push(i);
		} else {
			print_stack();
			a = pop();
			b = pop(); 
			
			switch(token[0]){
				
				case '+':
					push(a+b);
				break;
				
				case '-':
					push(b - a);
				break;
				
				case '*':
					push(a*b);
				break;
				
				case '/':
					push(b/a);
				break;
			}
			print_stack();
		}
	}
}

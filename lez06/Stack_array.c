#include <stdlib.h>
#include "Stack.h"
#include <stdio.h>


void destroy(Stack *s){
	make_empty(s);
	free(s);
	s = NULL;
}

Stack* create_stack() {
	return malloc(sizeof(Stack));
}

/* svuota la pila */
void make_empty( Stack *s){
	for(int i=0; i < (s -> top+1); i++){
		s -> array[i] = 0;
	}
}

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty( Stack *s ){

	if(s -> top == -1)
		return 1;
	else
		return 0;
}

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int get_top(Stack *s ){

	if(is_empty(s) == 1){
		printf("Pila vuota! get_top\n");
		exit(0);
	}else
		return s -> array[s->top];
}

/* se la pila non e' vuota, estrae il top da1la pila; 
altrimenti esce con messaggio di errore. */
int pop( Stack *s ){

	if(is_empty(s)){
		printf("Pila vuota pop\n");
		exit(0);
	}else{
		s -> top--;
		return s -> array[s -> top+1];
	}
}

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push(Stack *s, int n ){
	if((s -> top+1) < N){
		s -> array[s -> top+1] = n;
		s -> top++;
	}else
		printf("Pila piena push");
}

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( Stack *s ){
	for(int i= (s-> top); i > 0; i--){
		printf("[%d]",s -> array[i]);
	}
	printf("\n");
}




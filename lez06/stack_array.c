#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

#define MAX 100

int array[MAX];
int top = -1;

/* svuota la pila */
void make_empty( void ){
	for(int i=0; i < top+1; i++){
		array[i] = 0;
	}
}

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty( void ){
	if(top == -1)
		return 1;
	else
		return 0;
}

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int get_top( void ){
	if(is_empty() == 1){
		printf("Pila vuota! get_top\n");
		exit(0);
	}else
		return array[top];
}

/* se la pila non e' vuota, estrae il top da1la pila; 
altrimenti esce con messaggio di errore. */
int pop( void ){
	if(is_empty()){
		printf("Pila vuota pop\n");
		exit(0);
	}else{
		top--;
		return array[top+1];
	}
}

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( int n ){
	if(top+1 < MAX){
		array[top+1] = n;
		top++;
	}else
		printf("Pila piena push");
}

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( void ){
	for(int i=top; i > -1; i--){
		printf("[%d]",array[i]);
	}
	printf("\n");
}




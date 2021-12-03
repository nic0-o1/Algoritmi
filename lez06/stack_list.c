#include <stdlib.h>
#include <stdio.h>

struct node{
	int info;
	struct node *next;	
};

struct node *head = NULL;

/* svuota la pila */
void make_empty( void ){
	struct node *current = head;
	struct node *next;

	while (current != NULL){
		next = current->next;
		free(current);
		current = next;
	}

	head = NULL;
}

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty( void ){
	return head == NULL;
}

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int get_top( void ){
	if(is_empty()){
		printf("Pila vuota\n");
		exit(0);
	}else
		return head->info;
}

/* se la pila non e' vuota, estrae il top da1la pila; 
altrimenti esce con messaggio di errore. */
int pop( void ){
	if(is_empty()){
		printf("Pila vuota\n");
		exit(0);
	}else{
		struct node *temp = head;
		head = temp->next;
		return temp->info;
	}
}

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push( int n ){
	struct node *new = malloc(sizeof(struct node));
	new->info = n;
	new->next = head;
	head = new;
}

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( void ){
	struct node *current = head;
	while (current != NULL){
		printf("[%d]", current->info);
		current = current->next;
	}
	printf("\n");
}




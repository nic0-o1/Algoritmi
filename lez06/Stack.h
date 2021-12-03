#define STACK_H

#define N 100 
typedef struct stack {
	int array [N];
	int top ;
} Stack ;

/* svuota la pila */
void make_empty( Stack *s );

/* restituisce 1 se la pila e' vuota, 0 altrimenti */
int is_empty( Stack *s );

/* se la pila non e' vuota, restituisce il top de1la pila; 
altrimenti esce con messaggio di errore. */
int get_top( Stack *s );

/* se la pila non e' vuota, estrae il top da1la pila; 
altrimenti esce con messaggio di errore. */
int pop( Stack *s );

/* se c'e' spazio, aggiunge n alla pila; 
altrimenti esce con messaggio d'errore. */
void push ( Stack *s , int item );

/* stampa il contenuto della pila, partendo dal top. */
void print_stack( Stack *s );


Stack* create_stack();



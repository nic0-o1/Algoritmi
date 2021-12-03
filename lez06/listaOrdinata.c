#include <stdlib.h>
#include <stdio.h>


struct node {
	int info;
	struct node *next;
};

struct node *olist_insert(int n,struct node *l );
struct node *olist_search(int n,struct node *l );
struct node *add_to_list( struct  node *list , int n );
void list_print(struct node *l);


int main() {

	struct  node *new_node;
 	new_node = malloc( sizeof( struct  node ) );
 	new_node  -> info = 22;
 	
 	
 	new_node = add_to_list(new_node, 15);
 	new_node = add_to_list(new_node, 9);
 	new_node = add_to_list(new_node, 8);
 	
 	list_print(new_node);


	list_print(olist_insert(6,new_node));
	//list_print(new_node);

	
	return 0;
}

struct node *olist_insert(int n,struct node *l ) {
	
	struct  node *new_node, *prev, *curr;
 	new_node = malloc( sizeof( struct  node ) );
 	new_node -> info = n;
	
	for( curr = l, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		printf("Inserimento di %d. curr: %d prec: %d\n", curr -> info, prev -> info);
		/*if(curr -> info >= n){
			printf("Inserimento di %d. curr: %d prec: %d\n", curr -> info, prec -> info);
			prec -> next = new_node;
			new_node -> next = curr;
			
			if(prec == NULL) { //INSERIMENTO IN TESTA
				return new_node;	
			}
			else 
				return l;
		
		}*/
	
	}
}

struct  node *add_to_list( struct  node *list , int n ) {

	struct  node *new_node;
	new_node = malloc(sizeof( struct  node ) );
	new_node  -> info = n;
	new_node  -> next = list;
	
	return new_node;
}

void list_print(struct node *l) {
	printf("Elementi lista concatenata: [ ");;
	while (l != NULL) {
		printf("%d ", l -> info);
		l = l -> next;
	}
	
	printf("]\n");
}

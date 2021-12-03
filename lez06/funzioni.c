#include <stdlib.h>
#include <stdio.h>


struct Node {
	int info;
	struct Node *next;
};

void list_print( struct Node *l );
void list_printInv(struct Node *l );
void list_destroy ( struct Node * list );
int* listToArray( struct Node *l );

struct Node *add_to_list( struct  Node *list , int n );


int main() {
	 
 	struct  Node *new_node;
 	new_node = malloc( sizeof( struct  Node ) );
 	new_node  -> info = 10;
 	
 	
 	new_node = add_to_list(new_node, 9);
 	new_node = add_to_list(new_node, 5);
 	new_node = add_to_list(new_node, 7);
 	new_node = add_to_list(new_node, 2);
 	new_node = add_to_list(new_node, 1);
 	new_node = add_to_list(new_node, 88);
 	
 	list_print(new_node);
 	
 	list_destroy(new_node);
 	
 	list_print(new_node);
 	
	return 0;
}

struct  Node *add_to_list( struct  Node *list , int n ) {

	struct  Node *new_node;
	new_node = malloc(sizeof( struct  Node ) );
	new_node  -> info = n;
	new_node  -> next = list;
	
	return new_node;
}

void list_print(struct Node *l) {
	printf("Elementi lista concatenata: [ ");;
	while (l != NULL) {
		printf("%d ", l -> info);
		l = l -> next;
	}
	
	printf("]\n");
}

void list_printInv(struct Node *l ) {
	
	if(l -> next != NULL)
		list_printInv(l -> next);
	
	printf("%d ",l -> info);
}

int* listToArray( struct Node *l ) {
	int count = 0;
	struct Node *tmp = l;
	
	while (l != NULL) {
		count ++;
		l = l -> next;
	}
	
	int *data;
	
	data = malloc(count * sizeof(int));
	
	for(int i = 0; i < count; i++) {
		printf("%d: %d\n", i, tmp-> info);
		if(tmp != NULL){
			data[i] = tmp -> info;
		}
		tmp = tmp -> next;
	}
	
	return &data[0];
}


void list_destroy ( struct Node * list ) {

    struct Node *temp;
    
    while(list != NULL)  {
		
		temp=list;
		list=list->next;
		free(temp);

    }

}
















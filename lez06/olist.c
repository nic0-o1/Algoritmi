#include <stdio.h>
#include <stdlib.h>

struct node {
	int info ;
	struct node * next ;
};

struct node *olist_insert( int n, struct node *list ){
	struct node * curr , * prev, *new ;
	for ( curr = list , prev = NULL ; curr != NULL ; prev = curr , curr = curr -> next ) {
		/*if(curr->info > n){
			printf("[%d][%d]",n, curr->info);
			new->info = n;
			new->next = curr;
			if(prev == NULL){
				return new;
			}else{
				prev->next= new;
				return list;
			}
		}*/
	}
}


void list_print( struct node * list ){
	struct node *curr;
	for (curr = list; curr != NULL; curr = curr -> next ) {
		if(curr == NULL)
			break;
		else
			printf("[%d]",curr->info);
	}
}

void list_printInv( struct node * list ) {
	if(list->next != NULL)
		list_printInv(list->next);
	printf("[%d]",list->info);
}

int main() {
	struct node *first = NULL;
	first->info = 2;
	int n;

	while(scanf("%d", &n), n != 0){
		first = olist_insert(n, first);  
	}

	list_print(first);
	printf("\n");
	//list_printInv(first);
	printf("\n");
	return 0;
}


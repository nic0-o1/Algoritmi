#include <stdio.h>
#include <stdlib.h>

struct node {
	int info ;
	struct node * next ;
};

struct node * add_to_list ( struct node * list , int n ){
	struct node * new_node ;
	new_node = malloc ( sizeof ( struct node ) );
	new_node -> info = n ;
	new_node -> next = list ;
	return new_node;
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

int* listToArray( struct node * list ){
	int n, *arr, c=0;
	for (struct node *curr = list; curr != NULL; curr = curr -> next ) { 
		if(curr == NULL)
			break;
		else
			n++;
	}
	arr = malloc(n * sizeof(int));
	for (int i = 0; i<n; i++) {
		if(list != NULL){
			arr[i] = list->info;
			list= list->next;
		}
	}
	return &arr[0];
}

void list_destroy ( struct node * list ) {
	struct node *temp;
	while(list!=NULL);  
	{
		printf("destroing");
	  temp=list;
	  list=list->next;
	  free(temp);
	}
	printf("destroyed");
}

int main() {
	struct node *first = NULL;
	int n;

	while(scanf("%d", &n), n != 0){
		first = add_to_list( first, n);  
	}

	list_print(first);
	printf("\n");
	list_printInv(first);
	printf("\n");
	//int *arr = listToArray(first);
	//printf("%d\n", &arr[0]);
	list_destroy(first);
	list_print(first);
	printf("\n");
	return 0;
}

















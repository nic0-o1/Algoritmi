#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
	int info;
	struct node *next;
};

struct node *list_insert( int n, struct node *l ){
	struct node *new = malloc(sizeof(struct node));
	new -> info = n;
	new -> next = l;
	return new; 
}

struct node *list_delete(int n, struct node *head){
	struct node *curr, *prev;
	for ( curr = head, prev = NULL; curr != NULL; prev = curr, curr = curr -> next ) {
		if (curr -> info == n ) break;
	}
	if ( curr == NULL )
		return head; 
	if (prev == NULL )
		head = head -> next;
	else
		prev -> next = curr -> next;
	free( curr );
	return head;
}

bool appartiene(int n, struct node* head){
	struct node *curr;
	for(curr = head; curr != NULL; curr = curr->next){
		if(n == curr->info){
			return true;
		}
	}
	return false;
}

void print_list(struct node *head){
	struct node *curr;
	for(curr = head; curr!= NULL; curr = curr->next){
		printf("[%d]",curr->info);
	}
	printf("\n");
}

void list_destroy ( struct node * head ) {
	struct node *temp, *curr;
	for(curr = head; curr != NULL; curr = curr->next){
		temp=curr;
		curr=curr->next;
		free(temp);
		temp = NULL;
	}
}

int main(void){
	struct node *head = NULL;
	int n, count=0;
	char c;
	printf("Digita un comando: ");
	
	while( ( c = getchar () ) != 'f'  ){
		switch(c){
			case '+' :
				scanf("%d", &n);
				if(head==NULL || !appartiene(n, head)){
					head = list_insert(n, head);
					count++;
				}
				break;
			case '-' :
				scanf("%d", &n);
				if(head!=NULL && appartiene(n, head)){
					head = list_delete(n, head);
					count--;
				}
				break;
			case '?' :
				scanf("%d", &n);
				if(appartiene(n, head))
					printf("%d appartiene alla lista!\n", n);
				else
					printf("%d non appartiene alla lista!\n", n);
				break;
			case 'c' :
				printf("Count: %d\n", count);
				break;
			case 'p' :
				if(count == 0)
					printf("Lista vuota\n");
				else
					print_list(head);
				break;
			case 'd' :
				list_destroy(head);
				count = 0;
				break;
		}
	}
	return 0;
}



#include "queueList.h"
#include <stdio.h>
#include <stdlib.h>


Queue* create_queue() {
	Queue *q = malloc(sizeof(Queue));
	return q;
}

void destroy_queue(Queue *q) {
	free(q);
}

void enqueue( Queue *q, Item e ) {
	Node n = malloc(sizeof(Node));
	n -> info = e;
	printf("Valori pre enqueue:\n \tfront: %d \n\trear %d \n\t\n", q -> front, q -> rear);
	if(!is_empty_queue(q))
		q -> rear -> next = n;
	else
		q -> front = n;
	
	q -> rear = n;
	q -> tot ++;
	printf("Valori post enqueue:\n \tfront: %d \n\trear %d \n\t\n", q -> front, q -> rear);
}

Item dequeue( Queue *q) {
	if(is_empty_queue(q)) {
		printf("Impossibile estrarre da una coda vuota\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Valori pre dequeue:\n \tfront: %d \n\trear %d \n\t\n", q -> front, q -> rear);
	
	Item i = q -> front -> info;
	
	q -> front = q -> front -> next;
	q -> tot --;
	printf("Valori post dequeue:\n \tfront: %d \n\trear %d \n\t\n", q -> front, q -> rear);
	
	return i;

}


Item frontValue( Queue *q) {
	return q->front->info;
}

int is_empty_queue( Queue *q ){
	return q -> tot == 0;
}

void print_queue( Queue *q ){
	if(!is_empty_queue(q)){
		printf("pr\n");
		for(Node curr = q -> front; curr != NULL; curr = curr -> next) 
			printf("[%d]",curr -> info);
		printf("\n");
	}
}


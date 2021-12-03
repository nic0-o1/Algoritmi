#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


Queue* create_queue() {
	Queue *q = malloc(sizeof(Queue));
	q -> rear = -1;
	return q;
}

void destroy_queue(Queue *q) {
	
	for (int i = 0; i < q -> tot_el; i++) {
		q-> array[i] = 0;
	}
	free(q);
}

void enqueue( Queue *q, Item e ) {
	
	if (q -> tot_el +1 == N){
		printf("Impossibile inserire, coda piena\n");
		exit(EXIT_FAILURE);
	}
	//printf("Valori pre enqueue:\n \tfront: %d \n\trear %d \n\ttot %d\n", q -> front, q -> rear, q ->tot_el);
	q -> rear = (q -> rear + 1) % N; //controlla
	q -> array[q -> rear] = e;
	q -> tot_el++; 
	
	//printf("Valori post enqueue:\n \tfront: %d \n\trear %d \n\ttot %d\n", q -> front, q -> rear, q ->tot_el);
}

Item dequeue( Queue *q) {
	if(is_empty_queue(q)) {
		printf("Impossibile estrarre da una coda vuota\n");
		exit(EXIT_FAILURE);
	}
	//printf("Dequeue\n");

	
	//printf("Valori pre dequeue:\n \tfront: %d \n\trear %d \n\ttot %d\n", q -> front, q -> rear, q ->tot_el);
	
	Item i = q -> array[q->front];

	q -> front = (q -> front + 1 ) % N;
	q -> tot_el--;
	
	//printf("Valori post dequeue:\n \tfront: %d \n\trear %d \n\ttot %d\n", q -> front, q -> rear, q ->tot_el);
	return i;

}

Item frontValue( Queue *q) {
	return q->array[q-> front];
}

int is_empty_queue( Queue *q ){
	return q -> tot_el == 0;
}

void print_queue( Queue *q ){
	for (int i = q-> front; i <= q -> rear; i ++){
		printf("[%d->%d]",i ,q-> array[i]);
	}
	printf("\n");
}


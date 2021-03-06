#include "queueList.h"
#include <stdio.h>

int main (void){
	
	
	Queue *q = create_queue();
	
	enqueue( q, 4);
	printf("Deleted %d\n", dequeue(q));
	print_queue(q);
	
	enqueue( q, 9);
	print_queue(q);
	
	printf("Deleted %d\n", dequeue(q));
	print_queue(q);
	
	
	enqueue( q, 5);
	print_queue(q);
	
	printf("Front %d\n", frontValue(q));
	destroy_queue(q);
	print_queue(q);
}

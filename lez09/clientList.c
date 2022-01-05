#include "queueList.h"
#include <stdio.h>

int main (void){
	
	
	Queue *q = create_queue();
	
	enqueue( q, 4);
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
	
	float x = (float)rand()/(float)(1);
	
	printf("%.2f\n",x);
}

#define QUEUELIST_H
#include <stdbool.h>

typedef int Item;

struct listnode {
	struct listnode *next;
	Item info;
	bool visited;
};


typedef struct listnode* Node;


/*struct node {
	Item info;
	struct node *next;
};

typedef struct node *Node;*/

typedef struct {
	Node front;
	Node rear;
	int tot;
} Queue;

Queue* create_queue();

void destroy_queue(Queue *q);

// Put element on rear
void enqueue( Queue *q, Item e);

// Remove and return element from front
Item dequeue( Queue *q );

// Return front element
Item frontValue( Queue *q );

// Check if queue is empty
int is_empty_queue( Queue *q );

// Print queue content
void print_queue( Queue *q );

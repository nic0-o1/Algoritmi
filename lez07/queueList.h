#define QUEUELIST_H

typedef int Item;

struct node {
	Item info;
	struct node *next;
};

typedef struct node *Node;

typedef struct {
	Node front;
	Node rear;
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

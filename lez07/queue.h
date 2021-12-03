#define QUEUE_H
#define N 10

typedef int Item;

typedef struct {
	int front, tot_el, rear;
	Item array[N];
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

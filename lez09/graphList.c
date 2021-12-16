#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "queueList.h"


struct graph {
	int n, m;
	struct listnode **A;	
};



typedef struct graph *Graph;

/*crea un grafo con n nodi*/
Graph graph_new(int n );

/*distrugge il grafo g*/
void graph_destroy( Graph g );

/*inserisce l’arco (v,w) nel grafo g*/
void graph_edgeinsert( Graph g,int v,int w ); 

/*legge da standard input un grafo (specificare il formato!!)*/
Graph graph_read(void);

/*stampa su standard output un grafo (specificare il formato!!)*/
void graph_print( Graph g );

void BFS( Graph g );

void DFS(Graph g, int vertex);

bool contains(struct listnode **visited, struct listnode *item, int size );

struct listnode* listnode_new(int n);

void test(Graph g);


int main(void) {

	Graph g = graph_read();
	
	//graph_print(g);
	//BFS(g);
	DFS(g,0);
	//test(g);
	return 0;
}

bool contains(struct listnode **visited, struct listnode *item, int size ) {
	for(int i = 0; i < size; i++) {
		//printf("\nConfronto: visited %d con u %d\n",visited[i]-> info ,item -> info);
		if(visited[i] -> info == item -> info) {
			return true;
		}
	}
	return false;
}

void test(Graph g){
	int visIndex = 0;
	
	struct listnode *visited[g -> n];
	
	DFS(g,0);
}

void DFS(Graph g, int vertex) {
		// 0 1 2 4 3		
	
	if(g ->A[vertex] -> visited) {
		return;
	}
	else {
			printf("%d\n", g ->A[vertex] -> info);
	 		g ->A[vertex] -> visited = true;
		
			for(struct listnode *v = g -> A[vertex] -> next; v != NULL; v = v -> next) {
				DFS(g,v-> info);
				
			} 	
		}
	
	
	/*for (struct listnode *item = g -> A[vertex]; item != NULL; item = item -> next ) {
		printf("\nConfronto: %d\n", item -> info); 
		if(!contains(visited, item,  visIndex)){
			visited[visIndex] = item;
			visIndex++;
			DFS(g,item -> next -> info, visited, visIndex);
		}
	}*/
	
}

void BFS( Graph g ) {
	
	int i = 0;
	int visIndex = 0;
	bool found = false;
	Queue *q = create_queue();
	
	struct listnode *visited[g -> n];

	while(g-> A[i] -> next == NULL) {
		i++;
	}
	
	visited[visIndex] = g->A[i]; // primo nodo connesso
	enqueue(q, g -> A[i] -> info);
	print_queue(q);
	visIndex++;
	
	while(!is_empty_queue(q)) {
		int u = dequeue(q);
		printf("u1: %d\n", u);
		for (struct listnode *item = g -> A[u] -> next; item != NULL; item = item -> next ) {
		
			if(!contains(visited, item,  visIndex)){
	
				//printf("Inserisco in %d: %d\n",visIndex, item-> info);
				enqueue(q,item -> info);
				visited[visIndex] = item;
				visIndex++;
				print_queue(q);
				
				printf("\n");
			}
		}
		
	}
	print_queue(q);
	 


}

Graph graph_new(int n ) {
	int i; Graph g;
	
	
	g = malloc( sizeof(struct graph) );
	g -> A = calloc( n,sizeof(struct listnode*));
	
	for(int i = 0; i < n; i++) {
		g -> A[i] = listnode_new(i);
	}
	
		
	g -> n = n;
	
	return g;

}

struct listnode* listnode_new(int n) {
	struct listnode *l = malloc(sizeof( struct listnode*));
	
	l -> info = n;
	l -> next = NULL;
	l -> visited = false;
	return l;
}

void graph_edgeinsert( Graph g,int n,int w ) {

	for(struct listnode *item = g -> A[n]; item != NULL; item = item -> next) {
		if(item -> next == NULL) { //inserimento nel fondo
			item -> next = listnode_new(w);
			break;
		} else if( item -> next -> info > w) {
			struct listnode *new = listnode_new(w);
			struct listnode *oldNext = item -> next;
			
			item -> next = new;
			new -> next = oldNext;
			break;
		}
		
		
	}
}

Graph graph_read(void) {
	int n;
	//printf("Inserisci il numero di nodi: ");
	scanf("%d", &n);
	
	Graph g = graph_new(n);
	int u,v;
	int m = (n*(n-1))/2;
	
	while(m >=0) {
		//printf("Inserisci nodo: ");
		
		scanf("%d", &u);
		scanf("%d", &v);
		
		if (u < 0 || v < 0)
			break;
		
		graph_edgeinsert(g,u,v);
		m--;
	}
	
	return g;
}

void graph_print( Graph g ) {
	
	for(int i = 0; i < g->n; i++) {
		printf("%d", i);
		
		for (struct listnode *item = g->A[i] -> next; item != NULL; item = item -> next ) {
			printf("->%d", item -> info);
		}
		
		
		printf("\n");
	}
}







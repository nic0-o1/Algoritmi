#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
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

struct listnode* listnode_new(int n);

Graph gen(int n,float p);

int degree(Graph g,int v);

bool path (Graph g,int v,int w);

int ccc(Graph g);


void cc(Graph g, int v);


int main(void) {

	Graph g = graph_read();
	graph_print(g);
	srand(time(NULL));
	//cc(g,1);
	
	//Graph g = gen(5, 0.75);
	//graph_print(g);
	
	bool  x= path(g,0,3);
	printf("%s\n", x ? "true" : "false");
	
	//BFS(g);
	//DFS(gen(5, 0.75),0);
	return 0;
}

Graph gen(int n,float p) {
	Graph g = graph_new(n);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
		
			float x = (float)rand()/(float)(RAND_MAX);
			if( i < j && x < p) {
				printf("Prob : %.2f Inserisco arco.: %d , %d\n",x, i,j);
				graph_edgeinsert(g,i, j );
				
			}
		} 
	}
	
	return g; 
}


/*

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
}

*/


bool path(Graph g,int v,int w){
	printf("Controllo: %d, %d\n",v,w);
	if(v == w){
		printf("OK\n");
		return true;
	}

	for(struct listnode *item = g ->A[v] ->next; item != NULL; item = item ->next) {
		path(g,item-> info,w);
	} 		
	
	//return false;
}

/*bool path(Graph g,int v,int w){
		
	for(struct listnode *item = g -> A[v]; item != NULL;) {
		//printf("item : %d, w: %d\n", item -> info,w);
		//path(g, item -> info, w);
		
		if(w == item -> info) {
			return true;
		}
		
		if(item -> next != NULL) {
			item = g -> A[item ->next  -> info];
		}
		else
			return false;
	}
	
	return false;
}*/

int degree(Graph g,int v) {
	int degree = 0;
	
	for(struct listnode *item = g -> A[v] ->next; item != NULL; item = item -> next) {
		degree++;
	}
	
	return degree;
}

int ccc(Graph g) {
	int count = 0;
	for(int i = 0; i < g -> n; i++) {
		for(int j = 0; j < g -> n; i++) {
			if(i < j  && path(g, g ->A[i] -> info, g -> A[j] -> info)){
				count++;
			}
		}
	}
	return count;
}


void cc(Graph g, int v) {
	for(int i = 0; i < g -> n; i++) {
		if(path(g,v,g ->A[i] -> info)) {
			printf("%d %d\n",v, g->A[i] ->info);
		}
	}


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
}

void BFS( Graph g ) {
	
	int i = 0;
	bool found = false;
	Queue *q = create_queue();

	while(g-> A[i] -> next == NULL) {
		i++;
	}
	
	enqueue(q, g -> A[i] -> info);
	print_queue(q);
	
	while(!is_empty_queue(q)) {
		int u = dequeue(q);
		printf("u1: %d\n", u);
		for (struct listnode *item = g -> A[u] -> next; item != NULL; item = item -> next ) {
		
			if(!item -> visited){
	
				//printf("Inserisco in %d: %d\n",visIndex, item-> info);
				enqueue(q,item -> info);
				item -> visited = true;
				print_queue(q);
				
				printf("\n");
			}
		}
		
	}
	print_queue(q);
	
}








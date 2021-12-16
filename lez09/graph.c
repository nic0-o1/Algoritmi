#include <stdlib.h>
#include <stdio.h>

struct graph {
	int n, m; /*n = num vertici, m = num lati*/
	int **A; /*matrice di adiacenza*/
	
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



int main(void) {

	Graph g = graph_read();
	
	graph_print(g);
	return 0;
}

Graph graph_new(int n ) {
	int i; Graph g;
	
	/*alloca lo spazio per una struct graph*/
	g = malloc( sizeof(struct graph) );
	
	/*alloca lo spazio per un array di n puntatori a int*/
	g -> A = calloc( n,sizeof(int*) );
	
	
	for( i = 0; i < n; i++ )
		/*alloca lo spazio per l’array A[i] di n interi, inizialmente nulli*/
		g -> A[i] = calloc( n,sizeof(int) );
		
	g -> n = n;
	//g -> m = n -1;
	
	return g;

}

void graph_edgeinsert( Graph g,int v,int w ) {
	g -> A[v][w] = 1;
	g -> m++;

}

Graph graph_read(void) {
	int n;
	printf("Inserisci il numero di nodi:\n");
	scanf("%d", &n);
	
	Graph g = graph_new(n);
	int u,v;
	
	while((n*(n-1))/2 >=0) {
		//printf("Inserisci arco. Termina con negativo:\n ");
		
		scanf("%d", &u);
		scanf("%d", &v);
		
		if (u < 0 || v < 0)
			break;
		
		graph_edgeinsert(g,u,v);
		n--;
	}
	
	return g;
}

void graph_print( Graph g ) {
	
	printf("    ");
	
	for(int c = 0; c < g -> n; c++) {
			printf("%d ", c);
		
	}
	//printf("\n");
	printf("\n");

	for(int c = 0; c < g -> n; c++) {
		printf("%d | ", c);
		for(int r = 0; r < g -> n; r++) {
			printf("%d ", g -> A[c][r]);
		}
		printf("\n");
	}



}



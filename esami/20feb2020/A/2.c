#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct node{
	char *w;
	struct node  *next;
};

typedef struct node* Node;

char *fstring_iter(char *w, Node l) {
	char *r = w;
	int i;
	
	for(Node n = l; n != NULL; n = n -> next) {
	
		i = 0;
		
		while(r[i] != '\0') {
			i++;
		}
			
		while(w[i++] != '\0') {
			r[i]= w[i];
		}
		
	}
	return r;
}

char *fstring( char *w, Node l ){
	if ( l -> next == NULL )
		return strcat( w, l -> w );

	return strcat( fstring( w, l -> next ), l -> w );
}


Node flist( Node l ) {
	//printf("%s\n", l -> w);
	if ( l -> w[0] != '\0' && l -> w[1] == '\0' ){
		return l;
	}
	Node n = malloc( sizeof(struct node) );
	n -> w = ( l -> w ) + 1;
	n -> next = l;
	return flist( n );		
}

Node build( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;   //ciao\0
	lista -> next = NULL;
	//return flist( lista );
	return lista;
}


Node flist2( Node l ) {

	if ( l -> w[0] != '\0' && l -> w[1] == '\0' )
		return l;
	Node n = malloc( sizeof(struct node) );
	
	int size=0;
	
	while(l -> w[size] != '\0') {
		size++;
	}	
	
	n -> w = calloc(size, sizeof(char));
	
	for(int i = 0; i < size -1; i++) {
		n -> w[i] = l ->w[i];
	} 
	
	n -> next = l;
	return flist2( n );		
}

Node build2( char *w ) {
	Node lista = malloc (sizeof(struct node) );
	lista -> w = w;   //ciao\0
	lista -> next = NULL;
	return flist2( lista );
}

int main(void) {	
	
	char word[20] = "";
	printf( "%s\n", fstring( word, build2( "hello") ) );
	//Node x = build("prova");
	
	//n -> next = x;
	//printf("%s\n", n -> w);
	//char d[50] = "ciao";
	
	//char *c = fstring(d, n);
	//printf("%s\n", c);
	
	//printf("%s\n", fstring_iter(d,n));
}

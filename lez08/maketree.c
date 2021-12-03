#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 7

typedef int Item;

struct bit_node{
	Item item;
	struct bit_node *l, *r;
	
};

typedef struct bit_node *Bit_node;

Bit_node bit_new( Item );

void bit_inorder( Bit_node );
void bit_preorder( Bit_node );
void bit_postorder( Bit_node );
void bit_printnode(Bit_node p);
void bit_println_node(Bit_node p);
void bit_printassummary( Bit_node p,int spaces );

Bit_node bit_arr2tree(Item a[], int size,int i);


int main(void){

	/*Bit_node  root; 
	root = malloc( sizeof(struct  bit_node) );
	
	root  -> item = 50;
	root  -> l = malloc( sizeof(struct  bit_node) );
	root  -> r = malloc( sizeof(struct  bit_node) );
	root  -> l -> item = 13;
	root  -> l -> l = NULL;
	root  -> l -> r = malloc( sizeof(struct  bit_node) );
	root  -> r -> item = 75;
	root  -> r -> l = malloc( sizeof(struct  bit_node) );
	root  -> r -> l -> item = 60;
	root  -> r -> r = NULL;
	root  -> l -> r -> item = 38;*/
	
	
	/*printf("Preorder: ");
	bit_preorder(root);
	
	printf("\nInorder: ");
	bit_inorder(root);
	
	printf("\nPostorder: ");
	bit_postorder(root);
	
	printf("\n");
	
	bit_printassummary(root,0);*/
	
	srand(time(NULL));   // Initialization, should only be called once.
	
	int val[SIZE];
	
	for(int i = 0; i< SIZE; i++){
		val[i] = rand() % 50;	
	}
	
	
	for (int i = 0; i < SIZE; i++) {
        printf("[%d]",val[i]);
    }
    printf("\n");
    
    
    Bit_node root = bit_arr2tree(val,SIZE, 0);
    bit_printassummary(root,0);
    
	return 1;
}

Bit_node bit_new( Item item ) {
	Bit_node n = malloc(sizeof(Bit_node));
	
	n -> item = item;
	n -> l = NULL;
	n -> r = NULL;
	
	return n;

}

Bit_node bit_arr2tree(Item a[], int size,int i) {
	Bit_node tree= NULL;
	
	if(i <size) {
	
	  tree=malloc(sizeof(Bit_node));
	  tree -> l=bit_arr2tree(a,size, 2*i+1);
	  tree -> item=a[i];
	  tree -> r=bit_arr2tree(a,size,2*i+2);
	 }
	 return tree;
}


void bit_printassummary( Bit_node p,int spaces ) {
	int i;
	for( i = 0; i < spaces; i++)
		printf(" ");
	
	
	if(p){
		printf("*");
		bit_println_node(p);
		
		if( p-> l || p -> r){
			bit_printassummary(p-> l , spaces+1);
			bit_printassummary(p-> r, spaces+1);	
		}
	}
	else{
		printf("*\n");
	}
	
	
	

}
void bit_println_node(Bit_node p) {
	if(p)
		printf("%d\n", p-> item);
}



void bit_printnode(Bit_node p) {
	printf("%d ", p-> item);
}

void  bit_inorder( Bit_node p ){
	if ( p ) {
		bit_inorder( p -> l );
		bit_printnode( p );
		bit_inorder( p -> r );
	}
}

void  bit_preorder( Bit_node p ){
	if ( p ) {
		bit_printnode( p );
		bit_preorder( p -> l );
		bit_preorder( p -> r );
	}
}

void  bit_postorder( Bit_node p ){
	if ( p ) {
		bit_postorder( p -> l );
		bit_postorder( p -> r );
		bit_printnode( p );
	}
}

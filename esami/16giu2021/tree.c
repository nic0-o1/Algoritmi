#include <stdlib.h>
#include <stdio.h>

int TOT = 0;

struct bit_node {
  int item;
  struct bit_node *l, *r;
};

typedef struct bit_node *Bit_node;

Bit_node newNode(int item){
    Bit_node new = malloc(sizeof(Bit_node));
    new-> item = item;
    new->l = NULL;
    new->r = NULL;
}

void printArray( int *a, int n ) {
	//TOT++;
    for ( int i = 0; i < n; i++ )
        printf( "%d ", a[i] );
    printf( "\n" );
}

void f_r( Bit_node root, int *path, int len ) {
	TOT++;
    if (root == NULL ){
		TOT--;
        return;
    }

    if ( root -> item % 2)  {
        path[len] = root -> item;
        len++;
    }

    if ( root -> r == NULL && root -> l == NULL ) {
        printArray( path, len );
        //TOT--;
        return;
    }
    
    f_r( root -> l, path, len );
    f_r( root -> r, path, len ); 
}

void f( Bit_node root ) {
    int *path = malloc( 1000 * sizeof( int ) );
    f_r( root, path, 0 );
}



int main(void){
    Bit_node root = newNode(1);
    root->l = newNode(39);
    root->r = newNode(15);
    root->r->r = newNode(79);
   	root->r->l = newNode(7);
    root->r->l->l = newNode(9);
    root->r->l->r = newNode(7);
    root->r->l->r->l = newNode(13);
    f(root);
    
    printf("%d\n",TOT);
}

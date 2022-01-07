#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct node {
	int v ;
	struct node * next;
	struct node * ref;
};

struct arrayDiListe {
	int n;
	struct node ** A;
};
typedef struct arrayDiListe *ADL;

//PROTOTIPI
struct node* new_node(int v);
int **new_matr ( int n );
int **read_matr(int **matr);
void matr_print(int **matr, int n);
void adl_AddEges( ADL adl, int v, int w );
ADL matr2arrayDiListe(int **matr, int n);
void adl_print(ADL adl);
int **f_matr( int **matr, int n );
ADL f_arrayDiListe( ADL v, int n);


//MAIN
int main(void) {
	int n;
	scanf("%d", &n);
	//printf("%d\n", n);
	int **matr = new_matr(n);
	matr = read_matr(matr);
	//matr_print(matr, n);
	//printf("\n");
	
	int **matr2 = f_matr(matr,n);
	matr_print(matr, n);
	printf("\n");
	
	ADL v = matr2arrayDiListe(matr, n);
	adl_print(v);
	printf("\n");
	ADL v2 = f_arrayDiListe(v, n);
	adl_print(v2);
	
	return 0;
}


//FUNZIONI
struct node* new_node(int v){
	struct node *new = malloc(sizeof(struct node*));
	new -> v = v;
	new -> next = NULL;
	new -> ref = NULL;
	return new;
}

int **new_matr(int n ){
	int **matr = malloc(n*sizeof(int*));
	for(int i=0; i<n; i++){
		matr[i] = malloc(n*sizeof(int));
		for(int j=0; j<n; j++){
			matr[i][j] = 0;
		}
	}
	return matr;
}

int **read_matr(int **matr){
	//printf("Inserisci gli archi: ");
	int x,y;
	while(true){
		scanf("%d", &x);
		scanf("%d", &y);
		//printf("%d %d\n",x,y);
		if(x < 0 || y < 0){
			break;
		}
		matr[x][y] = 1;
	}
	return matr;
}

void matr_print(int **matr, int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", matr[i][j]);
		}
		printf("\n");
	}
}

void adl_AddEges( ADL adl, int v, int w ){
	struct node *curr;
	for(curr=adl->A[v]; curr!= NULL; curr=curr->next){
		if(curr->next == NULL){
			curr->next = new_node(w);
			curr->next->ref = adl->A[w];
			break;
		}else if(curr->next->v > w){
			struct node *temp = curr->next;
			curr->next = new_node(w);
			curr->next->ref = adl->A[w];
			curr->next->next = temp;
			break;
		}
	}
}	

ADL matr2arrayDiListe(int **matr, int n){
	ADL adl = malloc(sizeof(ADL));
	adl -> A = calloc(n, sizeof(struct node*));
	adl -> n = n;
	for(int i=0; i<n; i++){
		//printf("%d\n",i);
		adl->A[i]= new_node(i);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			 if(matr[i][j] == 1){
			 	adl_AddEges(adl, i, j);
			 }
		}
	}
	return adl;
}

void adl_print(ADL adl){
	struct node *curr;
	for(int i=0; i < adl->n; i++){
		printf("[%d]", adl->A[i]->v);
		for(curr=adl->A[i]->next; curr!= NULL; curr=curr->next){
			printf(" -> [%d][%d] ", curr->v,curr->ref->v);
		}
		printf("\n");
	}
}

int **f_matr( int **matr, int n ) {
	int **matr2 = new_matr( n );
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			if ( matr[i][j] == 1 )
				for ( int k = 0; k < n; k++ )
					if ( matr[j][k] == 1 )
						matr2[i][k] = 1;
	return matr2;
}

ADL f_arrayDiListe( ADL v, int n){
	ADL v2 = malloc(sizeof(ADL));
	v2 -> A = calloc(n, sizeof(struct node*));
	v2 -> n = n;
	for(int i=0; i<n; i++){
		//printf("%d\n",i);
		v2->A[i]= new_node(i);
	}
	
	struct node *curr;
	for(int i=0; i < v->n; i++){
		for(curr=v->A[i]->next; curr!= NULL; curr=curr->next){
			struct node *curr2;
			for(curr2=curr->ref->next; curr2!= NULL; curr2=curr2->next){
				adl_AddEges(v2, i, curr2->v);
			}
		}
	}
	
	return v2;
}









































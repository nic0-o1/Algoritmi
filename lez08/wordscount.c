#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX 30;

struct occorrenza {
	char* word;
	int n;
};

typedef struct occorrenza *Occorrenza;

struct bit_node{
	Occorrenza item;
	struct bit_node *l, *r;
	
};

typedef struct bit_node *Bit_node;

char *read_word(void);
Bit_node bit_new( Occorrenza item );
Occorrenza occorrenza_new(char* word);

void bist_orderprint( Bit_node p );
void bist_invorderprint( Bit_node p );
void bist_printnode(Bit_node p);
void bist_insert(Bit_node root, char* word);
int bist_filter(Bit_node root, char* word);


int main(void) {

	char *word = read_word();
	Bit_node root = bit_new(NULL);
		
	while(strcmp(word,"stop")) {
			
		if(root -> item == NULL) 
			root -> item = occorrenza_new(word);
		
		else 
			bist_insert(root, word);
			
		word = read_word();
	}
    printf("\n");
    
    //STAMPE
    printf("OCCORRENZE DI PAROLE NEL TESTO IN ORDINE ALFABETICO:\n");
	printf("****************************************************\n");
    bist_orderprint(root);
    
    
    printf("\n\nOCCORRENZE DI PAROLE NEL TESTO IN ORDINE INVERSO:\n");
	printf("****************************************************\n");
 	bist_invorderprint(root);
    
    
    //WHILE FILTRO
    
    printf("\n\nRICERCA DI PAROLE:\n");
	printf("******************\n");
	
	word = read_word();
	
   while(strcmp(word,"stop") != 0) {
    	printf("%s -> %d\n", word,bist_filter(root, word));
    	
    	word = read_word();
	}
    printf("\n");
	

	return 0;
}

void bist_insert(Bit_node root, char* word) {

	int res = strcmp(root -> item -> word, word);
	
	//printf("Controllato: %s con [%s]\n", root -> item -> word, word);
	
	if (res == 0) {
		root -> item -> n++;
		//printf("Incremento occorrenza di %s: %d\n", root -> item -> word, root -> item -> n);
	}
	else if (res > 0) {
		if (root -> l != NULL)
			bist_insert(root -> l , word);
		else {
			root -> l = bit_new(occorrenza_new(word));
			//printf("Inserisco sx: %s\n", word);
		}
	}
	else {
		if (root -> r != NULL)
			bist_insert(root -> r , word);
		else {
			root -> r = bit_new(occorrenza_new(word));
			//printf("Inserisco dx: %s\n", word);
		}
	}
}

void bist_orderprint( Bit_node p ) {
	
	if ( p ) {
		bist_orderprint( p -> l );
		bist_printnode( p );
		bist_orderprint( p -> r );
	
	}

}


void bist_invorderprint( Bit_node p ) {

	if ( p ) {
		bist_invorderprint( p -> r );
		bist_invorderprint( p -> l );
		bist_printnode( p );
	}
}
void bist_printnode(Bit_node p) {
	printf("%s -> %d\n", p -> item -> word, p -> item -> n);
}

int bist_filter(Bit_node root, char* word) {
	int res = strcmp(root -> item -> word, word);
	
	if (res == 0) {
		return root -> item -> n;
	}
	else if (res > 0) {
		if (root -> l != NULL)
			bist_filter(root -> l , word);
		else {
			return 0;
		}
	}
	else {
		if (root -> r != NULL)
			bist_filter(root -> r , word);
		else {
			return 0;
		}
	}
	
}

Occorrenza occorrenza_new(char* word) {
	Occorrenza o = malloc(sizeof(Occorrenza));
	o -> word = word;
	o -> n++;
	
	return o;

}

Bit_node bit_new( Occorrenza item ) {
	Bit_node n = malloc(sizeof(Bit_node));
	
	n -> item = item;
	n -> l = NULL;
	n -> r = NULL;
	
	return n;

}

char *read_word(void) {
	char *p, in;
	int n = 0, size = 2;
	
	p = malloc(size);
	
	while(( in = getchar()) != ' ') {
		if(in != '\n'){
			in = tolower(in);
			if(!ispunct(in)) {
				if( n >= size) {
					size *=2;
					p = realloc(p,size);

					
					if (!isalpha(in))  {
						p[n] = '\0';
						break;
					}
				}
				p[n++] = in;
			}
		} else{
			return p;
		}
	}
	return p;
}

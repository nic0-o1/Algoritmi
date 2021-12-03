#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
   int posti;
   char **nomi;
}Registro;



Registro* newBook(int);
void cancelBook(Registro*);
void book(Registro*,int, char*);
void cancel(Registro*, int);
void printBook(Registro*);
void move(Registro*, int,int);

char *read_word(void);
void *my_malloc(size_t);
void *my_realloc(void*, size_t);

int main( void ){

	Registro *registro = NULL;
	char input, *nome;
	int n, to;
	
	while( ( input = getchar () ) != 'f' ){

        switch(input){

            case 'b': // b n --> newBook(n)
		        scanf("%d", &n);
		        if (n <= 0)
		        	break;
		        if (registro != NULL)
		        	cancelBook(registro);
		        
		        registro = newBook(n);
		        break;

            case '+': // + k name --> book(k, name)
            	if(registro != NULL) {
            		scanf("%d", &n);
            		nome = read_word();
            		
            		if(n < 0 || n >=  registro -> posti)
            			break;
            			
            		book(registro, n,nome);
            	} 
            	else {
            		printf("Registro non inizializzato!\n");
            	}
            
            break;

            case '-': // - k --> cancel(k)
            	if(registro != NULL) {
            		scanf("%d", &n);
            		
            		if( n < 0 || n >= registro -> posti)
            			break;
            		
            		cancel(registro,n);
            	}
            	else {
            		printf("Registro non inizializzato!\n");
            	}

            break;

            case 'm': // m from to ---> move from to
            
            	if(registro != NULL) {
            		scanf("%d", &n);
            		scanf("%d", &to);
            		
            		if(n <= 0 || n >= registro -> posti || to < 0 || to >= registro -> posti)
            			break;
            		
            		move(registro,n,to);
            	}
            	else {
            		printf("Registro non inizializzato!\n");
            	}

            break;

            case 'p': // p ---> printBook()
            	if(registro != NULL) {
            		printBook(registro);
            	}
            	else {
            		printf("Registro non inizializzato!\n");
            	}

            break;

        }

    }
	return 0;
}

//Permette la cancellazione del registro
void cancelBook(Registro* registro) {
	for (char **nome = (registro -> nomi); nome < (registro ->nomi) + (registro -> posti); nome++)
		free(*nome);
		
	free(registro);
}

Registro* newBook(int n) {
	Registro *r = calloc(1, sizeof(Registro));
	r -> posti = n;
	r -> nomi = calloc(n, sizeof(char*));
	
	return r;
}

void book(Registro* registro,int num, char* nome) {
	if((registro -> nomi)[num] != NULL) {
		printf("Il posto è gia occupato!\n");
		return;
	}
	(registro -> nomi)[num] = nome;
}

/*Se il posto n è occupato, la prenotazione viene cancellata
 altrimenti viene visualizzato un messggio di errore*/
void cancel(Registro* registro , int n ) {
	if ((registro -> nomi)[n] == NULL) {
		printf("Posto non occupato!\n");
		return;
	}	
	free((registro -> nomi)[n]);
	(registro -> nomi)[n] = NULL;
	
}

/* Permette di effettuare uno spostamento all'interno del registro, solo se
il posto di destinazione è libero*/
void move(Registro* registro, int from ,int to) {
	if((registro -> nomi)[from] != NULL && (registro -> nomi)[to] == NULL) {
		(registro -> nomi)[to] = (registro -> nomi)[from];
		(registro -> nomi)[from] = NULL;
	}
	else {
		printf("Impossibile effettuare lo spostamento\n");
	}
}

void printBook(Registro* registro) {
	/*printf("REGISTER[0...%d]: \n", (registro -> posti -1));
	
	for(char **nome = registro ->nomi; nome < registro ->nomi + registro ->posti; nome++) {
		if( *nome != NULL) 
			printf("%d --> %s\n", nome-(registro->nomi), *nome);
	}*/
	
	printf("REGISTER[0..%d]:\n",(registro -> posti)-1);

    for(int i=0; i < (registro -> posti); i++){

        if(registro->nomi[i] != NULL)

            printf("[%d]->['%s']\n", i, registro->nomi[i]);

    }
}

char *read_word(void) {
	char *p, in;
	int n = 0, size = 2;
	
	p = malloc(size);
	
	while(( in = getchar()) != '\n') {
	
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
	return p;
}

void *my_malloc(size_t n) {
	void *p;
	p = malloc(n);
	if (p == NULL) {
	printf( "errore alloc\n" );
	exit(EXIT_FAILURE);
	} 
	return p;
}

void *my_realloc(void *p, size_t n) {
	p = realloc(p, n);
	if (p == NULL) {
	  printf("errore realloc\n");
	  exit(EXIT_FAILURE);
	}
	return p;
}

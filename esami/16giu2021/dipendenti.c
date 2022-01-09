#include <stdlib.h>
#include <stdio.h>

struct dipendente {
	char n;
	struct dipendente *supervisore;
	struct node *subordinato;
};


struct node {
	struct dipendente *info ;
	struct node * next ;
};

void stampaSubordinati(struct dipendente *d);
void stampaSubordinati(struct dipendente *d);
void stampaImpiegatiSopra(struct dipendente *d);
void stampaImpiegatiConSupervisore(struct node *imp);

int quantiSenzaSubordinati(struct node *imp);

struct node* add_dipendenti(struct node *dipendenti, struct dipendente *d);
void supervisore(struct dipendente *d);
void stampaImpiegatiConSupervisore(struct node *imp); 

struct dipendente *new_dipendente(char n);
struct node *new_node(struct dipendente *d);
struct node *list_insert(struct node *supMax, struct dipendente *toAdd, struct dipendente *supToAdd);

int main(void) {


	struct dipendente *A = new_dipendente('A');
	struct dipendente *B = new_dipendente('B');
	struct dipendente *C = new_dipendente('C');
	struct dipendente *D = new_dipendente('D');
	struct dipendente *E = new_dipendente('E');
	struct dipendente *F = new_dipendente('F');
	struct dipendente *G = new_dipendente('G');
	struct dipendente *H = new_dipendente('H');
	struct dipendente *I = new_dipendente('I');
	
	
	struct node *dipendenti = malloc(sizeof(struct node*));
	
	dipendenti = add_dipendenti(dipendenti, A);
	dipendenti = add_dipendenti(dipendenti, B);	
	dipendenti = add_dipendenti(dipendenti, C);
	dipendenti = add_dipendenti(dipendenti, D);
	dipendenti = add_dipendenti(dipendenti, E);
	dipendenti = add_dipendenti(dipendenti, F);
	dipendenti = add_dipendenti(dipendenti, G);
	dipendenti = add_dipendenti(dipendenti, H);
	dipendenti = add_dipendenti(dipendenti, I);
	
	A -> subordinato = list_insert(dipendenti, B,A);
	A -> subordinato = list_insert(dipendenti, C,A);
	A -> subordinato = list_insert(dipendenti, D,A);
	
	B -> subordinato = list_insert(dipendenti, E,B);
	B -> subordinato = list_insert(dipendenti, F,B);
	
	F -> subordinato = list_insert(dipendenti, I,F);
	
	G -> subordinato = list_insert(dipendenti, H,G);
	
	
	/*printf("Dipendenti senza subordinati: %d\n",quantiSenzaSubordinati(dipendenti));
	
	printf("Imipiegati sopra F\n");
	stampaImpiegatiSopra(F);
	
	stampaSubordinati(B);*/
	
	stampaImpiegatiConSupervisore(dipendenti);
	
	
	return 0;
}


struct node* add_dipendenti(struct node *dipendenti, struct dipendente *d) {
	
	struct node * new = new_node(d); 
	if(dipendenti -> info != NULL)
		new-> next = dipendenti;
	return new;

	
	
	/*struct node *curr, *prev;
	
	
	if(dipendenti -> info == NULL) {
		dipendenti = new_node(d);
		return;
	}
	
	for(curr = dipendenti, prev = NULL; curr != NULL; prev = curr, curr = curr -> next) {
		if(curr -> next == NULL) {
			curr -> next = new_node(d);
			return;
		}
	
	}*/

}



struct node *list_insert(struct node *dipendenti, struct dipendente *toAdd, struct dipendente *supToAdd){
	struct node *curr;
	
	for(curr = dipendenti; curr !=NULL; curr = curr -> next) {
		if((curr -> info -> n) == (supToAdd -> n)){
			
			toAdd -> supervisore = supToAdd;
			struct node * new = new_node(toAdd); 
			new -> next = curr -> info -> subordinato;
			return new;
			
			
			
			/*struct node *currS;
			
			for(currS = curr -> info -> subordinato; currS != NULL; currS = currS ->next) {
				if(currS -> next == NULL) { //aggiunto come ultimo subordinato
					currS -> next = new_node(toAdd);
					toAdd -> supervisore = supToAdd;
				}
			}*/
		}
	}
	
	
	
}

struct node *new_node(struct dipendente *d) {
	struct node *n = malloc(sizeof(struct node));
	
	n -> info = d;
	n -> next = NULL;
	
	return n;

}

struct dipendente *new_dipendente(char n) {
	struct dipendente *d = malloc(sizeof(struct dipendente));
	
	d -> n = n;
	d -> supervisore = NULL;
	d -> subordinato = NULL;
	
	return d;

}

void stampaImpiegatiSopra(struct dipendente *d) {

	if(d -> supervisore != NULL){
		printf("%c\n", d -> supervisore -> n);
		stampaImpiegatiSopra(d -> supervisore);
	} 
	else
		return;


}

int quantiSenzaSubordinati(struct node *imp) {
	int senza = 0;
	
	struct node *curr;
	
	for(curr = imp; curr != NULL; curr = curr ->next) {
		if(curr -> info -> subordinato == NULL)
			senza++;
	}
	return senza;

}


void stampaSubordinati(struct dipendente *d) {
	struct node *curr;
	
	printf("Elenco subordinati di: %c\n", d ->n);
	
	for(curr = d -> subordinato; curr != NULL; curr = curr -> next) {
		printf("%c ", curr -> info -> n);
	}	
	
	printf("\n");
}

void supervisore(struct dipendente *d) {
	printf("Supervisore di: %c => %c\n", d->n, d -> supervisore ->n);
}

void stampaImpiegatiConSupervisore(struct node *imp) {
	
	struct node *curr;
	
	for(curr = imp; curr != NULL; curr = curr -> next) {
		if(curr -> info -> supervisore != NULL){
			supervisore(curr -> info);
		}
	
	}
}




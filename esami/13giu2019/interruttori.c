#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


#define MAX_C 3

struct lampadina {
	int num;
	bool stato;	
};

typedef struct lampadina *Lampadina;

struct interruttore {
	int num;
	Lampadina *collegamenti;
	
};

typedef struct interruttore* Interruttore;


struct rete{
	Interruttore *interruttori;
	Lampadina *lampadine;
	int n;
};

typedef struct rete* Rete;


Rete crea_rete(int n);
Lampadina* crea_rete_lam(int n);
Lampadina crea_lampadina(int num);
Interruttore crea_interruttore(int i,int n, Lampadina *lam);
void stato_accensione(Rete rete, int *val);
void premi_interruttore(Rete rete, int num);
void stato_accensione(Rete rete, int *val);
void premi_in_sequenza(Rete rete, int m, int *val);
void stampa_stato(Rete r);

Rete crea_rete(int n) {
	
	Rete rete = malloc(sizeof(Rete));

	Interruttore *in = calloc(n, sizeof(Interruttore));
	
	Lampadina *la = crea_rete_lam(n);
	
	for(int i = 0; i < n; i ++) {
		in[i] = crea_interruttore(i,n,la);
	} 
	rete -> interruttori = in;
	rete -> lampadine = la;
	rete -> n = n;
	
	return rete;

}

Interruttore crea_interruttore(int i,int n, Lampadina *lam) {
	Interruttore in = malloc(sizeof(Interruttore));
	
	in -> num = i;
	in -> collegamenti = calloc(MAX_C, sizeof(Lampadina));
	
	if (i >= 1  && i <=  n - 2) {
		in -> collegamenti[0] = lam[i - 1];
		in -> collegamenti[1] = lam[i + 1];
	}
	
	else if (i == n -1) {
		in -> collegamenti[0] = lam[n - 2];
		in -> collegamenti[1] = lam[0];
	}
	
	else if (i == 0){
		in -> collegamenti[0] = lam[n-1];
		in -> collegamenti[1] = lam[1];
	}
	
	in -> collegamenti[2] = lam[i];
	
	return in;

}

Lampadina* crea_rete_lam(int n) {
	Lampadina *la = calloc(n, sizeof(Lampadina));
	
	for (int i = 0; i < n; i++) {
		la[i] = crea_lampadina(i+1);
	}
	
	return la;
}

Lampadina crea_lampadina(int num) {
	Lampadina l = malloc(sizeof(Lampadina));
	
	l -> num = num;
	l -> stato = false;
	
	return l;
}

void premi_interruttore(Rete rete, int num) {
	//printf("Ricevuto: %d\n", rete -> interruttori[num -1] -> num);
	for(int i = 0; i < MAX_C; i++) {
		//printf("i: %d\n", i);
		rete -> interruttori[num-1] -> collegamenti[i] -> stato = !rete -> interruttori[num-1] -> collegamenti[i] -> stato; 
	}
}


void stato_accensione(Rete rete, int *val) {
	for(int i = 0; i < rete -> n; i++) {
		rete -> lampadine[i] -> stato = val[i];
	}

}

void premi_in_sequenza(Rete rete, int m, int *val) {
	//printf("Seq %d\n",m);
	for(int i = 0; i < m; i++) {
		premi_interruttore(rete, val[i]);
		//printf("OK\n");
	}
}

void stampa_stato(Rete r) {
	for(int i = 0; i < r -> n; i++) {
		printf("%d ", r -> lampadine[i] -> stato);
	}
	printf("\n");
}

int main (void) {
	char in;
	bool canRead = true;
	int n;
	
	Rete rete;
	
	while(canRead) {
		scanf("%c", &in);
	
		switch(in) {
		
			case '+': {
				scanf("%d", &n);
				rete = crea_rete(n);
				break;
			}
				
			case 'o': {
				int val[n];
				for(int i = 0; i < n; i++) {
					scanf("%d", &val[i]); 
				}
				stato_accensione(rete, val);
				break;
			}
			case 'p':
				stampa_stato(rete);
				break;
				
			case 's': {
				int in;
				scanf("%d", &in);
				premi_interruttore(rete,in);
				break;
			}
			case 'S': {
				int m;
				scanf("%d",&m);
				int v[m];
				for(int i = 0; i< m; i++) {
					scanf("%d", &v[i]);
				}
				premi_in_sequenza(rete, m, v);
				break;
			}
			case 'f':
				canRead = false;
				break;
				
			case '\n': break;
				
			default:
				printf("Comando non riconosciuto\n");
				break;
		}
	
	
	
	}

}

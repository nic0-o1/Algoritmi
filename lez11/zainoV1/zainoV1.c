#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define WEIGHT 15


typedef struct {
	int p;
	int v;
}Oggetto;

Oggetto *new_obj(int p, int v);

Oggetto **read_objs(int n);

void print_obj(Oggetto *o);

void FindSolution(Oggetto **oggetti, int n, int *M);

int main(void) {

	int *val = calloc(WEIGHT, sizeof(int));
	
	int totObjs;
	
	scanf("%d",&totObjs);
	
	Oggetto **oggetti = read_objs(totObjs);
	
	FindSolution(oggetti, totObjs, val);
	
	/*for(int i = 0; i < WEIGHT; i++) {
		printf("%d ", val[i]);
	}*/
	
	printf("\n");

	return 0;
}

Oggetto *new_obj(int p, int v) {
	Oggetto *o = malloc(sizeof(Oggetto));
	
	o -> p = p;
	o -> v = v;
	
	return o;
	
}

Oggetto **read_objs(int n) {
	Oggetto **oggetti = calloc(n,sizeof(Oggetto));
	
	int p,v;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &p);
		scanf("%d",&v);
		
		oggetti[i] = new_obj(p,v);
	
	}
	return oggetti;
}


void print_obj(Oggetto *o) {
	printf("Peso: %d Valore: %d\n",o -> p , o -> v);

}

int max(int num1, int num2) {
	//printf("Max tra: %d e %d\n",num1,num2);
    return (num1 > num2 ) ? num1 : num2;
}


void FindSolution(Oggetto **Oggetti, int totObj, int *M){
    for (int i = 0; i < WEIGHT; i++) {
    	for(int j = 0; j < totObj; j ++) {
    		if(M[i+Oggetti[j] -> p] < Oggetti[j] -> v){
    			M[i+Oggetti[j] -> p] = M[i] + Oggetti[j] -> v;
   		 			for(int i = 0; i < WEIGHT; i++) {
						printf("%d ", M[i]);
					}
					printf("\n");
    		}
    	
    	}
    
    }
}











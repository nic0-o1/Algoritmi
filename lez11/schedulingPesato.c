#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
	int i;
	int f;
	int v;
} Intervallo;


Intervallo *new_int(int i,int f, int v);

Intervallo **read_int(int n);

void print_int(Intervallo *i);

void Ordina(Intervallo **arr, int n);

int setP(Intervallo **arr, int j);

int Opt(Intervallo **arr, int j, int *M);

void FindSolution(Intervallo **Intervalli, int j, int *M);

int main(void) {
	
	int n;
	scanf("%d",&n);
	
	Intervallo **intervalli = read_int(n);
	
	Ordina(intervalli,n);
	
	int val[n];
	
	for(int i = 0; i < n; i++) {
		val[i] = -1;
	}
	
	printf("Optimal value: %d\n",Opt(intervalli, n-1, val));
	FindSolution(intervalli, n-1, val);
	
	
	
	printf("\n");
	return 0;
}

Intervallo *new_int(int i,int f, int v) {
	Intervallo *in = malloc(sizeof( Intervallo));
	
	in -> i = i;
	in -> f = f;
	in -> v = v;
	
	return in;
}

Intervallo **read_int(int n) {

	int in,f,v;
	char c;
	
	Intervallo **intervalli = calloc(n, sizeof( Intervallo));
	
	for(int i = 0; i<n; i++) {
		scanf("%d", &in);
		scanf("%c", &c);  // salta -
		scanf("%d", &f);
		scanf("%d", &v);
	
		intervalli[i] = new_int(in,f,v);
	
	}
	
	return intervalli;
}

void print_int(Intervallo *i) {
	printf("%d-%d %d\n",i -> i, i->f, i-> v);

}

void Ordina(Intervallo **arr, int n)  {
	int i = 1;
	bool scambiato = false;
	
	do {
		scambiato = false;
		for(int j = 1; j < n; j++) {
			if(arr[j] -> f < arr[j-1] -> f) {
				Intervallo *tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
				scambiato = true;
			}
		}
		i++;
	
	}while(scambiato &&  i < n);


}


int setP(Intervallo **arr, int j) {

	int i = j-1;
	
	while(i >= 0) {
		if(arr[j] -> i >= arr[i] -> f) {
			return i;
		}
	
		i--;
	}
	return -1;

}

int max(int num1, int num2)
{
	//printf("Max tra: %d e %d\n",num1,num2);
    return (num1 > num2 ) ? num1 : num2;
}

int Opt(Intervallo **arr, int j, int *M) {
	if(j == -1){
        return -0;
    }else if(M[j] != -1){
        //printf("!=0\n");
        return M[j];
    }else{
        //printf("max\n");
        M[j] = max(arr[j]->v + Opt(arr, setP(arr,j), M),Opt(arr, j-1, M));
        return M[j];
    }

}

void FindSolution(Intervallo **Intervalli, int j, int *M){
    if(j == -1){
        //Nothing    
    }else{
        if((Intervalli[j]->v + M[setP(Intervalli, j)]) >= M[j-1]){
            printf("%d-%d %d\n",Intervalli[j]->i,Intervalli[j]->f,Intervalli[j]->v);
            FindSolution(Intervalli, setP(Intervalli, j), M);
        }else{
            FindSolution(Intervalli, j-1, M);
        }
    }
}









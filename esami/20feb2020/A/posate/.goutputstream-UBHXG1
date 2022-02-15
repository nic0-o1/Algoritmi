#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct listItem {
	char tipo;
	struct listItem* next;	
};

typedef struct listItem* ListItem;

struct robot {

	char sx,dx;
	ListItem pila;

};

typedef struct robot* Robot;

int r();
Robot new_robot();
ListItem new_item(char t);
void AddTop(Robot r, char t);
char Pop(Robot r);
char GetTop(Robot r);
bool IsEmpty(Robot r);
void stampaPila(Robot r) ;


int main (void) {
	
	printf ( "%d\n" , r() );
	
	return 0;
}

int r() {
	Robot r = new_robot();
	char d;
	
	int scatole = 0;
	
	while(true) {
		
		if(r -> sx == ' ' && r -> dx == ' ') {
			scanf("%c", &d);
			if(d == '\n') {
				break;
			}
			r -> sx = d;
			printf("sx %c\n",r -> sx);
			
		}
		else if(r -> sx != ' ' && r -> dx == ' ') {
			if( r -> pila != NULL) {
				char w = GetTop(r);
				if(w != r -> sx) {
					printf("dx pop %c\n",w);
					r -> dx = Pop(r);
				}
				else {
				scanf("%c", &d);
				if(d == '\n') {
					break;
				}
			 	r -> dx = d;
				printf("dx %c\n",d);
				}
			}
			else {
				scanf("%c", &d);
				if(d == '\n') {
					break;
				}
			 	r -> dx = d;
				printf("dx %c\n",d);
			}
		}
		
		if((r -> sx == 'F' && r -> dx == 'K') || (r -> dx == 'F' && r -> sx == 'K')) {
			printf("+1\n");
			scatole++;
			r -> sx = ' ';
			r -> dx = ' ';
		}
		
		else if(r -> sx == r -> dx){
			printf("dx push %c\n",r -> dx);
			AddTop(r,r->dx);
			r -> dx = ' ';
		}
	
	
	}
	
	printf("%d ", scatole);
	
	r -> sx == ' ' ? printf("Z ") : printf("%c ", r -> sx);
	
	stampaPila(r);
	
	return IsEmpty(r) ?  0 :  1;
}

	

Robot new_robot() {

	Robot r = malloc(sizeof(Robot));
	
	r -> sx = ' ';
	r -> dx = ' ';
	r -> pila = NULL;
	
	return r;	

}

void AddTop(Robot r, char t){

	ListItem item = new_item(t);
	
	if(r -> pila == NULL)
		r -> pila = item;
		
	else{
		ListItem tmp = r -> pila;
		r -> pila = item;
		r -> pila -> next = tmp;
	}
}

char Pop(Robot r) {
	
	char c = r -> pila ->tipo;
	
	r -> pila = r -> pila -> next;
	
	return c;

}

bool IsEmpty(Robot r) {
	return r -> pila == NULL;
}

ListItem new_item(char t) {

	ListItem l = malloc(sizeof(ListItem));

	l -> tipo = t;
	l -> next = NULL;
	
	return l;	
}

char GetTop(Robot r) {

	return r -> pila != NULL ? r -> pila -> tipo : ' ';

}
void stampaPila(Robot r) {
	for(ListItem l = r -> pila; l != NULL; l = l -> next){
		printf("%c ", l -> tipo);
	}
	printf("\n");

}





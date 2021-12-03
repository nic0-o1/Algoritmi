#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool Palindroma(char *f, char *l){

    while(f < l){

        printf("%c %c\n", *f, l);

        if(f == *l){

            f++;
            l--;

        }else{

            return false;

        }



    }

    return true;

}



int main( int argc, char *argv[]) {

    //char c[]="ingegni";

    for(int i =1; i <argc ;i++){

        if(Palindroma(&argv[i][0], &argv[i][strlen(argv[i])-1])){

            printf("%s -> Palindroma\n", argv[i]);

        }else{

            printf("%s -> Non palindroma\n", argv[i]);

        }

    }

    return 0;

}

#include <stdio.h>



int main(void){

    int array[100],n = 0;



    do{

        scanf("%d", &array[n]);

        int i = n;

        while(array[i] < array[i-1]){

            int temp = array[i-1];

            array[i-1] = array[i];

            array[i] = temp;

            i--;

        }

        n++;

    } while (n<100 && array[0] != 0);





    for(int i = 0; i < n; i++){

        printf("[%d]", array[i]);

    }

    printf("\n");



    return 0;

}

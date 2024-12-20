
/*
 * Author: Yolia Simon
 * Date: 21/11/24
*/

//Program description: Write a program to calculate the first N square numbers, where N is supplied by
//the user at runtime

#include <stdio.h>
#include <stdlib.h>

//function prototypes



int main(void) {

    printf("This program calculates the first N square numbers.\n");

    int N = 0;

    //asking user for N
    printf("Enter a value for N: ");
    do {
            scanf("%d",&N);

            if (N <= 0) {
            printf("\nError: Please enter a valid input.\n\n");
            while (getchar() != '\n');
            }
        }while (N <= 0);

    //allocating memory here
    long* squares = (long*)malloc(N*sizeof(long));
    if (squares==NULL) {
        fprintf(stderr, "Error - memory not allocated\n");
        exit(1);
    }

    //Calculate squares
    for (long i=0; i<N; i++) {
        squares[i] = (i+1)*(i+1);
    }

    //Print squares
    for (long i=0; i<N; i++) {
        printf("%ld ", squares[i]);
    }
    printf("\n");

    //Release memory
    free(squares);
    squares = NULL;

return 0;

}

//functions go here



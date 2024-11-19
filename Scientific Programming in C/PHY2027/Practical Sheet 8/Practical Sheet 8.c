/*
 * Author: Yolia Simon
 * Date: 14/11/24
*/

//Program description: This C program allows the user to perform operations on an array of numbers. The program provides a menu with three
//options: sum an array, multiply an array and quit. The program includes error checking to ensure the array size does not exceed the maximum,
//allowed size and that the multiplier is positive. This task demonstrates basic array handling, user input, and function utilization in C.

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 1000

//function prototypes


double sum_array(double array[], int size);

void multiply_array(double array[], int size, double multiplier);

int main(void) {

    printf("What would you like to do today? Please choose from the following options:");
    printf("\n1. Sum an array");
    printf("\n2. Multiply an array");
    printf("\n3. Quit");

    int option;
    double array[MAX_SIZE]; //declaring an array to hold the data
    int size;
    double multiplier;

    printf("\n\nEnter your choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("\nSum an array: To start, please enter the array size:");

        //asking user for array size
        do {
            scanf("%d",&size);

            if (size > MAX_SIZE || size <= 0) {
            printf("\nError: Please enter a valid input.\n\n");
            while (getchar() != '\n');
            }

        }while (size <= 0);

        //asks the user for the array values

        printf("Please enter your array values: \n\n");
        for (int i = 0; i < size; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%lf", &array[i]);
        }

        //prints results to console
        printf("\nHere are your results~\n\n");
        double x;
        x = sum_array(array,size);
        printf("\nSum of array = %.5lf", x);

        }

        else if (option == 2) {
        printf("\nMultiply an array: To start, please enter the array size: ");

        //asking user for array size
        do {
            scanf("%d",&size);

            if (size > MAX_SIZE || size <= 0) {
            printf("\nError: Please enter a valid input.\n\n");
            while (getchar() != '\n');
            }

        }while (size <= 0);
        //asks the user for the array values

        printf("Please enter your array values: \n\n");
        for (int i = 0; i < size; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%lf", &array[i]);
        }


        //asking user for constant multiplier
        printf("\nPlease enter the constant multiplier: ");
        do {
            scanf("%lf",&multiplier); //could change this to a function

            if (multiplier <= 0) {
            printf("\nError: Please enter a positive integer above zero.\n\n");
            while (getchar() != '\n');
            }

        }while (multiplier <= 0);

        //prints results to console
        printf("\nHere are your results~\n");
        multiply_array(array,size,multiplier);
        for (int i = 0; i < size; i++){
            printf("\nMultiplication of array = %.5lf", array[i]);
        }


    } else if (option == 3){
        printf("Exiting the program...");
        return (1);

    } else if (option != 1 || option != 2 || option != 3){ //create error message
        printf("Incorrect input. Exiting the program...");
        return 1;
    }
return 0;

}

//functions go here

double sum_array(double array[], int size){  //sum array function

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;

}

void multiply_array(double array[], int size, double multiplier){ //multiply array function

    for(int i = 0; i < size; i++){
        array[i] *= multiplier;
    }
}

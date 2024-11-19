/*
 * Author: Yolia Simon
 * Date: 06/11/24
*/

//Program description: This program lets the user choose between three options:
// a) Test whether a number is prime.
// b) Test whether a number is perfect.
// c) Quit the program

#include <stdio.h>
#include <math.h>
#define PI 3.14159265

//call the functions here

int checkPrime(int num); //checks for prime numbers

int checkPerfect(int num); //checks for perfect numbers


int main(void) {

    printf("Please select any option from the menu:\n\n");
    printf("1. Test whether a number is prime\n");
    printf("2. Test whether a number is perfect\n");
    printf("3. Quit\n");

    int option;
    int num;

    printf("\n\nEnter your choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("\nEnter a valid number to test.");

        //asking user input
        do {
            scanf("%d",&num);

            if (num <= 0) {
            printf("\nError: Please enter a valid input.\n\n");
            while (getchar() != '\n');
            }

        }while (num <= 0);


        //testing

        if (checkPrime(num)){
            printf("%d is a prime number\n", num);
        } else {
            printf("%d is not a prime number\n", num);
        }

        }

        else if (option == 2) {
        printf("\nEnter a valid number to test: \n");

        //asking user input
        do {
            scanf("%d",&num);

            if (num <= 0) {
            printf("\nError: Please enter a valid input.\n\n");
            while (getchar() != '\n');
            }

        }while (num <= 0);

        //testing

        if (checkPerfect(num)){
            printf("%d is a perfect number\n", num);
        } else {
            printf("%d is not a perfect number\n", num);
        }

        }


        else if (option == 3){
        printf("Exiting the program...");
        return (1);

        }

        else if (option != 1 || option != 2 || option != 3){ //create error message
            printf("Incorrect input. Exiting the program...");
            return 1;
        }


return 0;

}

//functions go here

int checkPrime(int num){

    if (num < 2) return 0; //not prime
    if (num <= 0) return -1; //error
    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0) return 0; //composite
    return 1; //prime

}

int checkPerfect(int num){

    if (num <= 0) return -1; //error

    int sum_of_factors = 0;
    for (int i = 1; i < num; i++)
        if (num % i == 0) sum_of_factors += i;
    return (num == sum_of_factors);

}


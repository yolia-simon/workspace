/*
 * Practical class 4
 * Author: Yolia Simon
 * Date: 17/10/24
*/

//Program description: Write a program that lets the user choose between three options:
// a) Calculate the sum of a series of integers (as many as the user wishes).
// b) Calculate the value of the quadratic y = ax2 + bx + c, where a, b, c and x are floating-point
// numbers entered by the user.
// c) Quit the program.
// The program must (i) allow the user to repeat the menu options as many times as desired and (ii)
// check that the user only enters one of the three menu options.

#include <stdio.h>
#include <math.h>

//functions go here


//function for quadratic
double calc_quad(float a, float b, float c, float x){
    float y = 0.0;
    y = (a * x * x) + (b * x) + c;
    return y;
}


int main(void) {

    printf("What would you like to do today? Please choose from the following options:");
    printf("\n1. Sum calculations");
    printf("\n2. Quadratic calculations");
    printf("\n3. Quit");

    int option;

    printf("\n\nEnter your choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("To start, enter the numbers you wish to sum. To produce the result, press 0");
        int sum = 0;
        int total;
        do {
            printf("\nEnter a number:");
            scanf("%d", &total);
        }
        while (total == 0); { // error here
            printf("\nHere is the sum of your numbers~");
            sum += total;
        }

        }

        else if (option == 2) {
        printf("To calculate a quadratic in the form of y = ax^2 + bx + c, please enter 4 numbers for a, b, c and x");

        int a, b, c, x;

        printf("\nEnter value for a: ");
        scanf("%d", &a);
        printf("\nEnter value for b: ");
        scanf("%d", &b);
        printf("\nEnter value for c: ");
        scanf("%d", &c);
        printf("\nEnter value for x: ");
        scanf("%d", &x);

        double result;
        result = calc_quad(a, b, c, x);

        printf("Here is the value of your quadratic: %.2f \n", result);
        //use quadratic function
        //use floats

    } else if (option == 3){
        printf("Exiting the program...");
        return (1);

    } else if (option > 3){
        printf("Exiting the program...");
        return (1);
    }




  return 0;

}

/*
 * Here, you will put your functions if there are any. Before every function, you will need to put some comments describing what the function is doing.
 * If you have more than one function, you will put a short description at the top of every function. It could be "This function does this or that",
 * or you may want to relate them to a specific question in the assessment, for example "Function definition for question N".
 */

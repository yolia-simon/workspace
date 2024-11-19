/*
 * Assessment 2 for PHY2027
 * Author: Yolia Simon
 * Date: 06/11/24
*/

/*
 * Program description: This is a C program that calculates the Taylor series approximation of sin(x), for given angles x.
 * The program computes this approximation by summing the first n terms of the Taylor series expansion. The program also includes
 * input validation for user-provided values and outputs results that can be used for further analysis or plotting.

*/


#include <stdio.h>
#include <math.h>
#define PI 3.14159265

#define array_size 5  //used to prevent 'magic numbers'


//prototype function declarations here

double factorial(int n);

double sum_sin_series(double x, int n);

int main(void) {

    double x_values[array_size]; //declaring the array for x values

    printf("This code calculates the Taylor series approximation of sin(x) using n terms.\n");
    printf("Afterwards, the code will output some results that can be used for plotting in Excel.\n\n");

    //asks the user for 5 positive integers

    printf("Please enter 5 numerical values of x (in degrees): \n\n");
    for(int i = 0; i < array_size; i++){
        int valid_input1;

        do {
            valid_input1 = scanf("%lf",&x_values[i]);

            if (valid_input1 != 1 || x_values[i] < 0){
                printf("\nError: Please enter a valid positive integer for x.\n\n");
                while (getchar() != '\n'); //deletes the incorrect input
            }

            }while (valid_input1 != 1 || x_values[i] < 0);
    }

    //prompt user for the number of terms for the Taylor series

    int n; //number of terms for the Taylor series approximation
    printf("\nPlease enter how many terms you would like to use for the Taylor series approximation: ");
    do {
        int valid_input2;
        valid_input2 = scanf("%d",&n);

        if (valid_input2 != 1 || n <= 0) {
        printf("\nError: Please enter a positive integer above zero.\n\n");
        while (getchar() != '\n');
        }

    }while (n <= 0);

    //prints results to screen
    printf("\nHere are your results~\n\n");

    for (int i = 0; i < array_size; i++){
        double sin_x1, approx_sin_x1;
        sin_x1 = sin(x_values[i] * (PI/180)); //conversion from deg to rad
        approx_sin_x1 = sum_sin_series(x_values[i], n); //taylor series approx.
        printf("\nFor x = %.2lf, sin(x) = %.5lf, Taylor series approximation = %.5lf\n", x_values[i], sin_x1,approx_sin_x1);
    }

    //extending program for x = 0° - 360° with n = 6
    printf("\nNow calculating values for x = 0 - 360 with n = 6...\n ");

    FILE * fptr;
    fptr = fopen("sin_taylor_series.csv","w"); //creating a csv file using write mode
    fprintf(fptr,"x, sin(x), Taylor_approx\n"); //prints the column headings

    for(int x = 0; x <= 360; x++){
        double sin_x2, approx_sin_x2;
        sin_x2 = sin(x * (PI/180)); //conversion from deg to rad
        approx_sin_x2 = sum_sin_series(x, 6); //taylor series approx.
        fprintf(fptr,"%d,%.5f,%.5f\n",x, sin_x2, approx_sin_x2); //writes data to file
    }

    fclose(fptr);
    printf("\nValues have been successfully saved to sin_taylor_series.csv for plotting in Excel~\n");

  return 0;

}

//functions go here

//factorial function

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++){ //multiplies a number by every number below it until 1
        result *= i; //can also be written as 'result = result * i'
    }

    return result;
}

//function to calculate the Taylor series approximation for sin(x)

double sum_sin_series(double x, int n){
    x = x * (PI/180); //conversion from deg to rad

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double term;
        term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1); //for calculating each Taylor series term
        sum += term;
    }
    return sum;
}

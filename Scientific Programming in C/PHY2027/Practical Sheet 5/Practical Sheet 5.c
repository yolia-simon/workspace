/*
 * Author: Yolia Simon
 * Date: 06/11/24
*/

//Program description: Write a program that, in addition to main(), contains three functions:
// a) double square(double num) which takes a double parameter and returns its square.
// b) int isOdd(int num) which takes an integer parameter and returns 0 if num is even and 1 if
//    it is odd.
// c) void printCircleProps(double radius) which takes a radius and prints out the
//    diameter, circumference and area of the corresponding circle

#include <stdio.h>
#include <math.h>
#define PI 3.14159265

double square(double num); //call the functions here
int isOdd(int num);
void printCircleProps(double radius);


int main(void) {

    const int num = 6;

    square(num);
    isOdd(num);
    printCircleProps(num);


return 0;

}

//functions

double square(double num) {
    return num * num;
}

int isOdd(int num) {
    return num / 2;
}

void printCircleProps(double radius) {
    printf("A circle with radius %g has:\n", radius);
    printf("\nDiameter: %g",radius*2);
    printf("\nCircumference: %g",2*PI*radius);
    printf("\nArea: %g",PI*radius*radius);
}


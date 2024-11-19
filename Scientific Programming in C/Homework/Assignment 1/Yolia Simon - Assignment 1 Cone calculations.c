/*
 * Assessment 1 for PHY2027
 * Author: Yolia Simon
 * Date: 04/10/2024
*/

/*
 * Program description: This is a C program that asks the user to input the radius r and height h of a right circular cone and then
 * calculates its slant height s, opening angle θ in degrees, volume and total surface area
*/

#include <stdio.h>
#include <math.h>

int main(void) {

    const double PI = 3.14159265;

    float radius, height; //defining variables for radius and height

    printf("This code calculates the slant height, opening angle, volume and surface area of a right circular cone.\n");

    printf("\nPlease enter a numerical value for the radius of the cone: ");
    scanf("%f", &radius);

    //if statements below check for positive input values
    if (radius <= 0) {
        printf("Error: Radius must be a positive value.\n");
        return(1);
    }

    printf("Please enter a numerical value for the height of the cone: ");
    scanf("%f", &height);

    if (height <= 0) {
        printf("Error: Height must be a positive value.\n");
        return(1);
    }

    float s_height, theta, volume, s_area; //defining variables for slant height, theta (opening angle), volume and total surface area*/

    s_height = sqrt((radius * radius) + (height * height));

    theta = atan(radius / height) * (180 / PI);

    volume = (PI * radius * radius * height)/3;

    s_area = PI * (radius + height) * radius;

    printf("\nHere are your calculations rounded to 2 d.p~\n\n");

    printf("Slant height (s): %.2f\n", s_height);

    printf("Opening angle (theta): %.2f\n", theta);

    printf("Volume (V): %.2f\n", volume);

    printf("Total surface area (A): %.2f\n", s_area);

return 0;

}

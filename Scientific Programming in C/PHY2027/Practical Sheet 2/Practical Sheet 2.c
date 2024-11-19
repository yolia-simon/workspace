/*
 * Author: Yolia S
 * Date: 03/10/24
*/

/*
 * Program description: Write a piece of code that calculates and prints
 * to screen the surface areas and volumes of three geometric figures:
 * a sphere, a cylinder and a cuboid
 */

#include <stdio.h>

int main(void) {

    const double PI = 3.14159265;

    float radius1, s_area1, volume1; /*sphere surface A and V*/

    printf("This code calculates the surface areas and volumes for a sphere, cylinder and a cuboid.");

    printf("\nEnter value for the radius of the Sphere : ");
    scanf("%f", &radius1);

    s_area1 = 4 * PI * radius1 * radius1;
    volume1 = (4/3) * PI * radius1 * radius1 * radius1;

    printf("\nSurface Area of Sphere : %f", s_area1);
    printf("\nVolume of Sphere : %f", volume1);

    float radius2, height1, s_area2, volume2;  /*cylinder surface A and V*/

    printf("\nEnter value for the radius of the Cylinder : ");
    scanf("%f", &radius2);
    printf("\nEnter value for the height of the Cylinder : ");
    scanf("%f", &height1);

    s_area2 = (2 * PI * radius2 * radius2) + (2 * PI * radius2 * height1);
    volume2 = PI * radius2 * radius2 * height1;

    printf("\nSurface Area of Cylinder : %f", s_area2);
    printf("\nVolume of Cylinder : %f", volume2);

    float length, height2, width, s_area3, volume3;  /*cuboid surface A and V*/

    printf("\nEnter value for the length of the Cuboid : ");
    scanf("%f", &length);
    printf("\nEnter value for the height of the Cuboid : ");
    scanf("%f", &height2);
    printf("\nEnter value for the width of the Cuboid : ");
    scanf("%f", &width);


    s_area3 = 2 * ((length*width)+(width*height2)+(length*height2));
    volume3 = length * width * height2 ;

    printf("\nSurface Area of Cuboid : %f", s_area3);
    printf("\nVolume of Cuboid : %f", volume3);

return 0;
}

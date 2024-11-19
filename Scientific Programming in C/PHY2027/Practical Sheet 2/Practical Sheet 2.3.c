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

    FILE *fptr;
    fptr = fopen("sphere.txt", "r");

    float radius;
    fscanf(fptr, "%f", &radius);

    float s_area1, volume1;
    s_area1 = 4 * PI * radius * radius;
    volume1 = (4/3) * PI * radius * radius * radius;

    printf("\nSurface Area of Sphere : %f", s_area1);
    printf("\nVolume of Sphere : %f", volume1);

    fclose(fptr);

    FILE *fptr2;
    fptr2 = fopen("cylinder.txt", "r");

    float radius2, height1;
    fscanf(fptr2, "%f", &radius2);
    fscanf(fptr2, "%f", &height1);

    float s_area2, volume2;  /*cylinder surface A and V*/

    s_area2 = (2 * PI * radius2 * radius2) + (2 * PI * radius2 * height1);
    volume2 = PI * radius2 * radius2 * height1;

    printf("\nSurface Area of Cylinder : %f", s_area2);
    printf("\nVolume of Cylinder : %f", volume2);

    fclose(fptr);

    FILE *fptr3;
    fptr3 = fopen("cuboid.txt", "r");

    float length, height2, width;
    fscanf(fptr3, "%f", &length);
    fscanf(fptr3, "%f", &height2);
    fscanf(fptr3, "%f", &width);

    float s_area3, volume3;  /*cuboid surface A and V*/

    s_area3 = 2 * ((length*width)+(width*height2)+(length*height2));
    volume3 = length * width * height2 ;

    printf("\nSurface Area of Cuboid : %f", s_area3);
    printf("\nVolume of Cuboid : %f", volume3);

    fclose(fptr);

return 0;
}


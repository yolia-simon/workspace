/*
 * Assessment 1 for PHY2027
 * Author: Yolia Simon
 * Date: 04/10/2024
*/

/*
 * Program description: This is a C program that reads the 'exam_marks.txt' file and then calculates the average and standard deviation
 * for physics, mathematics and both subjects together.
 */

#include <stdio.h>
#include <math.h>

/*Functions go here*/

//function that calculates mean(average):
double calc_mean(int tot[], int N){
    double sum = 0.0;
    for (int x = 0; x < N; x++){ // ++ is shorthand for x=x+1 (increments)
        sum += tot[x]; //shorthand for sum = sum + tot
    }
    return sum / N;
}

//function that calculates standard deviation:
double calc_stdev(int tot[], int N, double mean){
    double devi_sum = 0.0;
    for (int x = 0; x < N; x++){
        devi_sum += pow((tot[x] - mean), 2); //deviation sum
    }
    return sqrt(devi_sum/N);
}


int main(void) {
    FILE *fptr;
    fptr = fopen("exam_marks.txt", "r+");  //error message
    if (fptr == NULL) {
        printf("Error: File could not be opened.");
        return(1);
    }

    int physics[5], maths[5], combin[10]; //defining variables to store data in

    //reading physics and maths exam marks from the file
    fscanf(fptr, "%*[^:]: %d %d %d %d %d", &physics[0], &physics[1], &physics[2], &physics[3], &physics[4]);
    fscanf(fptr, "%*[^:]: %d %d %d %d %d", &maths[0], &maths[1], &maths[2], &maths[3], &maths[4]);

    //storing physics and maths marks in 'combined' array
    for (int x = 0; x < 5; x++){
        combin[x] = physics[x];
        combin[x + 5] = maths[x];
    }


    //calculating all the means
    double phys_mean, maths_mean, combin_mean;

    phys_mean = calc_mean(physics, 5);

    maths_mean = calc_mean(maths, 5);

    combin_mean = calc_mean(combin, 10);

    //calculating all the standard deviations
    double phys_stdev, maths_stdev, combin_stdev;

    phys_stdev = calc_stdev(physics, 5, phys_mean);

    maths_stdev = calc_stdev(maths, 5, maths_mean);

    combin_stdev = calc_stdev(combin, 10, combin_mean);


    fclose(fptr);


    //opening the file to append results at the end
    fptr = fopen("exam_marks.txt", "a");
    if (fptr == NULL) {
        printf("Error: File could not be opened for appending.\n");
        return (1);
        }

    //appending all results rounded to 2 d.p
    fprintf(fptr, "\n\nPhysics - Average: %.2f \n", phys_mean);

    fprintf(fptr, "Maths - Average: %.2f \n", maths_mean);

    fprintf(fptr, "Combined - Average: %.2f \n\n", combin_mean);

    fprintf(fptr, "Physics - Standard Deviation: %.2f \n", phys_stdev);

    fprintf(fptr, "Maths - Standard Deviation: %.2f \n", maths_stdev);

    fprintf(fptr, "Combined - Standard Deviation: %.2f \n", combin_stdev);

    fprintf(fptr, "\n\nThese results show the average performance and standard deviation in the marks of 5 students for Physics, Mathematics and both subjects combined.");


    fclose(fptr);


    printf("Results have now been appended to the file~");

return 0;

}

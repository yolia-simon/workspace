
/*
 * Author: Yolia Simon
 * Date: 21/11/24
*/

//Program description: Write a simple program to practise the basic use of pointers,
//including how to declare, initialise and print them.

#include <stdio.h>
#include <math.h>

char c = 'S';
char* pc = &c;

int i = 91;
int* pi = &i;

double d = 3.14159;
double* pd = &d;

int main(void) {

    //for variable c
    printf("c = %c, Address of c = %p, Value pointed by pc = %c\n", i, pc, *pc);
    i++;
    printf("New c = %c, Address of new c = %p, New value pointed by pc = %c\n", c, pc, *pc);
    pc++;
    printf("New c = %c, Address of new c = %p, New value pointed by pc = %c\n\n", c, pc, *pc);

    //for variable i
    printf("i = %d, Address of i = %p, Value pointed by pc = %d\n", i, pi, *pi);
    i++;
    printf("New i = %d, Address of new i = %p, New value pointed by pc = %d\n", i, pi, *pi);
    pi++;
    printf("New i = %d, Address of new i = %p, New value pointed by pc = %d\n\n", i, pi, *pi);

    //for variable d
    printf("d = %lf, Address of d = %p, Value pointed by pd = %lf\n", d, pd, *pd);
    d++;
    printf("New d = %lf, Address of new d = %p, New value pointed by pd = %lf\n", d, pd, *pd);
    pd++;
    printf("New d = %lf, Address of new d = %p, New value pointed by pd = %lf\n", d, pd, *pd);


return 0;

}


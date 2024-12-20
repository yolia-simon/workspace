
/*
 * Author: Yolia Simon
 * Date: 21/11/24
*/

//Program description: Write and test a function that converts single characters to uppercase

#include <stdio.h>
#include <string.h>

//function prototypes

void to_upper_case(char *ch);

int main(void) {

    //testing with single letters
    char ch1 = 'a';
    printf("Character before: %c\n", ch1);
    to_upper_case(&ch1);
    printf("Character after: %c\n", ch1);

    //testing with string
    char str[] = "Welcome!";
    printf("\nString before: %s", str);
    for (int i=0; i<strlen(str); i++){
        to_upper_case(&str[i]);
    }
    printf("\nString after: %s\n", str);

return 0;

}

//functions go here

void to_upper_case(char *ch){
    if (*ch < 97 || *ch > 122){ //in ASCII the lowercase letters are between 97 ('a') and 122 ('z')
        return; //this is for if the letter is already uppercase
    }else {
        *ch = *ch - 32;
    }

}


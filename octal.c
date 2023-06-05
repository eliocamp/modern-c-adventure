
/* 
4- Expressions 
    Writes an integer in octal.
    This creates an integer decimal representation of
    the octal number. It works but it's not generalisable 
    to any base greater than 10.

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc , char* argv[argc+1]) {
    int number = atoi(argv[1]);
    int octal = 0;
    size_t i = 0;

    do {
        octal = octal + (number % 8)*pow(10, i);
        number = number / 8;
        i++;
    } while (number != 0);

    printf("%d\n", octal);
}
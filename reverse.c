
/* 
4- Expressions 
    Reverses a number supplied as command line argument
    */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc , char* argv[argc+1]) {
    int number = atoi(argv[1]);
    
    do {
        printf("%i", number % 10 );  // Print last digit
        number = number / 10;        // Remove last digit
    } while (number != 0);   
    printf("\n");
}
/* LISTING 3.1. Computing multiplicative inverses of numbers */

#include <stdlib.h>
#include <stdio.h>

/* lower and upper iteration limits centered around 1.0 */
static double const eps1m01 = 1.0 - 0x1P-01;   // 0.5  WHY??!?!?
static double const eps1p01 = 1.0 + 0x1P-01;   // 1.5
static double const eps1m24 = 1.0 - 0x1P-24;   // Slightly less than 1
static double const eps1p24 = 1.0 + 0x1P-24;   // Slightly more than 1

/* Command line arguments are processed with two arguments
      argc: [int] the number of command line arguments
      argv: [char*] a (pointer) array which points to each argument. The first one is the name of the program. Its length is argc+1 because there's an extra NULL pointer to terminate the array.
      https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.htm
      https://stackoverflow.com/questions/63867125/what-is-the-reason-for-using-argvargc-1-instead-of-just-argv
 */
int main(int argc , char* argv[argc+1]) {
    /* i starts at 1 instead of 0 because argv[0] is the program name */

    for (int i = 1; i < argc; ++i) { // process args
        /*
        strtod converts char to double.
        It actually converts the first part of a char that
        resembles a double, so strtod("123 abc", NULL)
        The second argument is a pointer that will be
        set to the position of the rest of the string that
        wasn't parsed as a number.
        https://cplusplus.com/reference/cstdlib/strtod/
         */
        double const a = strtod(argv[i], 0) ; // arg - > double

        /*
        This gets an initial guess that's a power of 2 and that's
        relatively close to 1/a.
        0.5 < a*x < 1.5
         */
        double x = 1.0;
        for (;;) {
            // by powers of 2
            double prod = a*x;
            if (prod < eps1m01) {   // a < 1/(x*2)
                x *= 2.0;
            } else if ( eps1p01 < prod ) {  // Greater than 1.5
                x *= 0.5;
            } else {
                break ;
            }
        }

        printf("first guess is: %f\n", x);


        for (;;) {
            // Heron approximation
            /* Note that this is actually Newton's method.
            To find the zero of a function f(x), you start with a
            first guess and then iterate with

            x_(n+1) = x_n - f(x_n)/f'(x_n)

            In this case, f(x) = 1/x - a, for which f(1/a) = 0
            and f'(x) = -1/x^2. Putting it together:

            x_(n+1) = x_n*(2 - a*x_n)

            https://en.wikipedia.org/wiki/Multiplicative_inverse#Algorithms
            */
            double prod = a*x;
            if (( prod < eps1m24 ) || ( eps1p24 < prod )) {
                x *= (2.0 - prod);
            } else {
                break ;
            }
        }
        printf("heron: a=%.5e, \tx=%.5e, \ta*x=%.12f\n",
                a, x, a*x);
    }
    return EXIT_SUCCESS ;
}

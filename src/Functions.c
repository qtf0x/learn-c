/**
 * @file Functions.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-20
 *
 * @brief Functions are FUN.
 */

#include <stdio.h>

/* function declaration */
int foo(int bar);

int main() {
    // functions receive either a fixed or variable amount of arguments
    // functions can only return one value, or return no value

    /* calling foo from main */
    printf("The value of foo is %d\n", foo(1));

    return 0;
}

int foo(int bar) { return bar + 1; }

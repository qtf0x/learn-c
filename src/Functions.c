/**
 * @author qtf0x
 * @date 20.05.2022
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

/**
 * @file Recursion.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-26
 *
 * @brief It's just ... recursion.
 */

#include <stdio.h>

unsigned int multiply(unsigned int x, unsigned int y);

int main() {
    printf("3 times 5 is %d\n", multiply(3, 5));

    return 0;
}

unsigned int multiply(unsigned int x, unsigned int y) {
    if (x == 1) {
        // base case
        return y;
    } else if (x > 1) {
        // recursive step
        return y + multiply(x - 1, y);
    }

    // catch scenario when x is 0
    return 0;
}

/**
 * @file Types.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-16
 *
 * @brief Basic use of primitive types.
 */

#include <stdio.h>

// before C99, there's no boolean type
#define BOOL char
#define FASLE 0
#define TRUE 1

// C99 added a library for booleans
#include <stdbool.h>

int main() {
    int a = 0, b = 1, c = 2, d = 3, e = 4;
    a = b - c + d * e;
    printf("%d - %d + %d * %d = %d\n", b, c, d, e, a);

    int f = 3;
    float g = 4.5;
    double h = 5.25;

    float sum = f + g + h;

    printf("The sum of f (%d), g (%f), and h(%lf) is %f.\n", f, g, h, sum);

    return 0;
}

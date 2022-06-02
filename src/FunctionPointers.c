/**
 * @author qtf0x
 * @date 01.06.2022
 *
 * @brief Like most things in C, this is more straightforward than C++.
 */

#include <stdio.h>
#include <stdlib.h> // for qsort()

void someFunction(int arg);

int compare(const void* left, const void* right);

int main() {
    // function pointers require a return type, identifier, and argument type
    void (*pf)(int) = &someFunction;

    printf("We're about to call someFunction() using a pointer!\n");
    pf(5);
    printf("Wow that was cool. Back to main now!\n");

    /* Function pointers are commonly used for generalized searching/sorting
     * functions. */

    int iarray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < sizeof(iarray) / sizeof(*iarray); ++i) {
        printf("%d \t", iarray[i]);
    }
    printf("\n");

    int (*cmp)(const void*, const void*) = &compare;
    qsort(iarray, sizeof(iarray) / sizeof(*iarray), sizeof(*iarray), cmp);

    for (int i = 0; i < sizeof(iarray) / sizeof(*iarray); ++i) {
        printf("%d \t", iarray[i]);
    }
    printf("\n");

    return 0;
}

void someFunction(int arg) {
    printf("This is someFunction being called and arg is: %d\n", arg);
    printf("Whoops leaving the function now!\n");
}

int compare(const void* left, const void* right) {
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated:
    // http://www.cplusplus.com/reference/cstdlib/qsort/
}

/**
 * @author qtf0x
 * @date 20.05.2022
 *
 * @brief They point to things.
 */

#include <stdio.h>

int main() {
    // arrays and pointers are the same thing!
    char* name = "John";

    printf("Name: %s\n", name);

    printf("Name: ");
    for (int i = 0; i < 4; ++i) {
        printf("%c", name[i]);
    }
    printf("\n");

    // accessing pointers
    int a = 1;
    int* pointer_to_a = &a;

    // let's change the variable a
    a += 1;

    // we just changed the variable again!
    *pointer_to_a += 1;

    // will print out 3
    printf("The value of a is now %d\n", a);

    return 0;
}

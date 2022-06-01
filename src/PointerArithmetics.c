/**
 * @author qtf0x
 * @date 31.05.2022
 *
 * @brief It works kinda like you'd think. Go figure.
 */

#include <stdio.h>

int main() {
    // memory is accessed and modified byte-wise
    // the number of bytes modified by pointer arithmetic is determined by the
    // type of the pointer (for example, an int is usually 4 bytes)

    int intarray[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i) {
        printf("intarray[%d] has value %d - and address @ %p\n", i, intarray[i],
               &intarray[i]);
    }

    /* Incrementing a Pointer with (++) */

    // print the address of the 4th element in the array
    int* intpointer = &intarray[3];
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    // now increment the pointer to the 5th element in the array
    ++intpointer;
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    /* Decrementing a Pointer with (--) */

    // print the address of the 5th element in the array
    intpointer = &intarray[4];
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    // now decrement the pointer to the 4th element in the array
    --intpointer;
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    /* Adding Pointers with (+) */

    // print the address of the 2nd element in the array
    intpointer = &intarray[1];
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    // now shift the pointer by 2 to the 4th element in the array
    intpointer += 2;
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    /* Subtracting Pointers with (-) */

    // print the address of the 5th element in the array
    intpointer = &intarray[4];
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    // now shift the pointer by 2 to the 3rd element in the array
    intpointer -= 2;
    printf("address: %p - has value %d\n", intpointer, *intpointer);

    return 0;
}

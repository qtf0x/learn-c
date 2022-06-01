/**
 * @author qtf0x
 * @date 16.05.2022
 *
 * @brief Basic array syntax.
 */

#include <stdio.h>

int main() {
    // defines an array of 10 integers
    int numbers[10];

    // populate the array
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;
    numbers[3] = 40;
    numbers[4] = 50;
    numbers[6] = 60;
    numbers[7] = 70;

    // print the 7th number from the array, which has an index of 6
    printf("The 7th number in the array is %d\n", numbers[6]);

    return 0;
}

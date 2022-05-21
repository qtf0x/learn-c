/**
 * @file Loops.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-20
 *
 * @brief Loops. They work like you would think.
 */

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += array[i];
    }

    /* sum now contains a[0] + a[1] + ... + a[9] */
    printf("Sum of the array is %d\n", sum);

    /* calculate the factorial of the variable array */
    int factorial = array[0];

    for (int i = 1; i < 10; ++i) {
        factorial *= array[i];
    }

    // loop directives break and continue work as normal

    return 0;
}

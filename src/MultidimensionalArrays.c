/**
 * @file MultidimensionalArrays.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-16
 *
 * @brief Declaring and initializing multidimensional arrays.
 */

int main() {
    // General form:
    // type name [size1][size2]...[sizeN];

    // Examples:
    int foo[1][2][3];
    char vowels[1][5] = {{'a', 'e', 'i', 'o', 'u'}};

    // first dimension is unnecessary
    char Vowels[][5] = {{'A', 'E', 'I', 'O', 'U'}, {'a', 'e', 'i', 'o', 'u'}};

    // the inner braces are also unnecessary
    // the following are identical
    int a[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
    int b[][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // BUT you can't just declare an array with any missing dimensions
    int numbers[][6][5]; // compiler error

    return 0;
}

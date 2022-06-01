/**
 * @author qtf0x
 * @date 24.05.2022
 *
 * @brief They're the same thing (not really).
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    // array variable is a constant pointer to first element of the array
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char* pvowels = vowels;
    int i = 0;

    // print the addresses
    for (i = 0; i < 5; ++i) {
        printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i,
               &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // print the values
    for (i = 0; i < 5; ++i) {
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i,
               vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    // allocate memory to store five characters
    int n = 5;
    pvowels = (char*)malloc(n * sizeof(char));

    /*
    arrays and pointers are NOT the same
    the size of an array must be known at compile time
    the "size" of a pointer can be determined at run time
    however, pointers can be used like this to give us a sort of "dynamic array"
    */
    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    pvowels[3] = 'O';
    *(pvowels + 4) = 'U';

    for (i = 0; i < n; ++i) {
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    free(pvowels);
    pvowels = NULL;

    // we can extend this idea of dynamic arrays to multidimensional arrays
    int nrows = 2;
    int ncols = 5;
    int j = 0;

    // allocate memory for nrows pointers
    char** pVowels = (char**)malloc(nrows * sizeof(char*));

    // for each row, allocate memory for ncols elements
    pVowels[0] = (char*)malloc(ncols * sizeof(char));
    pVowels[1] = (char*)malloc(ncols * sizeof(char));

    pVowels[0][0] = 'A';
    pVowels[0][1] = 'E';
    pVowels[0][2] = 'I';
    pVowels[0][3] = 'O';
    pVowels[0][4] = 'U';

    pVowels[1][0] = 'a';
    pVowels[1][1] = 'e';
    pVowels[1][2] = 'i';
    pVowels[1][3] = 'o';
    pVowels[1][4] = 'u';

    for (i = 0; i < nrows; ++i) {
        for (j = 0; j < ncols; ++j) {
            printf("%c ", pVowels[i][j]);
        }

        printf("\n");
    }

    // free individual rows
    free(pVowels[0]);
    pVowels[0] = NULL;
    free(pVowels[1]);
    pVowels[1] = NULL;

    // free the top-level pointer
    free(pVowels);
    pVowels = NULL;

    return 0;
}

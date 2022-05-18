/**
 * @file Strings.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-17
 *
 * @brief Or character arrays, rather.
 */

#include <stdio.h>

int main() {
    // immutable string
    char* name = "Vincent Marias";

    // mutable string
    char name1[] = "Vincent Marias";
    /* is the same as */
    char name2[15] = "Vincent Marias"; // +1 for '\0' terminator

    name1[1] = 'A'; // edit string

    // String Length
    printf("Length of name: %d\n", strlen(name));

    // String Comparison

    // safe version: strncmp (returns 0 for equal)
    if (strncmp(name, "John", 4) == 0) {
        printf("Hello, John!\n");
    } else {
        printf("You are not John. Go away.\n");
    }

    // unsafe version: strcmp (do not use)

    // String Concatenation
    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, 3);
    printf("%s\n", dest);
    strncat(dest, src, 20);
    printf("%s\n", dest);

    return 0;
}

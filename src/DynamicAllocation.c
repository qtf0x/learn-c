/**
 * @file DynamicAllocation.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-22
 *
 * @brief A whole HEAP of fun!
 */

#include <stdlib.h>

typedef struct {
    char* name;
    int age;
} person;

int main() {
    // malloc() returns a void pointer, needs to be typecast
    // to allocate a new object on the heap
    person* myperson = (person*)malloc(sizeof(person));
    // OR person* myperson = malloc(sizeof(*myperson))

    // the explict typecast is actually unnecessary
    person* yourperson = malloc(sizeof(*yourperson));

    // sizeof() isn't an actual function
    // compiler translates it to the memory size (bytes)

    // dynamically allocated objects are mutable
    myperson->name = "Vincent";
    myperson->age = 20;

    // free() does not delete the variable
    // it simply releases the data that it points to
    // the variable still points to a memory location,
    // but we can no longer it to access that memory
    free(myperson);
    free(yourperson);

    // dereferencing a freed pointer is undefined
    // myperson->age = 21;

    // assign freed pointers NULL to avoid this
    myperson = NULL;
    yourperson = NULL;

    // can reallocate memory to a freed pointer (maybe don't)
    myperson = malloc(sizeof(person));

    return 0;
}

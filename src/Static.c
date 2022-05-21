/**
 * @file Static.c
 * @author Vincent Marias (@vincent-marias)
 * @date 2022-05-20
 *
 * @brief Static stuff is wierd in C.
 */

#include <stdio.h>

int runner() {
    // static variables INCREASE scope local -> file
    // count will actually be updated each time
    static int count = 0;
    ++count;
    return count;
}

// static functions DECREASE scope global -> file
static void fun(void) { printf("I am a static function."); }

int main() {
    printf("%d ", runner());
    printf("%d ", runner());

    return 0;
}

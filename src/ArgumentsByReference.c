/**
 * @author qtf0x
 * @date 22.05.2022
 *
 * @brief Well, not really.
 */

#include <stdio.h>

typedef struct {
    int x;
    int y;
} point;

void move(point* p) {
    ++p->x;
    ++p->y;
}

int main() {
    // C does NOT have references
    // by pass-by-reference, we mean pass-by-pointer
    point p;
    p.x = 10;
    p.y = 9;

    move(&p);

    printf("x: %d\n", p.x);
    printf("y: %d\n", p.y);

    return 0;
}

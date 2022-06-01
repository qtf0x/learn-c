/**
 * @author qtf0x
 * @date 31.05.2022
 *
 * @brief Unions are very weird.
 */

// unions allow us to reference the same memory with different variable names
// and even different type specifiers

#include <stdio.h>

// Tagged Unions

// this takes a lot of memory
struct operator{
    int intNum;
    float floatNum;
    int type;
    double doubleNum;
};

// with this setup, the size of the struct is just the size of `type` + the size
// of the largest type in the union (the double)
typedef struct number {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    }; // if union doesn't have a name, members accessed directly from struct
} operator;

// the union will be as large as it's largest type (+ padding from compiler)
union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

// when you always have multiple variables of the same type, and you want ot be
// able to use both names and indices, do this:
union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    }; // anonymous struct acts the same way as an anonymous union, members are
       // on the outer container
    int coins[4];
};

int main() {
    union intParts parts;
    parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

    printf("The int is %i\nThe bytes are [%i, %i %i, %i]\n", parts.theInt,
           parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt,
           *((char*)&theInt + 0), *((char*)&theInt + 1), *((char*)&theInt + 2),
           *((char*)&theInt + 3));

    // or with array syntax which can be a tiny bit nicer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n", theInt,
           ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2],
           ((char*)&theInt)[3]);

    operator op;
    op.type = 0; // int, probably better as an enum or macro constant
    // intNum is part of the union, but since it's not named you access it
    // directly off the struct itself
    op.intNum = 352;

    // since the union makes the variables share the same memory, the coins
    // array matches with each int in the struct (in order)
    union Coins change;
    for (int i = 0; i < sizeof(change) / sizeof(int); ++i) {
        scanf("%i", change.coins + i); // BAD code! input is always suspect!
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
           change.quarter, change.dime, change.nickel, change.penny);

    // OR

    // initializer lists like this are assigned to the first member of the
    // union/struct
    union Coins change2 = {{1, 2, 3, 4}};
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
           change.quarter, change.dime, change.nickel, change.penny);

    return 0;
}

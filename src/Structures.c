/**
 * @author qtf0x
 * @date 22.05.2022
 *
 * @brief Like classes, but worse.
 */

// without typedef
struct point1 {
    int x;
    int y;
};

// with typedef
typedef struct {
    int x;
    int y;
} point2;

// structs can also hold pointers
typedef struct {
    char* brand;
    int model;
} vehicle;

int main() {
    // without typedef, define new objects like this
    struct point1 p1;
    p1.x = 14;
    p1.y = 97;

    // with type typedef, can just use struct name
    point2 p2;
    p2.x = 14;
    p2.y = 97;

    // struct holding a pointer (string)
    vehicle mycar;
    mycar.brand = "Ford";
    mycar.model = 2007;

    return 0;
}

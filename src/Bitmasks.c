/**
 * @author qtf0x
 * @date 01.06.2022
 *
 * @brief Itty bitty bits.
 */

int main() {
    /* Setting bin n */

    // OR the value in memory with 2^n
    char storage = 0;  // 0000 0000
    storage |= 1 << 3; // 0000 1000

    /* Clearing bit n */

    // AND the value in memory with the inverse (NOT) of 2^n
    storage = 8;          // 0000 1000
    storage &= ~(1 << 3); // 0000 0000

    /* Flipping bit n */

    // XOR the value in memory with 2^n
    storage |= ~(0);   // 1111 1111
    storage ^= 1 << 3; // 1111 0111

    /* Checking bit n */

    // AND the value in memory with 2^n
    storage = 8; // 0000 1000
    if (storage & (1 << 3)) {
        // do something
    }

    return 0;
}

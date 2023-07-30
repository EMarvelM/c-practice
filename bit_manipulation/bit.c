#include <stdio.h>

int main(void)
{
    int z = 12; // 0000000000001100 in binary
    int y = 8;  // 0000000000001000 in binary
    int x = 6;  // 0000000000000110 in binary

    // AND
    printf("AND: %d\n", z & y); // Result: 0000000000001000 (8 in decimal)

    // OR
    printf("OR: %d\n", x | y); // Result: 0000000000001110 (14 in decimal)

    return 0;
}

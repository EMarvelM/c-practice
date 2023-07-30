#include <stdio.h>
#include <stdarg.h>

int and(int x, ...)
{
    va_list op;
    va_start(op, x);
    int y = va_arg(op, int);

    int arrx[32], i, arry[32];
    for (i = 0; x != 0; i++)
    {
        x = x % 2;
        arrx[i] = x/10;

        y = y % 2;
        arry[i] = y/10;
    }

}

int main(void)
{
    int z = 12; // 0000000000001100 in binary
    int y = 8;  // 0000000000001000 in binary
    int x = 6;  // 0000000000000110 in binary

    // AND
    printf("AND: %d\n", z & y); // Result: 0000000000001000 (8 in decimal)
    printf("AND: %d\n", and(z, y)); // Result: 0000000000001000 (8 in decimal)

    // OR
    printf("OR: %d\n", x | y); // Result: 0000000000001110 (14 in decimal)

    // NOR
    //How it works
    printf("NOR: %d\n", z ^ x); // Result: 0000000000001010 (10 in decimal)

    // NOT
    //How it works
    printf("NOT: %d\n", ~x); // Result: 1111111111111001 (10 in decimal)

    return 0;
}

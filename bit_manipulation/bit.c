#include <stdio.h>

int main(void)
{
    int z = 12; //0000000000000110
    int y = 8;  //0000000000001000
    int x = 6;

    //AND
    printf("AND: %d\n", z & y); //0000000000001000

    //OR
    printf("OR: %d\n", x | y); //0000000000001110
}
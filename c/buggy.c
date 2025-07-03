#include <cs50.h>
#include <stdio.h>

void printBricks(int h);

int main(void)
{
    int h = get_int("Enter height: ");
    printBricks(h);
}

void printBricks(int h)
{
    for (int i = 0; i <= h; i++){
        printf("#\n");
    }
}

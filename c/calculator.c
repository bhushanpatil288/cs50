#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long dollars = 1;
    while(true){
        int x = get_int("x: ");
        int y = get_int("y: ");

        printf("%.50f\n", (float) x / y);

    }
}

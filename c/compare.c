#include <stdio.h>
#include <cs50.h>

int main(void){
    int x = get_int("What's x? ");
    int y = get_int("what's y? ");
    if (x < y)
    {
        printf("%i is less than %i", x, y);
    }
    else if (x > y)
    {
        printf("%i is not less than %i", x, y);
    }
    else
    {
        printf("%i is equal to %i", x, y);
    }
}

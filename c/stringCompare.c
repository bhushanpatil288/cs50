#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {
        if(strcmp(strings[i], s) == 0)
        {
            printf("Found at index: %i\n", i);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

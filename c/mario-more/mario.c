#include <cs50.h>
#include <stdio.h>

void printPyramid(int n);

int main(void)
{
    bool validUserInput = false;
    int userInput;
    while (validUserInput != true)
    {
        userInput = get_int("Height: ");
        if (userInput > 0 && userInput <= 8)
        {
            validUserInput = true;
        }
    }
    printPyramid(userInput);
    return 0;
}

void printPyramid(int n)
{
    // print pyramid height
    for (int i = 0; i < n; i++)
    {
        // print left pyramids spaces
        for (int j = n - i - 1; j > 0; j--)
        {
            printf(" ");
        }
        // print left pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // print gap between pyramids
        for (int j = 0; j < 2; j++)
        {
            printf(" ");
        }

        // print right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

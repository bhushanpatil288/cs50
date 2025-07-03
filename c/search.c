#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};
    int arrSize = sizeof(numbers)/sizeof(int);

    int n = get_int("Number: ");

    for (int i = 0; i < arrSize; i++)
    {
        if (numbers[i] == n)
        {
            printf("%i\n", i);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}

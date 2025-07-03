#include <cs50.h>
#include <stdio.h>

void meow(int nums);
int get_positive_int(void);

int main(void)
{
    int n = get_positive_int();
    meow(n);
}

int get_positive_int(void)
{
    int n;
    do
    {
        n = get_int("Enter the number: ");
    }
    while (n < 1);
    return n;
}

void meow(int nums)
{
    for (int i = 0; i < nums; i++)
    {
        printf("meow\n");
    }
}

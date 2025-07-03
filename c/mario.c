#include <cs50.h>
#include <stdio.h>

void get_num_of_marks(void);
void get_num_of_y_bricks(void);
void print_question_marks(int n);
void print_y_bricks(int n);
void print_thick_bricks(int n, int m);
void get_dimensions_of_thick_bricks(void);

int main(void)
{
    // get_num_of_marks();
    // get_num_of_y_bricks();
    get_dimensions_of_thick_bricks();
}

void get_num_of_marks(void)
{
    int n = get_int("Enter the number of question marks: ");
    print_question_marks(n);
}

void print_question_marks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("?");
    }
    printf("\n");
}

void get_num_of_y_bricks(void)
{
    int n = get_int("Enter the number of question marks: ");
    print_y_bricks(n);
}

void print_y_bricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#\n");
    }
}

void get_dimensions_of_thick_bricks(void)
{
    int n = get_int("Enter the height of the bricks: ");
    int m = get_int("Enter the width of the bricks: ");
    print_thick_bricks(n, m);
}

void print_thick_bricks(int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}

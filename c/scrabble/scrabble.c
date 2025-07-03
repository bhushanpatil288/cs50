#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int getPoints(string s, string characters, int points[]);

int main(void)
{
    string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int player1Points = getPoints(player1, characters, points);
    int player2Points = getPoints(player2, characters, points);

    if (player1Points == player2Points)
    {
        printf("Tie!\n");
    }
    else if (player1Points > player2Points)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

    return 0;
}

int getPoints(string s, string characters, int points[])
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (characters[j] == toupper(s[i]))
            {
                sum += points[j];
            }
        }
    }
    return sum;
}

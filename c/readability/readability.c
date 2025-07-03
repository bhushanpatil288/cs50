#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // getting text from user
    string text = get_string("Text: ");

    // counting letter, spaces and words
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0, l = strlen(text); i < l; i++)
    {
        if (text[i] != ' ' &&
            ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')))
        {
            letters += 1;
        }
        if (text[i] == ' ')
        {
            words += 1;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    // printf("letters: %i, words: %i, sentences: %i\n", letters, words, sentences);

    // computer grade
    int grade = (int) round(
        (0.0588 * (((float) letters / words) * 100) - 0.296 * (((float) sentences / words) * 100)) -
        15.8);

    // print grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

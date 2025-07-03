#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {

        // checking length of the key if its 26
        string key = argv[1];
        int keyLen = strlen(key);

        if (keyLen < 26)
        {
            printf("Key must contain 26 characters\n");
            return 1;
        }
        bool seen[26] = {false};
        for (int i = 0; i < 26; i++)
        {
            if (!isalpha(key[i]))
            {
                printf("key must only container aplphabetic characters\n");
                return 1;
            }
            int index = toupper(key[i]) - 'A';
            if (seen[index])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
            seen[index] = true;
        }
        string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string lowerCase = "abcdefghijklmnopqrstuvwxyz";

        // get plain text

        string plainText = get_string("plaintext: ");
        int plainTextLen = strlen(plainText);

        // making new cypher text
        char cipher[plainTextLen + 1];
        int cipherLen = 0;

        for (int i = 0; i < plainTextLen; i++)
        {
            if (isupper(plainText[i]))
            {
                int pos = plainText[i] - 'A';
                cipher[i] = toupper(key[pos]);
            }
            else if (islower(plainText[i]))
            {
                int pos = plainText[i] - 'a';
                cipher[i] = tolower(key[pos]);
            }
            else
            {
                cipher[i] = plainText[i];
            }
        }
        cipher[plainTextLen] = '\0';

        printf("ciphertext: %s\n", cipher);
    }
}

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");

    // char *t = s;

    // t[0] = toupper(t[0]);

    // printf("%s\n", s);
    // printf("%s\n", t);



    //////////////// to actually copy s to t //////////////////

    char *t = malloc(strlen(s)+1);

    if (t == NULL){
        return 1;
    }

    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s[i];
    }

    // strcpy(t,s);   //shortcut

    if (strlen(t) > 0){
        t[0] = toupper(t[0]);
    }


    printf("%s\n", s);
    printf("%s\n", t);

    free(t); //frees memory (userful for continuesly running programs)

}

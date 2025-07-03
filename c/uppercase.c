#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// WITH LIBRARY

int main(void){
    string s = get_string("Before: ");
    printf("After:  ");
    for (int i = 0, n = strlen(s); i < n; i++){
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}




// MANUAL


// int main(void){
//     string s = get_string("Before: ");
//     printf("After:  ");
//     for (int i = 0, n = strlen(s); i < n; i++){
//         if (s[i] >= 'a' && s[i] <= 'z'){
//             printf("%c", s[i]-('a' - 'A'));
//         } else {
//             printf("%c", s[i]);
//         }
//     }
//     printf("\n");
// }

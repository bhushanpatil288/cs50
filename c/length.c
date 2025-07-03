#include <cs50.h>
#include <stdio.h>
#include <string.h>

// USING LIBRARY

int main(void){
    string name = get_string("Name: ");
    int length = strlen(name);
    printf("%i\n", length);
}


// MANUAL



// prototype
// int get_length(string word);

// int main(void){
//     string name = get_string("Name: ");
//     printf("%i\n", get_length(name));

// }

// int get_length(string words){
//     int n = 0;
//     while(words[n] != '\0'){
//         n += 1;
//     }
//     return n;
// }

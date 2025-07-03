#include <cs50.h>
#include <stdio.h>

// WITH LIBRARY

int main(int argc, string argv[]){
    if (argc == 2){
        printf("Hello %s\n", argv[1]);
    } else {
        printf("Hello, world\n");
    }

    for (int i = 0; i < argc; i++){
        printf("%s ", argv[i]);
    }
    printf("\n");
    return 0;
}

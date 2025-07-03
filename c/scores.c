#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3;

// Prototype
float average(int length, int array[]);

int main(void){
    // Get scrores
    int scores[N];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
}


float average(int length, int array[]){
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum / (float)length;
}

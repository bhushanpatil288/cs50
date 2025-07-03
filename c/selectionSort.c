#include <stdio.h>

void swap(int *a, int *b);

int main(void){
    int array[] = {5, 2, 1, 3, 6, 4};
    int arrSize = sizeof(array)/sizeof(int);

    for (int i = 0; i < arrSize; i++){
        int minIndex = i;
        for (int j = i + 1; j < arrSize; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
        }
    }

    for (int i = 0; i < arrSize; i++){
        printf("%i", array[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

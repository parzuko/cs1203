#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// sort every third element wihtout changing the order of the other elements
int *sortEveryThirdElement(int *array, int n) {
    int *result = malloc(n * sizeof(int));
    int i, j, k;
    for (i = 0; i < n; i++) {
        result[i] = array[i];
    }
    for (i = 2; i < n; i += 3) {
        for (j = i; j < n; j += 3) {
            if (result[i] > result[j]) {
                int temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }
    return result;
}



int main(void) {
    int longListOfNumbers[] = {0,0,41,0,0,24,0,0,98,0,0,43,0,0,59,0,0,35,0,0,9,0};
    int n = sizeof(longListOfNumbers) / sizeof(int);
    
    int *sorted = sortEveryThirdElement(longListOfNumbers, n);
    printArray(sorted, n);
}
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

// https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// smallest k numbers in array excluding every third element
void kSmallestAmongUntouched(int *array, int k, int n) {
    // copy all emeents except every third element
    int totalThirdElements = n / 3;
    int *result = malloc((n - totalThirdElements) * sizeof(int));

    int i, j;
    for (i = 0, j = 0; i < n; i++) {
        if (i % 3 != 2) {
            result[j++] = array[i];
        }
    }
    // sort the result
    qsort(result, (n - totalThirdElements), sizeof(int), compare);

    printf("The smallest %d numbers in the array are: ", k);
    // print the first k elements
    for (i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}



int main(void) {
    int longListOfNumbers[] = {124, 24, 41, 82, 142, 25, 46, 42, 98, 53, 75, 43, 14, 41, 59, 42, 94, 35, 63, 8,9,0};
    int n = sizeof(longListOfNumbers) / sizeof(int);
    
    int *sorted = sortEveryThirdElement(longListOfNumbers, n);

    kSmallestAmongUntouched(longListOfNumbers, 3, n);
}
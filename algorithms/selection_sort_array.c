#include <stdio.h>

void selection_sort(int unsorted_nums[], int length) {
    for (int i = 0; i < length; i++) {
        int min = i;
        for (int j = i + 1; j < length; j++) {
            if (unsorted_nums[j] < unsorted_nums[min]) {
                min = j;
            }
        }
        // swap with min with i
        int temp = unsorted_nums[i];
        unsorted_nums[i] = unsorted_nums[min];
        unsorted_nums[min] = temp;
    }
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int length;
    printf("Selection Sort Algorithm\n");
    printf("Enter the number of elements in your array: ");
    scanf("%d", &length);

    int unsorted_nums[length];
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &unsorted_nums[i]);
    }

    printf("The unsorted array is: ");
    print_array(unsorted_nums, length);
    
    selection_sort(unsorted_nums, length);

    printf("The sorted array is: ");
    print_array(unsorted_nums, length);
}
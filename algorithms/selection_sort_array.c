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
    int unsorted_nums[] = {31, 1, 491, 241, 83, 17};
    int length = sizeof(unsorted_nums) / sizeof(unsorted_nums[0]);

    printf("The unsorted array is: ");
    print_array(unsorted_nums, length);
    
    selection_sort(unsorted_nums, length);

    printf("The sorted array is: ");
    print_array(unsorted_nums, length);
}
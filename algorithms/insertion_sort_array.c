#include <stdio.h>

void insertion_sort(int unsorted_nums[], int length) {
    for (int i = 1; i < length; i++) {
        int current_anchor = unsorted_nums[i];
        int j = i - 1;

        // Find number just smaller than current_anchor
        while (j >= 0 && unsorted_nums[j] > current_anchor) {
            unsorted_nums[j + 1] = unsorted_nums[j];
            j--;
        }

        // Insert current_anchor at the right position
        unsorted_nums[j + 1] = current_anchor;
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
    printf("Insertion Sort Algorithm\n");
    printf("Enter the number of elements in your array: ");
    scanf("%d", &length);

    int unsorted_nums[length];
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &unsorted_nums[i]);
    }
    
    printf("The unsorted array is: ");
    print_array(unsorted_nums, length);
    
    insertion_sort(unsorted_nums, length);

    printf("The sorted array is: ");
    print_array(unsorted_nums, length);
}
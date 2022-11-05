#include <stdio.h>

int get_partition(int nums[], int start, int end) {
    int pivot = nums[end];
    int i = start - 1;

    for (int j = start; j < end; j++) {
        // Swap if current element is smaller than the pivot
        if (nums[j] <= pivot) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    // Swap i + 1 with end
    int temp = nums[i + 1];
    nums[i + 1] = nums[end];
    nums[end] = temp;
    return i + 1;
}

void quick_sort(int unsorted_nums[], int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = get_partition(unsorted_nums, start, end);
    quick_sort(unsorted_nums, start, pivot - 1);
    quick_sort(unsorted_nums, pivot + 1, end);
}

void print_array(int array[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    int length;
    printf("Quick Sort Algorithm\n");
    printf("Enter the number of elements in your array: ");
    scanf("%d", &length);

    int unsorted_nums[length];
    for (int i = 0; i < length; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &unsorted_nums[i]);
    }

    printf("The unsorted array is: ");
    print_array(unsorted_nums, length);
    
    quick_sort(unsorted_nums, 0, length - 1);

    printf("The sorted array is: ");
    print_array(unsorted_nums, length);
}
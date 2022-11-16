#include <stdio.h>
#include <stdlib.h>
int N = 0;

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int array[], int size, int i) {
    if (size == 1) {
        return;
    } else {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] > array[largest]) {
            largest = l;
        }
        if (r < size && array[r] > array[largest]) {
            largest = r;
        }
        if (largest != i) {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }

}

void heapPush(int array[], int newNum) {
    if (N == 0) {
        array[0] = newNum;
        N += 1;
    } else {
        array[N] = newNum;
        N += 1;
        for (int i = N / 2 - 1; i >= 0; i--) {
            heapify(array, N, i);
        }
    } 
}

void heapPop(int array[], int num) {
    int i;
    for (i = 0; i < N; i++) {
        if (num == array[i]) {
            break;
        }
    }
    swap(&array[i], &array[N - 1]);
    N -= 1;
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(array, N, i);
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void thirdLargestNum(int *maxHeap, int n) {
    if (n < 3) {
        printf("Not enough elements in the array\n");
        return;
    }
    
    // save the first max 2 elements
    int k = 2;
    int largerThanThird[2] = {0, 0};
    for (int i = 0; i < k; i++) {
        largerThanThird[i] = maxHeap[0];
        heapPop(maxHeap, maxHeap[0]);
    }
    
    printf("The third largest number in the heap is %d", maxHeap[0]);
    
    // restore the heap's original state
    heapPush(maxHeap, largerThanThird[0]);
    heapPush(maxHeap, largerThanThird[1]);
}

int main()
{
    int array[10];

    heapPush(array, 10);
    heapPush(array, 20);
    heapPush(array, 30);
    heapPush(array, 40);
    heapPush(array, 50);
    heapPush(array, 80);

    printf("Max-Heap array: ");
    printArray(array, N);

    thirdLargestNum(array, N);
}
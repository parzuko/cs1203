#include <stdio.h>

int main(void) {
    // discussing arrays
    int nums[10] = {1,2,3,4,5,6,7,8,9,10};

    int x = 3;
    int *y;
    y = &x;

    // print y
    printf("y is %p\n", y);

    // print the value of y
    printf("y is %d\n", *y);

    // print the address of y
    printf("y is %p\n", &y);

    *y = *y + 1;
    printf("y is %d\n", *y);
    printf("x is now %d\n", x);
}
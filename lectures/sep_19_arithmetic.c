#include <stdio.h>

// arithmetic and stuff
int main(void) {
    float answer = 0.1 + 0.2;

    if (answer == 0.3)
    {
        printf("The answer is 0.3\n");
    }
    else
    {
        printf("The program broke :)\n");
    }

    // computers are bad at algebra, tbh
    float a2 = 0.1 + 0.1 + 0.1;
    if (a2 == 0.3)
    {
        // code goes kaput
    }

    char a4 = 'x';

    int a5 = -3 % 2;
    int b = -3 % -2;

    printf("%d %d\n", a5, b); // -1, -1  BUT WHY
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void advancedFizzBuzz(int *array, int m, int *b, int nb, int *f, int nf) {
    for (int i = 0; i < m; i++) {
        int x = array[i];
        int fizzFlag = 0;
        int buzzFlag = 0;
        for (int j = 0; j < nf; j++) {
            if (x % f[j] == 0) {
                fizzFlag = 1;
            }
        }
        for (int j = 0; j < nb; j++) {
            if (x % b[j] == 0) {
                buzzFlag = 1;
            }
        }
        if (fizzFlag == 1 && buzzFlag == 1) {
            printf("fizzbuzz\n");
        } else if (fizzFlag == 1) {
            printf("fizz\n");
        } else if (buzzFlag == 1) {
            printf("buzz\n");
        } else {
            printf("%d\n", x);
        }
    }
}

int main(void) {
    int fizz[] = {3, 5};
    int buzz[] = {2, 7};
    int array[] = {15, 21, 14, 35, 17, 23, 105};

    advancedFizzBuzz(array, 7, buzz, 2, fizz, 2);
}
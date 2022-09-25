// computers are limited precision machines. stress test for loops. see where it falls aparts in mutliple languages. numerical stability falls apart

#include <stdio.h>

int main (void) {
    for (int x = 0; x < 10; x++) {
		printf("blah\n");
    }
    // as you increase 0s you increase chance of failure. it will be slightly off.
    for (float x = 0.0; x < 1.0; x = x + 0.1) {
		printf("blah\n");
    }   
}
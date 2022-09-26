#include <stdio.h>

void break_code() {
    char *s = "abcdefgh";

    // breaks the code
    *(s + 5) = 'x';
    s[6] = 'y';
    // breaks the code

    printf("the character *(s+1) is \"%c\"\n", *(s + 1));
    printf("the string s is \"%s\"\n", s); // \0 is the null character

    const int x = 5;
    // x = 6; // not allowed

    print("%d\n", x);

    // understadning const with pointers
    const int x = 5;
    int *p = &x;
    *p = 6;

    printf("%d\n", x);
    printf("*p = %d\n", *p);
    printf("%d\n", x);

    // stupidity
    const char *string = "Can't touch this";
    string = "can't touch this either";
    printf("\"%s\"\n", string);
}

void printing_overhaul() {
    int x = 1;
    int y = 1;

    x = (y = 5) * 3; // works because x = y = 5

    printf("x = %d, y = %d\n", x, y);

    int x = 0;
    int y = x++; // y is set to 0, then x is incremented
    y = ++x;     // x is incremented, then y is set to x

    printf("x = %d, y = %d\n", x, y);

    char s = 'v';
    printf("character s is '%c'\n", s);
    printf("character s is \"%c\"\n", s);
}


// will not compile, by design
int main(int argc, char **argv) {
    printing_overhaul();
    break_code();
    return 0;
}
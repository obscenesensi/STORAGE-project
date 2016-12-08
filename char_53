#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addi(int a, int b) {
    return a + b;
}

char *adds(char *a, char *b) {
    char *res = malloc(strlen(a) + strlen(b) + 1);
    strcpy(res, a);
    strcat(res, b);
    return res;
}

#define add(a, b) _Generic(a, int: addi, char*: adds)(a, b)

int main(void) {
    int a = 1, b = 2;
    printf("%d\n", add(a, b)); // 3

    char *c = "hello ", *d = "world";
    printf("%s\n", add(c, d)); // hello world

    return 0;
}

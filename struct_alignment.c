#include <stdio.h>

struct test_t {
    int x;
    char y;
} __attribute__((aligned(16)));

union mytest
{
        unsigned int num:8;
        struct
        {
            unsigned char a:1;
            unsigned char b:2;
            char :4;
            unsigned int c:1;
        };
} __attribute__((aligned(4)));

typedef union mytest mytest;

int main()
{
    mytest test;
    printf("%lu\n", sizeof(test));
    test.num = 20;
    test.a = 1;
    test.b = 1;
    test.c = 1;
    printf("Num = %u\n", test.num);
    return 0;
}
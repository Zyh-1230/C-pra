#include <stdio.h>

int main(void)
{
    int* p;
    printf("&p = %X\n", &p);
    printf("*p = %X\n", *p);
    printf("p = %X\n", p);
    int i = 7;

    p = &i;
    printf("&p = %X\n", &p);
    printf("*p = %X\n", *p);
    printf("p = %d\n", p);

    return 0;
}
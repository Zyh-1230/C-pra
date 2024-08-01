#include <stdio.h>


void itcge(int* p, int* q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;

}


int main(void)
{
    int a = 7;
    int b = 1230;

   
    itcge(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    return 0;
}
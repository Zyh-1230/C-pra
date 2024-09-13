#include <stdio.h>


void swap(int* p, int* q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;
  printf("%d %d\n", sizeof(p), sizeof (q));
}


int main(void)
{
    int a = 7;
    int b = 1230;

   
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    printf("%d %d", sizeof(a), sizeof (b));

    return 0;
}
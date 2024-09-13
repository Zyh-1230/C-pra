#include <stdio.h>

void f(int** q)
{
    /*
    转化地址
    int j = 13;
    *q = &j;
    */
   *q = (int*)0xFFFFFFFF; //修改p的地址
}

int main(void)
{
    int i = 12;
    int* p = &i;

    printf("%p\n", p);
    f(&p);
    printf("%p\n", p);


    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void f(int** q);

int main(void)
{
    int* p;
    printf("%p\n", p);
    f(&p);
    printf("%p\n", p);

    return 0;
}

/*
int f(int** q)
{
    int s;
    *q = &s;

}

有警告，原因是当f函数运行完后，系统为s所分配的内存自动释放，此时的p所指向的地址为无效地址
*/

void f(int** q)
{
    *q = (int*)malloc(sizeof(int));

}
#include <stdio.h>
#include <stdlib.h>

/*
void f(int** q)
{
    int i = 5;
    **q = i;

}
//error i是静态变量，在main函数运行完后，f函数被程序自动清空，逻辑出错，无法正常输出
*/

void f(int** q)
{
    *q = (int*)malloc(sizeof(int));//此为程序员动态分配的动态内存，不会被程序自动释放，而是程序员手动释放，故逻辑不会出错
    **q = 5;
}


int main(void)
{
    int* p;
    f(&p);
    printf("%d", *p);

    return 0;
}

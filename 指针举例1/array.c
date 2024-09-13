#include <stdio.h>

void f(int* pArr, int len)
{
    int i;
    for(i=0; i<len; ++i)
        printf("%d ", *(pArr+i));//*(pArr+i)等价于pArr[i]
}

int main(void)
{
    int a[7]={1,2,3,4,5,6,7};
    f(a,7);

    return 0;
}

/*

time:20240807 23:10
输出结果：1 2 3 4 5 6 7 

*/
#include <stdio.h>

void sort(int* a, int len)
{
    int i,j,t;
    for (i=0; i<len-1; ++i)
    {
        for (j=0; j<len-1-i; ++j)
        {
            if (a[j]>a[j+1])
                {
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
        }
    }
}


int main(void)
{
    int a[7] = {1, -3, 7, -2, 5, 9, 4};
    int i;

    sort(a, 7);

    for (i=0; i<7; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
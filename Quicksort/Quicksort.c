#include <stdio.h>

void QuickSort(int* a, int low, int high);
int FindPos(int* a, int low, int high);

int main(void)
{
    int a[7] = {4, 1, 3, 6, 7, 2, 5};
    int i;

    QuickSort(a, 0, 6);//第二个参数代表数组中第一个元素的下标 第三个参数代表数组中最后一个元素的下标

    for(i=0; i<7; ++i)
        printf("%d", a[i]);

    return 0;
}

void QuickSort(int* a, int low, int high)
{
    int pos;

    if (low < high)
    {
        pos = FindPos(a, low, high);
        QuickSort(a, low, pos-1);
        QuickSort(a, pos+1, high);
    }
}

int FindPos(int* a, int low, int high)
{
    int val = a[low];

    while(low < high)
    {
        while(low < high && a[high] >= val)
            --high;
        a[low] = a[high];

        while(low < high && a[low] <= val)
            ++low;
        a[high] = a[low];
    }

    a[low] = val;//a[high] = val;

    return low;//return high
}
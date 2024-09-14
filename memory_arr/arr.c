#include <stdio.h>
#include <stdbool.h>//bool
#include <stdlib.h>//malloc、exit

struct Array
{
    int* pBase;
    int len;
    int cnt;//当前数组有效元素的个数
};

void init_arr(struct Array* pArr, int length);
void show_arr(struct Array* pArr);
bool is_empty(struct Array* pArr);//bool类型只返回true/false
bool is_full(struct Array* pArr);
bool append_arr(struct Array* pArr, int val);//追加
bool insert(struct Array* pArr, int pos, int val);//pos表示插入的位置（插入至第几号元素）
bool delete(struct Array* pArr, int pos, int* pVal);//删除并返回删除的值
void inversion(struct Array* pArr);//倒置
void sort(struct Array* pArr);//排序

int main(void)
{
    struct Array arr;

    int len = 7;
    int val;
    init_arr(&arr, len);
    printf("数组的长度是：%d\n", arr.len);
    append_arr(&arr, 1);
    append_arr(&arr, 5);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 7);
    append_arr(&arr, 6);
    /*
    append_arr(&arr, 7);

    if(append_arr(&arr, 8))
        printf("pArr->pBase[7] == 8 追加成功!\n");
    else
        printf("pArr->pBase[7] == 8 追加失败!\n");
    */
    printf("该数组的有效长度是：%d\n", arr.cnt);
    insert(&arr, 7, 27);

    if(delete(&arr, 3, &val))
    {
        printf("删除成功!\n");
        printf("删除的元素是:%d\n", val);
    }
    else
        printf("删除失败!\n");

    show_arr(&arr);
    printf("该数组的有效长度是：%d\n", arr.cnt);

    inversion(&arr);
    show_arr(&arr);

    sort(&arr);
    show_arr(&arr);

    return 0;
}

void init_arr(struct Array* pArr, int length)//若为void init_arr(struct Array pArr) 无法修改参数 输出结果为82116388
{
    pArr->pBase = (int*)malloc(sizeof(int)*length);
    if (NULL == pArr->pBase)
    {
        printf("动态内存分配失败!\n");
        exit(-1);//exit(x)表示关闭所有文件，终止正在进行的文件，x发送给系统 x=0时，代表程序正常退出；x!=0时代表程序异常退出
    }
    else
    {
        pArr->len = length;
        pArr->cnt = 0;
    }

    return;
}

bool is_empty(struct Array* pArr)
{
    if (0 == pArr->cnt)
        return true;
    else
        return false;
}

void show_arr(struct Array* pArr)
{
    int i;

    if(is_empty(pArr))//注意此时show_arr和is_empty函数中的行参pArr不同，但为同级指针，故只需直接传输而非传输地址
        printf("数组为空！\n");
    else
    {
        for(i=0; i<pArr->cnt; ++i)
            printf("%d ", pArr->pBase[i]);
        printf("\n");
    }

   /*
   if(数组为空)
   printf("提示数组为空");
   else
   printf（输出数组有效内容);
   */
}

bool is_full(struct Array* pArr)
{
    if (pArr->cnt == pArr->len)
        return true;
    else
        return false;

}

bool append_arr(struct Array* pArr, int val)
{
    if (is_full(pArr))
        return false;
    
    else
    {
        pArr->pBase[pArr->cnt] = val;
        pArr->cnt++;
    }
    return true;
}

bool insert(struct Array* pArr, int pos, int val)
{
    int i;

    if(pos<1 || pos>pArr->cnt+1)//此处为cnt+1而不是len 注意该函数的功能是在已有数组的基础上向其中插入元素，而非在数组剩余长度中添加元素，故因考虑cnt
        return false;
        
    if (is_full(pArr))
        return false;
    else
    {    
        for (i = pArr->cnt-1; i>=pos-1; --i)
            pArr->pBase[i+1] = pArr->pBase[i];
        pArr->pBase[pos-1] = val;
        pArr->cnt++;
        return true;
    }
}

bool delete(struct Array* pArr, int pos, int* pVal)
{
    int i;
    if (pos<1 || pos>pArr->cnt)
        return false;
    if (is_empty(pArr))
        return false;
    *pVal = pArr->pBase[pos-1];
    for (i=pos; i<pArr->cnt; ++i)
    {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}

void inversion(struct Array* pArr)
{
    int i = 0;
    int j = pArr->cnt-1;
    int t;

    while (i<j)
    {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        i++;
        j--;
    }
    return;
}

void sort(struct Array* pArr)
{
    int i;
    int j;
    int t;

   for (i=0; i<pArr->cnt; ++i)
    {
        for(j=0; j<pArr->cnt; ++j)
        {
            if (pArr->pBase[j]>pArr->pBase[j+1])
            {
                t = pArr->pBase[j];
                pArr->pBase[j] = pArr->pBase[j+1];
                pArr->pBase[j+1] = t;
            }
        }
    }

}
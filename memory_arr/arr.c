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

int main(void)
{
    struct Array arr;

    int len = 7;
    init_arr(&arr, len);
    printf("数组的长度是：%d\n", arr.len);
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    append_arr(&arr, 6);
    append_arr(&arr, 7);

    if(append_arr(&arr, 8))
        printf("pArr->pBase[7] == 8 追加成功!\n");
    else
        printf("pArr->pBase[7] == 8 追加失败!\n");

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
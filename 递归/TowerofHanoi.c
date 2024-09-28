#include <stdio.h>

void hanoi(int, char, char, char);//实现有序的盘子从全部在A柱子上到全部在C上

int main(void)
{
    int val;
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    printf("请输入您想移动的盘子的个数:\n");//假定盘子全部放在A柱子上
    printf("val =  ");
    scanf("%d", &val);

    hanoi(val, 'A', 'B', 'C');


    return 0;
}

void hanoi(int n, char A, char B, char C)
{
    /*
    如果是1个盘子
    直接将A柱子上的盘子从A移到C

    否则先将A柱子上的n-1个盘子借助C移到B
    直接将A柱子上的盘子从A移到C
    最后将B柱子上的n-1个盘子借助A移到C
    */
    if (1 == n)
        printf("将编号为%d的盘子从%c柱子上移到%c柱子上\n", n, A, C);
    else
    {
        hanoi(n-1, A, C, B);
        printf("将编号为%d的盘子从%c柱子上移到%c柱子上\n", n, A, C);
        hanoi(n-1, B, A, C);
    }

}
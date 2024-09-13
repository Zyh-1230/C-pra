#include <stdio.h>
#include <stdlib.h> //在macOS上，类似malloc、free、calloc和realloc这样的内存分配函数是在标准库头文件<stdlib.h>中定义的，而不是在malloc.h中。

int main(void)
{
    int* pArr;
    int len;
    int i;
    printf("请输入你要存放的元素的个数：");
    scanf("%d", &len);
    pArr = (int*)malloc(4 * len); //创建动态一维数组，该一维数组的长度是len，数组名叫pArr，该数组的每个元素是int类型
    //类似于pArr[i] 但此数组为静态数组

    printf("请输入你要存放的相应个数的元素:\n");// 对动态数组进行输入
    for(i=0;i<len;++i)
        scanf("%d", &pArr[i]);
    
    printf("一维数组的内容是:\n");//对动态数组进行输出
    for(i=0;i<len;++i)
        printf("%d ", pArr[i]);

    return 0;
}



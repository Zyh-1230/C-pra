#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int age;
    float score;
    char name[100];
};

void f(int* len, struct Student* pArr)
{
    int i;
    for (i=0; i<*len; ++i)
    {
        printf("请输入第%d个学生的信息:\n", i+1);

        printf("age = ");
        scanf("%d", &pArr[i].age);//不要加\n会导致程序停滞，因为\n是非输出控制符啊！
        getchar(); // 清除换行符

        printf("name = ");
        scanf("%99s", pArr[i].name);//name已经是数组名，本身就是地址，不用再加& ！//99是为了限制读取的最大字符数为99，以防止缓冲区溢出。
        getchar(); // 清除换行符

        printf("score = ");
        scanf("%f", &pArr[i].score);
        getchar(); // 清除换行符
    }
}

void h(int* len, struct Student* pArr)
{
    int i,j;
    struct Student t;
    for (i=0; i<*len-1; ++i)
    {
        for (j=0; j<*len - i - 1; ++j)
        {
            if (pArr[j].score < pArr[j+1].score)
            {
                t = pArr[j];
                pArr[j] = pArr[j+1];
                pArr[j+1] = t;
            }
        } 
    }


}
void g(struct Student* pArr, int* len)
{
    int j;
    for (j=0; j<*len; ++j)
    {
        printf("第%d个学生的信息是:\n", j+1);

        printf("age = %d\n", pArr[j].age);
        printf("name = %s\n", pArr[j].name);
        printf("score = %f\n", pArr[j].score);
    }
}

int main(void)
{
    int len;
    struct Student* pArr;

    printf("请输入学生的个数:\n");
    scanf("%d", &len);

    pArr = (struct Student*)malloc(len * sizeof(struct Student));

    f(&len, pArr);//input
    h(&len, pArr);//冒泡降序
    g(pArr, &len);//output

    free(pArr);

    return 0;
}
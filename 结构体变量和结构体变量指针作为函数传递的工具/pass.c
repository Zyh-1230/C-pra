#include <stdio.h>
#include <string.h>

struct Student
{
    int age;
    char sex;
    char name[100];

};

void InputStudent(struct Student *);
void OutputStudent(struct Student stu);

int main(void)
{
    struct Student zyh;
    InputStudent(&zyh);
    printf("%d %s %c\n", zyh.age, zyh.name, zyh.sex);
    OutputStudent(zyh);

    return 0;
}

void InputStudent(struct Student *pstu)
{
    (*pstu).age = 18;
    strcpy(pstu->name, "周");//对数组元素的改变
    pstu->sex = 'F';
}

void OutputStudent(struct Student stu)//也可通过指针传递
{
    printf("%d %s %c", stu.age, stu.name, stu.sex);
}
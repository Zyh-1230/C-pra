#include <stdio.h>

struct Student
{
    int age;
    char sex;
    double score;
};



int main(void)
{
    struct Student zyh = {18, 'F', 100};
   // printf("%d %c %lf", zyh.age,zyh.sex,zyh.score);
    struct Student* pst = &zyh;
    printf("THE STUDENT'S AGE IS: %d\n", pst->age);

    return 0;
}
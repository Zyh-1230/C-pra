#include <stdio.h>
#include <stdlib.h>

struct Student* CreateStudent(void);
void ShowStudent(struct Student* pst);

struct Student
{
    int sid;
    int age;

};


int main(void)
{
    struct Student* ps;
    ps = CreateStudent();
    ShowStudent(ps);

    return 0;
}

struct Student* CreateStudent(void)
{
    struct Student* p = (struct Student*)malloc(sizeof(struct Student));
    p->sid = 123;
    p->age = 27;
    return p;

}
void ShowStudent(struct Student* pst)
{
    printf("%d %d", pst->sid, pst->age);

}
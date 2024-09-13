#include <stdio.h>
#include <string.h>

struct Student
{
    int sid;
    char name[10];
    int age;

};

int main(void)
{
    struct Student st = {1230, "jk", 27};
    printf("%d %s %d\n", st.sid, st.name, st.age);

    st.sid = 901;
    st.age = 28;
    strcpy(st.name, "Kim");
    printf("%d %s %d", st.sid, st.name, st.age);

    return 0;
}
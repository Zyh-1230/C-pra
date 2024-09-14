#include <stdio.h>

/*
typedef struct Student
{
    int sid;
    char name[10];
}STU;       //STU为struct Student的另一名称


int main(void)
{
    STU st;
    st.sid = 27;
    printf("%d\n", st.sid);

    return 0;
}
*/

typedef struct Student
{
    int sid;
    char name[10];
}*STU, St;//STU代表struct Student*  St代表struct Student

int main(void)
{
    STU st;
    St st2;
    st2.sid = 27;
    st = &st2;
    printf("%d\n", st->sid);


    return 0;
}
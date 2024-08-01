#include <stdio.h>
#include <iostream>

using std::endl;
using std::cout;

void itcge(int* p, int* q)
{
    int t;

    t = *p;
    *p = *q;
    *q = t;

}


int main(void)
{
    int a = 7;
    int b = 1230;

    cout << "sizeof(a) = " << sizeof(a) << endl;
    cout << "sizeof(b) = " << sizeof(b) << endl;


    itcge(&a, &b);
    printf("a = %d,b = %d\n", a, b);

    return 0;
    
}
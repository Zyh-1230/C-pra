#include <stdio.h>

long f(int n)
{
    if(1 == n)
        return 1;
    else
        return f(n-1) * n;
}
int main(void)
{
    printf("%ld\n", f(3));


    return 0;
}
#include <stdio.h>

int main(void)
{
    double* p;
    double x;

    p = &x;//x占8个字节 一个字节是8位，一个字节一个地址,但p只存放首字节地址，也就是只存放一个地址

    double arr[3] = {1.2, 2.3, 3.4};
    double* q;

    q = &arr[0];
    printf("%p\n", q);//%p是以16进制输出地址
    q = &arr[1];
    printf("%p\n", q);//两地址的输出序号差8位，并非1位

    return 0;
}
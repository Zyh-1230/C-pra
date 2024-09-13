#include <stdio.h>

int main(void)
{
    char ch = 128;//把4个字节的整数赋给只占1个字节的ch 溢出 仅保留最后一个字节1000 0000 被解释为负数 故输出结果为-128
    printf("%d\n", ch);

    return 0;
}
/*

time：20240822 21:34
output：-128

*/
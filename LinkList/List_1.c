#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;//数据域
    struct Node* pNext;//指针域
}NODE, *PNODE;//NODE 等价于 struct Node  PNODE等价于struct Node*

PNODE create_list(void);
void traverse_list(PNODE pHead);

int main(void)
{
    PNODE pHead = NULL;

    pHead = create_list();//create_list可创建一个非循环单链表，并将该链表的首地址发送给pHead
    traverse_list(pHead);

    return 0;
}

PNODE create_list(void)
{
    int len;
    int i;
    int val;//临时存放用户输入的节点值

    PNODE pHead = (PNODE)malloc(sizeof(NODE));//不是PNODE 而是NODE，等价于struct Node
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    if(NULL == pHead)
    {
        printf("分配失败，程序终止!\n");
        exit(-1);

    }

    printf("请输入您想生成的有效节点数: len = ");
    scanf("%d", &len);

    for(i=0; i<len; ++i)
    {
        printf("请输入第%d个的值: ", i+1);
        scanf("%d", &val);

        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew)
        {
            printf("分配失败，程序终止!\n");
            exit(-1);

        } 
        /*
        pNew->data = val;
        pHead->pNext = pNew;
        pNew->pNext = NULL;
        
        表示把新生成的节点挂到头结点的后面 但这不成线性 error
        应该是把新生成的节点挂到尾节点的后面
        */
        pNew->data = val;
        pTail->pNext = pNew;
        pTail = pNew;//pTail更新，此时pTail和pNew共享结构体的同一成员，下次pTail更新时，pTail->pNext指向下一个pNew，相应的上一个pNew->pNext也是指向下一个pNew，下一个pNew->pNext则指向NULL，pTail更新为下一个pNew

    }
    return pHead;
}

void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;

    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

}
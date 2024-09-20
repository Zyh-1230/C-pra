#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;//数据域
    struct Node* pNext;//指针域
}NODE, *PNODE;//NODE 等价于 struct Node  PNODE等价于struct Node*

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int*);
void sort(PNODE);

int main(void)
{
    PNODE pHead = NULL;
    int pos;
    int val;
    int Val;
    int Pos;

    pHead = create_list();//create_list可创建一个非循环单链表，并将该链表的首地址发送给pHead
    traverse_list(pHead);
    if(is_empty(pHead))
        printf("链表为空!\n");
    else
        printf("链表不为空!\n");
    
    int len = length_list(pHead);
    printf("链表的长度是：%d\n", len);

    sort(pHead);
    traverse_list(pHead);

    printf("请输入你想插入的位置：");
    scanf("%d", &pos);
    printf("请输入你想在该位置插入的元素：");
    scanf("%d", &val);

    insert_list(pHead, pos, val);
    traverse_list(pHead);

    printf("请输入你想删除的节点位置: ");
    scanf("%d", &Pos);
    if (delete_list(pHead, Pos, &Val))
        printf("删除成功!你删除的元素是:%d\n",Val);
    else
        printf("删除失败!\n");

    return 0;
}

PNODE create_list(void)
{
    int len;
    int i;
    int val;//临时存放用户输入的节点值
    //pHead不存放有效数据，只是提供链表的地址
    PNODE pHead = (PNODE)malloc(sizeof(NODE));//不是PNODE 而是NODE，等价于struct Node
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    if(NULL == pHead)
    {
        printf("分配失败，程序终止!\n");
        exit(-1);

    }

    printf("请输入您想生成的节点数: len = ");
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
    printf("链表的内容是:");
    while (NULL != p)
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

}

bool is_empty(PNODE pHead)
{
    if(NULL == pHead->pNext)
        return true;
    else
        return false;

}

int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len = 0;

    while(NULL != p)
    {
        len = len + 1;
        p = p->pNext;
    }
    return len;
}

void sort(PNODE pHead)//此方法并不标准，只是借用数组排序的方法来进行类比（泛型）
{
    int i,j,t;
    int len = length_list(pHead);
    PNODE p,q;

    if(pHead == NULL || pHead->pNext == NULL)//若链表为空则不需要排序
        return;

    for(i=0,p=pHead->pNext; i<len-1; ++i,p=p->pNext)//选择排序
    {
        for(j=i+1,q=p->pNext; j<len; ++j,q=q->pNext)
        {
            if(p->data > q->data)//等价于a[i] > a[j]
            {
                t = p->data;
                p->data = q->data;
                q->data = t;

            }
        }
    }
    /*
    Q:既然链表不像数组一样连续，那为什么还要在for循环中加入i和j？
    A：
    在链表中使用类似于数组的索引i和j是为了控制循环的次数
    而不是直接访问元素
    由于链表不是连续存储的
    我们不能像数组那样通过索引来直接访问元素
    相反，我们需要通过指针遍历链表
    在这种情况下,i和j用于跟踪已经处理过的节点数量
    以确保整个链表被正确地遍历和排序
    */

}
//在pHead所指向的链表的第pos个位置之前插入一个新的节点，该节点的值是val
bool insert_list(PNODE pHead, int pos, int val)
{
    int i = 0;
    PNODE p = pHead;
    int len = length_list(pHead);

    while (NULL!=p && i<pos-1)//遍历到要插入位置的前一个节点 ++i后，i=pos-1
    {
        p = p->pNext;
        ++i;
    }

    if (pos<1 || pos>len+1)//规定pos的范围 防止无效插入
    {
        printf("插入位置无效!\n");
        return false;
    }
    if(i>pos-1 || NULL == p)//检查插入位置是否有效
        return false;

    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }    
    pNew->data = val;
    //插入新节点
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;

    return true;


}

bool delete_list(PNODE pHead, int pos, int* pVal)
{
    int i = 0;
    PNODE p = pHead;
    
    while (NULL!=p->pNext && i<pos-1)//遍历到要删除的前一个节点的位置
    {
        p = p->pNext;
        ++i;
    }

    if(i>pos-1 || NULL == p->pNext)//检查删除位置是否有效
        return false;
    
    PNODE q = p->pNext;//q与p后一个元素（即要删除的元素）共享同一成员
    *pVal = q->data;

    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;

    return true;

}
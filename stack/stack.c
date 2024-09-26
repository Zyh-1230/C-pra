#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node
{
    int data;
    struct Node* pNext;

}NODE, *PNODE;


typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;

}STACK, *PSTACK;

void init_stack(PSTACK);
void push_stack(PSTACK, int);//压栈
void traverse(PSTACK);
bool pop(PSTACK, int*);//取出栈顶上的一个元素
bool empty(PSTACK);
void clear(PSTACK);//清除栈中所有元素

int main(void)
{
    STACK S;
    int val;//临时存放用户输入的值，等待压栈
    int Val;//用于临时存放用户想要删除的已在栈中的元素


    init_stack(&S);

    printf("请输入你想存放的值： ");
    scanf("%d", &val);
    push_stack(&S, val);

    printf("请输入你想存放的值： ");
    scanf("%d", &val);
    push_stack(&S, val);

    printf("请输入你想存放的值： ");
    scanf("%d", &val);
    push_stack(&S, val);

    printf("您栈中存放的元素是：");
    traverse(&S);
  
    if(pop(&S, &Val))
       { 
        printf("出栈成功!您出栈的元素是%d\n", Val);
        printf("您栈中存放的元素是：");
        traverse(&S);
       }
    else
        printf("出栈失败!\n");
    
    clear(&S);
    printf("您栈中存放的元素是：");
    traverse(&S);
    

    return 0;
}

void init_stack(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop)
    {
        printf("动态内存分配失败!\n");
        exit(-1);
    }
    else
    {    
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;//or pS->pBottom->pNext = NULL;
    }
}


void push_stack(PSTACK pS, int Val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = Val;
    pNew->pNext = pS->pTop;//新节点的下一个节点指向当前栈顶
    pS->pTop = pNew;//把栈顶更新为pNew


}

void traverse(PSTACK pS)
{
    if(empty(pS))
    {
        printf("您栈中为空!");
        return;
    }
    else
    {
        PNODE p = pS->pTop;
        while (p!=pS->pBottom)
        {
            printf("%d ", p->data);
            p = p->pNext;
        }
        printf("\n");
    }
}

bool empty(PSTACK pS)
{
    if(pS->pBottom == pS->pTop)
        return true;
    else
        return false;

}

bool pop(PSTACK pS, int* pVal)
{
    if(empty(pS))
        return false;
    else
    {
        PNODE r = pS->pTop;
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
        return true;
    }
    
}

void clear(PSTACK pS)
{
    if(empty(pS))
        return;
    else
    {
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while(p != pS->pBottom)
        {
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop =pS->pBottom;
    }
}
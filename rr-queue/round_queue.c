#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int* pBase;
    int front;
    int rear;

}QUEUE;

void init_queue(QUEUE*, int);//把定义的数组初始化
bool en_queue(QUEUE*, int, int);//在数组中放入元素 形成队列
bool full_queue(QUEUE*, int);
void traverse(QUEUE*, int);
bool out_queue(QUEUE*, int*, int);
bool empty_queue(QUEUE*);

int main(void)
{
    QUEUE Q;
    int val;
    int len;

    printf("请输入你想要的队列元素的长度: ");
    scanf("%d", &len);

    init_queue(&Q, len);
 
    en_queue(&Q, 1, len);
    en_queue(&Q, 2, len);
    en_queue(&Q, 3, len);
    en_queue(&Q, 4, len);
    en_queue(&Q, 5, len);
    en_queue(&Q, 6, len);
    en_queue(&Q, 7, len);
    en_queue(&Q, 8, len);

    if(empty_queue(&Q))
        printf("你的队列为空！\n");
    else
        traverse(&Q, len);
    
    
    if(out_queue(&Q, &val, len))
    {
        printf("出队成功!你队列中出队的元素是: %d\n", val);
    }
    else
        printf("出队失败!你的队列为空！\n");
        
    traverse(&Q, len);

    return 0;
}

void init_queue(QUEUE* Pq, int len)//让pBse指向7个连续的空间，front和rear相等且都为0
{
    Pq->pBase = (int*)malloc(sizeof(int) * len);
    Pq->front = 0;
    Pq->rear = 0;
}

bool full_queue(QUEUE* Pq, int len)
{
    if ((Pq->rear+1) % len == Pq->front)
        return true;
    else
        return false;
}

bool en_queue(QUEUE* Pq, int val, int len)
{
    if (full_queue(Pq,len))
        return false;
    else
    {
        Pq->pBase[Pq->rear]= val;
        Pq->rear = (Pq->rear+1) % len;

        return true;
    }

}

void traverse(QUEUE* Pq, int len)
{
    int i = Pq->front;

    while (i != Pq->rear)
    {
        printf("%d ",Pq->pBase[i]);//注意 不能写输出i
        i = (i+1) % len;
    };
    printf("\n");

    return;
}

bool empty_queue(QUEUE* Pq)
{
    if (Pq->front == Pq->rear)
        return true;
    else
        return false;
}
bool out_queue(QUEUE* Pq, int* pVal, int len)
{
    if (empty_queue(Pq))
    {    
        return false;
    }
    else
    {
        *pVal = Pq->pBase[Pq->front];
        Pq->front = (Pq->front+1) % len;
        
    }
    return true;
}
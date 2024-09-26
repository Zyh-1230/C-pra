#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
    int* pBase;
    int front;
    int rear;

}QUEUE;

void init_queue(QUEUE*);//把定义的数组初始化
bool en_queue(QUEUE*, int);//在数组中放入元素 形成队列
bool full_queue(QUEUE*);
void traverse(QUEUE*);

int main(void)
{
    QUEUE Q;
    int val;
     
    init_queue(&Q);
    
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    en_queue(&Q, 8);

    traverse(&Q);

    return 0;
}

void init_queue(QUEUE* Pq)//让pBse指向7个连续的空间，front和rear相等且都为0
{
    Pq->pBase = (int*)malloc(sizeof(int) * 7);
    Pq->front = 0;
    Pq->rear = 0;
}

bool full_queue(QUEUE* Pq)
{
    if ((Pq->rear+1) % 7 == Pq->front)
        return true;
    else
        return false;
}

bool en_queue(QUEUE* Pq, int val)
{
    if (full_queue(Pq))
        return false;
    else
    {
        Pq->pBase[Pq->rear]= val;
        Pq->rear = (Pq->rear+1) % 7;

        return true;
    }

}

void traverse(QUEUE* Pq)
{
    int i = Pq->front;

    while (i != Pq->rear)
    {
        printf("%d ",Pq->pBase[i]);//注意 不能写输出i
        i = (i+1) % 7;
    };
}
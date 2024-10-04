#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    char data;
    struct BTNode* BTLChild;
    struct BTNode* BTRChild;

};

void PreTraverseBtree(struct BTNode*);
void InTraverseBtree(struct BTNode*);
void PostTraverseBtree(struct BTNode*);
struct BTNode* CreateBTree(void);

int main(void)
{
    struct BTNode* pT = CreateBTree();

    PreTraverseBtree(pT);
    printf("\n");
    InTraverseBtree(pT);
    printf("\n");
    PostTraverseBtree(pT);
    printf("\n");

    return 0;
}

void PreTraverseBtree(struct BTNode* pT)
{
    if(NULL != pT->data)
    {
        printf("%c ", pT->data);
        
        if(NULL != pT->BTLChild)
            PreTraverseBtree(pT->BTLChild);
        if(NULL != pT->BTRChild)
            PreTraverseBtree(pT->BTRChild);
    }
}

void InTraverseBtree(struct BTNode* pT)
{
    if(NULL != pT->data)
    {
        if(NULL != pT->BTLChild)
            InTraverseBtree(pT->BTLChild);

        printf("%c ", pT->data);

        if(NULL != pT->BTRChild)
            InTraverseBtree(pT->BTRChild);
    }  
}

void PostTraverseBtree(struct BTNode* pT)
{
    if(NULL != pT->data)
    {
        if(NULL != pT->BTLChild)
            PostTraverseBtree(pT->BTLChild);
        if(NULL != pT->BTRChild)
            PostTraverseBtree(pT->BTRChild);
        printf("%c ", pT->data);
        
    }
}

struct BTNode* CreateBTree(void)
{
    struct BTNode* pA = (struct BTNode*)malloc(sizeof(struct BTNode));
    struct BTNode* pB = (struct BTNode*)malloc(sizeof(struct BTNode));
    struct BTNode* pC = (struct BTNode*)malloc(sizeof(struct BTNode));
    struct BTNode* pD = (struct BTNode*)malloc(sizeof(struct BTNode));
    struct BTNode* pE = (struct BTNode*)malloc(sizeof(struct BTNode));
    struct BTNode* pF = (struct BTNode*)malloc(sizeof(struct BTNode));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    pF->data = 'F';

    pA->BTLChild = pB;
    pA->BTRChild = pD;
    pB->BTLChild = NULL;
    pB->BTRChild = pC;
    pC->BTLChild = pC->BTRChild = NULL;
    pD->BTLChild = pE;
    pD->BTRChild = NULL;
    pE->BTLChild = NULL;
    pE->BTRChild = pF;
    pF->BTLChild = pF->BTRChild = NULL;

    return pA;


}
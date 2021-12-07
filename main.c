#include <stdio.h>
#include <stdlib.h>

struct node{
    int Data;
    struct node *pLeft;
    struct node *pRight;
};

struct node* creatNode(int data);
struct node* insertNode(struct node *pRoot,int data);
void inOrder(pNode);

int main()
{
    struct node *pRoot = NULL;
    pRoot = insertNode(pRoot, 7);
    insertNode(pRoot, 5);
    insertNode(pRoot, 6);
    insertNode(pRoot, 10);
    insertNode(pRoot, 8);
    insertNode(pRoot, 12);

    inOrder(pRoot);
    printf("\n");
    preOrder(pRoot);

    return 0;
}

struct node* creatNode(int data)
{
    struct node *ptr;

    ptr = (struct node*)malloc(sizeof(struct node));

    if(ptr)
    {
        ptr->Data = data;
        ptr->pLeft = NULL;
        ptr->pRight = NULL;
    }

    return ptr;
};

struct node* insertNode(struct node *pRoot,int data)
{
    if(pRoot == NULL)
        pRoot = creatNode(data);

    else if(pRoot->Data > data)
        pRoot->pLeft = insertNode(pRoot->pLeft, data);

    else
        pRoot->pRight = insertNode(pRoot->pRight, data);

    return pRoot;
};

void inOrder(struct node *pRoot)
{
    if(pRoot->pLeft != NULL)
        inOrder(pRoot->pLeft);

    printf("%d\t", pRoot->Data);

    if(pRoot->pRight != NULL)
        inOrder(pRoot->pRight);
}


void preOrder(struct node *pRoot)
{
    printf("%d\t", pRoot->Data);

    if(pRoot->pLeft != NULL)
        preOrder(pRoot->pLeft);

    if(pRoot->pRight != NULL)
        preOrder(pRoot->pRight);
}

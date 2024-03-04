#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int data;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *createNode(int a)
{
    Tree *p;
    p = (Tree *)malloc(sizeof(Tree));
    p->data = a;
    p->right = NULL;
    p->left = NULL;
    return p;
}

void insert(Tree **head, int a)
{
    if (*head == NULL)
    {
        *head = createNode(a);
        return;
    }
    if ((*head)->data <= a)
    {
        insert(&((*head)->right), a);
        return;
    }
    insert(&((*head)->left), a);
    return;
}

void readTree(Tree **p)
{
    int New;
    printf("\nEnter the value ");
    scanf("%d", &New);
    insert(p, New);
}

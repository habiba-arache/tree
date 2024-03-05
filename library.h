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

void showTree(Tree *head)
{
    if (head != NULL)
        printf("%d ", head->data);
    showTree(head->left);
    showTree(head->right);
}

int existX(Tree *t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
            return 1;
        if (t->data > x)
            return existX(t->left, x);
        return existX(t->right, x);
    }
    return 0;
}

Tree *findX(Tree *t, int x)
{
    if (t != NULL)
    {
        if (t->data == x)
            return t;
        if (t->data > x)
            return findX(t->left, x);
        return findX(t->right, x);
    }
    printf("not found\n");
    return NULL;
}
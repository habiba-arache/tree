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

Tree *insert(Tree *head, int a)
{
    if (head == NULL)
    {
        return createNode(a);
    }

    if (head->data <= a)
    {
        head->right = insert(head->right, a);
        return head;
    }
    head->left = insert(head->left, a);
    return head;
}

void readTree(Tree **p)
{
    int New;
    printf("\nEnter the value ");
    scanf("%d", &New);
    *p = insert(*p, New);
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

// let's do it again !!
int Height(Tree *head)
{
    if (head->right == head->left == NULL)
        return 1;
    if (Height(head->right) >= Height(head->left))
        return (1 + Height(head->right));
    return (1 + Height(head->left));
}

int h = 1;
int depth(Tree *head)
{
    if (head->right == head->left == NULL && h == Height(head))
        return head->data;
    if (Height(head->right) > Height(head->left))
    {
        h++;
        return depth(head->right);
    }
    h++;
    return depth(head->left);
}
int isBalanced(Tree *head)
{
    if (Height(head->left) != Height(head->right)) // verification : the height's range
        return 0;
    return 1;
}
int isSymetric(Tree *left, Tree *right)
{
    if (right == left == NULL)
        return 1;
    if (right->data != left->data)
        return 0;
    if (isSymetric(right->left, left->right) != 1 || isSymetric(right->right, left->left) != 1)
        return 0;
}
// done

void reverse(Tree *root)
{
    Tree *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
// done

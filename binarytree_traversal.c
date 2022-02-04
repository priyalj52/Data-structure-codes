#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
} s1;

struct node *create_node(int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->data = val;
    return ptr;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *p = create_node(7);
    struct node *p1 = create_node(2);
    struct node *p2 = create_node(1);
    struct node *p3 = create_node(0);
    struct node *p4 = create_node(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("*** preorder traversal***\n");
    preorder(p);
    printf("\n*** postorder traversal***\n");
    postorder(p);
    printf("\n*** inorder traversal***\n");
    inorder(p);
    return 0;
}
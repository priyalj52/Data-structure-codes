#include <stdio.h>
#include <stdlib.h>
#define Count 10
struct node
{
    int data;
    struct node *left, *right;
};
struct node *create()
{
    int x;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    printf("\nenter the value of new node,write -1 if no node\n");
    scanf("%d", &x);
    if (x == -1)
        return 0;
    root->data = x;

    printf("\nenter the left child of %d", x);
    root->left = create();
    printf("\nenter the right child of %d", x);
    root->right = create();
    return root;
}

struct node *insert(struct node *root, int item)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (item == root->data)
        {
            printf("insertion is not possible as %d already exists", item);
            return 0;
        }
        else if (item < root->data)
            root = root->left;
        else
            root = root->right;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    if (item < prev->data)
        prev->left = new;
    else
        prev->right = new;
}
struct node *inOrderPre_or_Suc(struct node *root)
{
    if (root->left != NULL)
    {
        root = root->left;
        while (root->right != NULL)
        {
            root = root->right;
        }
    }

    else
    {
        root = root->right;
        while (root->left != NULL)
        {
            root = root->left;
        }
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{

    struct node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }

    else
    {
        iPre = inOrderPre_or_Suc(root);
        root->data = iPre->data;
        if (root->left != NULL)
            root->left = deleteNode(root->left, iPre->data);
        else
            root->right = deleteNode(root->right, iPre->data);
    }
    return root;
}

void print_tree(struct node *root, int space)
{
    if (root == NULL)
        return;
    space = space + Count;
    print_tree(root->right, space);
    printf("\n");
    for (int i = Count; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print_tree(root->left, space);
}
struct node *inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return root;
}
struct node *preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);

        preorder(root->right);
    }
    return root;
}
struct node *postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    return root;
}
void display(struct node *root)
{
    printf("the inorder traversal is:\n");
    inorder(root);
    printf("\nthe preorder traversal is:\n");
    preorder(root);
    printf("\nthe postorder traversal is:\n");
    postorder(root);
}

int main()
{
    int ch, m;
    printf("\n**Binary Search Tree****\n");
    struct node *root = create();
    print_tree(root, 0);
    while (1)
    {
        printf("enter \n 1- Insertion\n 2- deletion\n 3- display\n 4- exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value to be inserted\n");
            scanf("%d", &m);
            insert(root, m);
            printf("after insertion\n");
            print_tree(root, 0);
            break;

        case 2:
            printf("enter the value to be deleted\n");
            scanf("%d", &m);
            deleteNode(root, m);
            printf("after deletion\n");
            print_tree(root, 0);
            break;
        case 3:
            display(root);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("wrong choice");
            break;
        }
        printf("\npriyal jain,cse3,4376802720\n");
    }
}
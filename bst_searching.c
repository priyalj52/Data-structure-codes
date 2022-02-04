#include<stdio.h>
#include<stdlib.h>
#define count 10
struct node
{
    int data;
    struct node *left,*right;
};

struct node* create()

{
  int x;
 
  printf("\n enter the value of new node,enter -1 for no node\n");
  scanf("%d",&x);
  if(x==-1)
  return 0;
  struct node* root=(struct node*)malloc(sizeof(struct node));
   root->data=x;
   printf("\nenter the left child of %d ",x);
   root->left=create();
   printf("\nenter the right child %d ",x);
   root->right=create();
   return root;
}

struct node* print_tree(struct node* root,int space)
{
    if(root==NULL)
     return 0;
    space+=count;
    print_tree(root->right,space);
    printf("\n");
    for (int i = count; i < space; i++)
    printf(" ");
    printf("%d\n",root->data);
    return print_tree(root->left,space);
    

}
//searching using recursion
 struct node* search(struct node* root,int val)
 {
     if(root!=NULL)
     {
         if(root->data==val)
         return root;
         else if(val<root->data)
          return search(root->left,val);
          else
          return search(root->right,val);
     }
     
 }

 // searching using iteration

 struct node* search_iter(struct node* root,int val)
 {  if(root==NULL)
      return 0;
     while (root!=NULL)
 {
     if(val==root->data)
     return root;
     else if(val<root->data)
     root=root->left;
     else
     root=root->right;
 }
 
 
     
      
 }
 int main()
 {
     struct node* root;
     int val;
     root=create();
     printf("enter the value you want to search");
     scanf("%d",&val);
     
    /* if(search(root,val))
     printf("element found ");
     else
     printf("element not found");
     */

      if(search_iter(root,val))
     printf("element found ");
     else
     printf("element not found");
 }

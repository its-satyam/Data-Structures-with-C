#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
        int info;
        struct tree *left;
        struct tree *right;

}tree;
tree * Insert(tree *,int );
void leafnodes(tree*,int*);
int main()
{
    tree *root = NULL;
    int x,ch;
    while(1)
    {
        printf("Enter the value: ");
        scanf("%d",&x);
        root=Insert(root,x);
        printf("Enter 1 if you wish to continue adding elements and 0 if you have created the BST: ");
        scanf("%d",&ch);
        if(ch==0)
        break;
    }
    int c=0;
    leafnodes(root,&c);
    printf("The number of leaf nodes in the BST are: %d",c);
}
tree * Insert(tree *node,int value)
{
        if(node==NULL)
        {
                tree *p;
                p = (tree *)malloc(sizeof(tree));
                p -> info = value;
                p -> left = p -> right = NULL;
                return p;
        }
        if(value >(node->info))
        {
                node->right = Insert(node->right,value);
        }
        else if(value < (node->info))
        {
                node->left = Insert(node->left,value);
        }
        return node;
}
void leafnodes(tree* node,int* count)
{
 
    if(node != NULL)
    {
        leafnodes(node->left,count);
        if((node->left == NULL) && (node->right == NULL))
        {
            (*count)++;
        }
        leafnodes(node->right,count);
    } 
}
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
        int info;
        struct tree *left;
        struct tree *right;

}tree;
tree* Insert(tree* ,int);
tree *removeNode(tree*, int );
int getRightMin(tree *);
void Inorder(tree *);
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
    int d;
    printf("Enter the number you wish to delete: ");
    scanf("%d",&d);
    root = removeNode(root,d);
    printf("After deletion, the BST in inorder is: ");
    Inorder(root);
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
tree *removeNode(tree *root, int val)
{
    if(root == NULL)
        return NULL;
    if(root->info < val)
        root->right = removeNode(root->right,val);
    else if(root->info > val)
        root->left = removeNode(root->left,val);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if(root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            int rightMin = getRightMin(root->right);
            root->info = rightMin;
            root->right = removeNode(root->right,rightMin);
        }

    }
    return root;
}
int getRightMin(tree *root)
{
    tree *temp = root;
    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->info;
}
void Inorder(tree *node)
{
        if(node==NULL)
            return;
        Inorder(node->left);
        printf("%d ",node->info);
        Inorder(node->right);
}
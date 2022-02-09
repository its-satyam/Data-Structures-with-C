#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} node;

node *insert(node *, node *, int);
void display(node *);

int main()
{
    int num, ch;
    node *F = NULL, *R = NULL;
    while (1)
    {
        printf("Enter the value: ");
        scanf("%d", &num);
        R = insert(F, R, num);
        if (F == NULL)
            F = R;
        printf("Press 1 to continue adding elements to the queue and 0 if you have finished adding: ");
        scanf("%d",&ch);
        if(ch==0)
        break;
    }
    printf("The queue when printed like stack would look like:\n");
    display(F);
    return 0;
}

node *insert(node *F, node *R, int N)
{
    node *p = NULL;
    p = (node *)malloc(sizeof(node));
    if (p != NULL)
    {
        p->info = N;
        if (F == NULL && R == NULL)
            R = p;
        else
        {
            R -> next = p;
            R = p;
        }
        R->next = NULL;
    }
    printf("Element is added\n");
    return R;
}

void display(node *F)
{
    if(F == NULL)
        return;
    else
    {
        display(F->next);

        printf("%d\t", F->info);
    }
    printf("\n");
}
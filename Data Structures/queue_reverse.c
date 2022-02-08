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
        printf("Press 1 to create a queue\nPress 2 to display the queue in reverse order\nPress 3 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &num);
            R = insert(F, R, num);
            if (F == NULL)
                F = R;
            break;

        case 2:
            display(F);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }
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
    printf("Element is added\n\n\n");
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


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} node;

node *PUSH(node *, int);
void display(node *);

int main()
{
    int ch, num;
    node *top = NULL;
    while (1)
    {
            printf("Enter the value: ");
            scanf("%d", &num);
            top = PUSH(top, num);
            printf("Enter 1 to continue adding elements to the stack and 0 if you have added the desired elements: ");
            scanf("%d",&ch);
            if(ch==0)
            break;
    }
    printf("The elements of the stack when printed like queue would look like:\n");
    display(top);
    return 0;
}
node* PUSH(node *top, int N)
{
    node *p = NULL;
    p = (node*)malloc(sizeof(node));
    if(p != NULL)
    {
        p->info = N;
        if(top == NULL)
            p->next = NULL;
        else
        {
            p->next = top;
        }
        top = p;
    }
    printf("Element is added\n");
    return top;
}
void display(node *top)
{
    if(top == NULL)
        return;
    else
    {
        display(top->next);

        printf("%d ", top->info);
    }
}
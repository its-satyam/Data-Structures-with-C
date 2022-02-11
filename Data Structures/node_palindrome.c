#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int info;
    struct Node *next;
} node;

void create(node **, node**, int);
void count(node*, node*);
int check(int);

int main()
{
    int num, ch;
    node *L = NULL, *R = NULL, *L2 = NULL, *R2 = NULL;
    while (1)
    {
        printf("Press 1 to create a node\nPress 2 to count the palindrome keys\nPress 3 to exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &num);
            create(&L, &R, num);
            break;

        case 2:
            count(L, R);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void create(node **L1, node **R1, int N)
{
    node *p = NULL;
    p = (node*)malloc(sizeof(node));
    if(p != NULL)
    {
        p->info = N;
        if(*L1 == NULL && *R1 == NULL)
            *L1 = *R1 = p;
        else
        {
            (*R1)->next = p;
            *R1 = p;
        }
        (*R1)->next = NULL;
        printf("Element is added\n");
    }
}

void count(node *L1, node *R1)
{
    int count = 0;
    if(L1 == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        int N;
        while(L1 != NULL)
        {
            N = L1->info;
            if(check(N))
                count++;

            L1 = L1->next;
        }
    printf("The number of palindrome keys are %d\n", count);
    }
}

int check(int N)
{
    int rem, rev=0, N2 = N;
    while(N>0)
    {
        rem = N%10;
        rev = rev*10 + rem;
        N = N/10;
    }
    if(rev == N2)
        return 1;
    else    
        return 0;
}
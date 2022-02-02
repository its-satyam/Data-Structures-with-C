#include<stdio.h>
#define MAX 10
void Enqueue(int [],int*);
void Dequeue(int [],int*,int*);
void Display(int [],int,int);
int main()
{
    int Q[MAX], F = -1, R = -1, choice, test=1;
    do{
        printf("Press 1 for ENQUEUE Operation\nPress 2 for DEQUEUE Operation\nPress 3 for DISPLAY the elements of queue: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                Enqueue(Q, &R);
                if(R == 0)
                    F=0;
                break;
        case 2:
                Dequeue(Q, &F, &R);
                if(F == -1)
                    R = -1;
                break;
        case 3:
                Display(Q, F, R);
                break;
        default:
                printf("Invalid Choice\n");
        }
        printf("Press 1 for continue\nPress 0 to stop: ");
        scanf("%d", &test);
    }
    while(test == 1);
}
void Enqueue(int Q[], int *R)
{
    int x;
    if(*R == MAX-1)
        printf("Queue is full\n");
    else{
        printf("Enter the element: ");
        scanf("%d", &x);
        (*R)++;
        Q[*R] = x;
        printf("Element is added to queue\n");
    }
}

void Dequeue(int Q[], int *F, int *R)
{
    if(*F == -1)
        printf("Queue is empty\n");
    else if(*F == *R) {
        printf("Dequeued element is %d\n", Q[*F]);
        *F = -1;
    }
    else{
        printf("Dequeued element is %d\n", Q[*F]);
        (*F)++;
    }
}
void Display(int Q[], int F, int R)
{
    if(F == -1)
        printf("Queue is empty\n");
    else {
        for( ; F<=R ; F++)
            printf("%d\n", Q[F]);
    }
}
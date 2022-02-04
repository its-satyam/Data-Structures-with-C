#include<stdio.h>
#define MAX 10
int Eequeue(int [],int,int);
int Dequeue(int [],int,int);
void Display(int [],int,int);
void main()
{
    int Q[MAX], F = -1, R = -1, choice, test=1;
    do{
        printf("Press 1 for ENQUEUE Operation\nPress 2 for DEQUEUE Operation\nPress 3 for DISPLAY the elements of queue: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                R = Eequeue(Q, F, R);
                if(R == 0)
                    F=0;
                break;
        case 2:
                F = Dequeue(Q, F, R);
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

int Eequeue(int Q[], int F, int R)
{
    int x;
    if((R+1)%MAX == F)
        printf("Queue is full\n");
    else if(R == -1){
        printf("Enter the element: ");
        scanf("%d", &x);
        R=0;
        Q[R] = x;
        printf("Element is added to Queue\n");
    }
    else{
        printf("Enter the element: ");
        scanf("%d", &x);
        R = (R+1)%MAX;
        Q[R] = x;
        printf("Element is added to Queue\n");
    }
    return R;
}

int Dequeue(int Q[], int F, int R)
{
    if(F == -1)
        printf("Queue is Empty\n");
    else if(F == R){
        printf("Dequeued element is %d\n", Q[F]);
        F = -1;
    }
    else{
        printf("Dequeued element is %d\n", Q[F]);
        F = (F+1)%MAX;
    }
    return F;
}

void Display(int Q[], int F, int R)
{
    if(F == -1)
        printf("Queue is Empty\n");
    while(F != R)
    {
        printf("%d\n", Q[F]);
        F = (F+1)%MAX;
    }
    if(F != -1)
        printf("%d\n", Q[F]);
}
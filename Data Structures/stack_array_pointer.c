#include<stdio.h>
#define MAX 10
void Push(int [],int*);
void Pop(int [],int*);
void Display(int [],int*);
void Peek(int [],int*);
int main()
{
    int stack[MAX], top = -1, choice, test=1;
    do{
        printf("Press 1 for PUSH Operation\nPress 2 for POP Operation\nPress 3 for DISPLAY the elements of stack\nPress 4 for PEEK Operation: ");
            scanf("%d", &choice);
        switch (choice)
        {
        case 1:
                Push(stack, &top);
                break;
        case 2:
                Pop(stack, &top);
                break;
        case 3:
                Display(stack, &top);
                break;
        case 4:
                Peek(stack, &top);
                break;
        default:
                printf("Invalid Choice\n");
        }
        printf("Press 1 for continue\nPress 0 to stop: ");
        scanf("%d", &test);
    }
    while(test == 1);
}

void Push(int stack[], int *top)
{
    int x;
    if(*top == MAX-1)
        printf("Stack is full\n");
    else{
        printf("Enter the element: ");
        scanf("%d", &x);
        (*top)++;
        stack[*top] = x;
        printf("Element is added to stack\n");
    }
}
void Pop(int stack[], int *top)
{
    if(*top == -1)
        printf("Stack is empty\n");
    else{
        printf("Popped element is %d\n", stack[*top]);
        (*top)--;
    }
}
void Display(int stack[], int *top)
{
    int temp;
    temp = *top;
    if(temp == -1)
        printf("Stack is empty\n");
    else{
        for( ; temp > -1 ; temp--)
        printf("%d\n", stack[temp]);
    }
}
void Peek(int stack[], int *top)
{
    if(*top == -1)
        printf("Stack is empty\n");
    else{
        printf("%d\n", stack[*top]);
    }
}
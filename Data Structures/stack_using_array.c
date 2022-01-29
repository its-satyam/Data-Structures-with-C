#include<stdio.h>
#define MAX 5
int Push(int [],int);
int Pop(int [],int);
void Display(int [],int);
void Peek(int [],int);
int main()
{
    int stack[MAX],top=-1,ch;
    do
    {
     printf("Enter your choice :\n");
     printf("1 for Push \n");
     printf("2 for Pop \n");
     printf("3 for Display \n");
     printf("4 for Peek \n");
     scanf("%d",&ch);
   switch(ch)
   {
   case 1:
        top=Push(stack,top);
       break;
   case 2:
        top=Pop(stack,top);
       break;
   case 3:
        Display(stack,top);
       break;
   case 4:
        Peek(stack,top);
       break;
   default:
       printf("Wrong input");
   }
   } while (ch<=4);
  }
  int Push(int stack[],int top)
  {
      int x;
      if(top==MAX-1)
      {
          printf("Stack Overflow\n");
      }
      else
      {
          printf("Enter a number :");
          scanf("%d",&x);
          top++;
          stack[top]=x;
      }
    return top;
  }
  int Pop(int stack[],int top)
  {
      if(top==-1)
      {
          printf("\nStack Underflow");
      }
      else
      {
          printf("Number poped is :");
          printf("%d\n",stack[top]);
          top--;
      }
      return top;
  }
  void Display(int stack[],int top)
  {
      if(top==-1)
      {
          printf("Empty stack\n");
      }
      else
       printf("Stack elements are :\n");
      while(top!=-1)
      {
          printf("%d ",stack[top]);
          top--;
      }
      printf("\n");
 }
 void Peek(int stack[],int top)
 {
     if(top==-1)
     {
         printf("Stack is empty\n");
     }
     else
     printf("Peek element is :");
     printf("%d\n",stack[top]);
 }
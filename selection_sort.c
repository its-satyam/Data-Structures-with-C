#define MAX 100
#include<stdio.h>
void Selectionsorting(int [],int);
int main()                           
{
    int A[MAX],N;
    printf("Enter the size of array :");
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }    
   Selectionsorting(A,N);
   for(int i=0;i<N;i++)
   {
       printf("%d ",A[i]);
   }
}
void Selectionsorting(int A[],int N)
{
    int i,j,pos=0,min=0;
    for(int i=0;i<N;i++)
    {
     min=A[i];
     pos=i;
     for(j=i+1;j<N;j++)
     {
       if(A[j]<min)
       {
           min=A[j];
           pos=j;
       }

     }
     if(pos!=i)
     {
         A[pos]=A[i];
         A[i]=min;
     }

    }
}
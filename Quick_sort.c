#define MAX 100
#include<stdio.h>
void quicksort(int [],int,int);
int main()
{
    int n,t=0;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    quicksort(A,t,n-1);
    printf("The sorted  array is: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}
void quicksort(int A[],int lb,int ub)
{
    int i=lb,j=ub,key=A[lb],t=0;
    if(lb>=ub)
    {
        return;
    }
    while(i<=j)
    {
        while(key>=A[i] &&i<j)
        {
            i++;
        }
        while(key<A[j])
        {
            j--;
        }
        if(i<j)
        {
            t=A[i];
            A[i]=A[j];
            A[j]=t;
        }
    }
    A[lb]=A[j];
    A[j]=key;
quicksort(A,lb,j-1);
quicksort(A,j+1,ub);

}
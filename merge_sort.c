#define MAX 100
#include<stdio.h>
void mergesort(int [],int [],int,int);
void merge(int [],int [],int,int,int);
int main()
{
    int A[MAX],T[MAX];
    int n;
    printf("Enter the value of n :");
    scanf("%d",&n);
    printf("Enter the array elements :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    mergesort(A,T,0,n-1);
 for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
}                        
void mergesort(int A[],int T[],int lb,int ub)
{
    int mid=0;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
    mergesort(A,T,lb,mid);
    mergesort(A,T,mid+1,ub);
    merge(A,T,lb,mid,ub);
}    
}             
void merge(int A[],int T[],int lb,int mid,int ub)
{
    int k=lb,i=0,c=lb,LE=mid;
    while(lb<=LE && mid+1<=ub)
    {
        if(A[lb]<A[mid+1])
        {
            T[k]=A[lb];
            lb++;
            k++;
        }
        else
        {
            T[k]=A[mid+1];
            k++;
            mid++;
        }
    } 
    while(lb<=LE)
    {
        T[k]=A[lb];
        k++;
        lb++;
    }
    while(mid+1<=ub)
    {
        T[k]=A[mid+1];
        k++;
        mid++;
    }
    for(int i=c;i<=ub;i++)
    {
        A[i]=T[i];
    }
}
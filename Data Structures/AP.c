#include<stdio.h>
int main()
{
    int n,d=0,i,c=0,p=0;
    printf("Enter the size of array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array :");
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    d=a[1]-a[0];
    c++;
    for(i=1; i<n; i++)
    {
        for(int j=i+1; j<=i+1; j++)
        {
            p=a[j]-a[i];
        }
        if(p==d)
            c++;
        else
            break;
    }
    if(c==n-1)
    {
        printf("GIVEN SEQUENCE IS IN AP");
    }
    else
        printf("Not in AP");
}
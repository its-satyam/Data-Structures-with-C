#include<stdio.h>
int check(int [],int,int,int);
int main()
{
    int n, i, count=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the %d elements: ", n);
    for(i=0 ; i<n ; i++)
    scanf("%d", &a[i]);
    for(i=0 ; i<n ; i++){
        if(check(a, n, a[i], i)){
            count++;
        }
        if(count == 4){
            printf("The fourth non repeating element is %d", a[i]);
            break;
        }
    }
    return 0;
}
int check(int arr[], int n, int x, int j)
{
    int i;
    for(i=0 ; i<n ; i++){
        if(i != j && arr[i] == x){
            return 0;
        }
    }
    return 1;
}
#define MAX 100
 #include<stdio.h>
 void Insertionsorting(int [],int);
 int main()
 {
     int A[MAX],N,i=0;
 printf("Enter the size of array :\n");
 scanf("%d",&N);
 printf("Enter the array elements : \n");
 for(i=0;i<N;i++)
 {
     scanf("%d",&A[i]);

 }    

 Insertionsorting(A,N);
  printf("\nSorted array :");
 for(i=0;i<N;i++)
 {
     printf("%d ",A[i]);
 }
 
 }
 
 void Insertionsorting(int A[],int N)
 { 
    int i,j,t=0;
    for(i=0;i<N;i++)
     {
        t=A[i];
        j=i-1;
        while(j>=0 && t<A[j])
        {
          A[j+1]=A[j];
          j--;
            
        }
        A[j+1]=t;
     }
}

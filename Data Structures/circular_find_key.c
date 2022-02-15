#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int info;
    struct node* next;
}nodetype;
int main()
{
   nodetype *str=NULL,*p=NULL;
   int ch,x;
   while(1)
   {
       p=(nodetype*)malloc(sizeof(nodetype));
       if(p!=NULL)
       {
           printf("Enter the value: ");
           scanf("%d",&x);
           p->info=x;
           if(str==NULL)
           {
               str=p;
               p->next=str;
           }
           else
           {
               p->next=str->next;
               str->next=p;
               str=p;
           }
           printf("Press 1 to continue and press 0 if you have added the desired elements in the linked list: ");
           scanf("%d",&ch);
           if(ch==0)
           break;
       }
    }
    int key;
    printf("Enter the value of the key: ");
    scanf("%d",&key);
    p=str->next;
    int f=0;
    if(p->info==key)
    {
        str->next=p->next;
        free(p);
        f=1;
    }
    else
    {
    while((p->next)->info!=key && p!=str)
       p=p->next;
       if((p->next)->info==key)
       {
       nodetype* q=p->next;
       if((p->next)==str)
       str=p;
       p->next=q->next;
       free(q);
       f=1;
       }
    }
    if(f==0)
    printf("Key not found\n");
    printf("The linked list is: ");
    p=str->next;
    do
    {
        printf("%d ",p->info);
        p=p->next;
    }while(p!=str->next);
    free(p);
}
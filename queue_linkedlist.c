#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *add;
};
struct node *start = NULL,*new1,*temp;
void enqueue ()
{
    if (start == NULL)
    {
        printf("Enter the data ");
        int n;
        scanf("%d",&n);
        start = (struct node*) malloc(sizeof(struct node));
        start -> data =n;
        start ->add = NULL;
        temp = start;
    }
    else
    {
        printf("Enter the data");
        int n;
        scanf("%d",&n);
        new1 = (struct node*)malloc(sizeof(struct node));
        new1 -> data = n;
        new1 -> add =  NULL;
        temp -> add = new1;
        temp = temp ->add;
    }
}
void  dequeue()
{
    if (start ==   NULL)
    {
        printf("Queue is empty");
    }
    else
    { int n;
      temp = start;
      n = temp -> data;
      printf("Deleted Data = %d",n);
      temp = temp -> add;
      start = temp;

    }
}
void display ()
{
    if (start ==  NULL)
    {
        printf("Queue is empty ");
    }
    else
    {
      temp =start;
      while(temp!= NULL)
      {
        printf("%d\t", temp ->data);
        temp = temp -> add;
      }
    }
}
int main ()
{
int t=1 ,op;

    while (t==1)
    {
        printf("\npress 1 to enqueue\npress 2 to dequeue\npress 3 for display\npress 4 to quit\n");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
         enqueue();
         break;
         
        case 2:
         dequeue();
         break;
         
        case 3:
         display();
         break;
         case 4:
         t=0;
         break;
         
        default:
         printf("Enter valid input");
         
        };
    }
}
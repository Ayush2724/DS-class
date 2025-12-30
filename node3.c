#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *add;
};
struct node *start,*new1,*temp,*prev,*next,*current;
void first_insert()
{
    
    if (start == NULL)
    {
        printf("\nNode not found");
    }
    else
    {
      int n ;
    printf("\n Enter the elements ");
    scanf("%d",&n);
   new1 = (struct node*)malloc(sizeof(struct node));
    new1 -> data = n;
    new1 -> add = NULL;
    new1 -> add = start;
    start = new1;    
}}
void middle_insert()
{
    
    if (start == NULL)
    {
        printf("\nNode not found");
    }
    else
    {
    int n ,index,i=1;
    printf("\n Enter the elements ");
    scanf("%d",&n);
    printf("\n Enter the index ");
    scanf("%d",&index);
   new1 = (struct node*)malloc(sizeof(struct node));
    new1 -> data = n;
    new1 -> add = NULL;
    next = start;
    while (i<index)
    {
        prev = next;
        next = next -> add;
        i++;
    }
    prev->add = new1;
    new1->add = next;
}}
void last_insert()
{
    
    if (start == NULL)
    {
        printf("\nNode not found");
    }
    else
    {
    int n ;
    printf("\n Enter the elements ");
    scanf("%d",&n);
   new1 = (struct node*)malloc(sizeof(struct node));
    new1 -> data = n;
    new1 -> add = NULL;
    temp  = start;
    while (temp->add!=NULL)
    {
        temp = temp->add;
    }
    temp ->add= new1;
}}
void first_delete()
{
    
    if (start == NULL)
    {
        printf("\nNode not found");
    }
    else
{
    int n;
  temp = start;
  n =temp -> data;
  printf("The element deleted is = %d",n);
  temp = temp ->add;
  free(start);
  start = temp;
}}
void middle_delete()
{
    int n,i=1;
    printf("\n Enter the index \n");
    scanf("%d",&n);
    temp = start;
    while(i<n){
        prev =temp;
        temp = temp->add;
        i++;
    }
    prev ->add =temp->add;
    free(temp);
}
void last_delete()
{
    if(start == NULL)
    {
        printf("Node not found");
    }
    else
    {

     int n ;
    temp  = start;
    while(temp ->add!= NULL)
    {   prev = temp;
        temp = temp ->add;     
    } 
    n = temp ->data;
    printf(" The deleted element is = %d",n);
    prev ->add=NULL;
    free(temp);
    }
}

void create()
{
    int n;
    printf("\nEnter the element ");
    scanf("%d",&n);
    start = (struct node*)malloc(sizeof(struct node));
    start -> data = n;
    start -> add = NULL;
    temp = start;
    char ch;
    printf("\nDo you want to continue adding elements ?? ");
    scanf(" %c",&ch);
    while( ch == 'y' || ch == 'Y')
    {
         printf("\n Enter the element ");
         scanf("%d",&n);
         new1 =  (struct node*)malloc(sizeof(struct node));
         new1 -> data = n;
         new1 -> add = NULL;
         temp -> add = new1;
         temp = temp -> add;
         printf("\nDo you want to continue adding elements ?? ");
         scanf(" %c",&ch);

    }

}
void reverse()
{
   current = start;
   temp = current;
   prev = current;
   prev ->add =NULL;
   while (current->add != NULL)
   {
    prev = current;
    current = current ->add;
    temp = current;
    temp-> add = prev;

   }          
   start =current;

}
int main ()
{
    int op;
    int t=1 ;

    while (t==1)
    {
        printf("\npress 1 for first insert\npress 2 for middle insert\npress 3 for last insert\npress 4 for first delete\npress 5 for midde delete\npress 6 for last delete\npress 7 for display\npress 8 to quit \npress 9 to create\npress 10 for reverse\n"); 
        scanf("%d",&op);
        switch(op)
        {
        case 1:
         first_insert();
         break;
         
        case 2:
         middle_insert();
         break;
         
        case 3:
         last_insert();
         break;
         
        case 4:
         first_delete();
         break;
         
        case 5:
         middle_delete();
         break;
         
        case 6:
         last_delete();
         break;
         
        case 7:
         display();
         break;
         
        case 8:
         t=0;
         break;
         case 9:
         create ();
         break;
         case 10:
    reverse();
    break;
         default:
         printf("Enter valid input");
         
        };
    }
}
void display()
{
    if (start == NULL)
    {
        printf("\nNode not found");
    }
    else
    { 
        temp = start;
      while (temp != NULL)
      {
        printf("%d\t",temp-> data);
        temp = temp ->add; 
      }
      
    }
    
}
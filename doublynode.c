#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next,*prev;
};
struct node *start,*new1,*temp,*prev1,*next1;
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
    new1 -> prev = NULL;
    new1 -> prev = NULL;
    new1 -> next =start;
    start -> prev = new1;
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
    new1 -> prev = NULL;
    new1 -> prev = NULL;
    next1 = start;
    while (i<index)
    {
        prev1 = next1;
        next1 = next1 -> next;
        i++;
    }
    printf("\nprev1 =%d and next1 = %d",prev1->data,next1->data);
    new1 -> prev = prev1;
    new1 -> next = next1;
    prev1 -> next = new1;
    next1 -> prev = new1;
 
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
    new1 -> prev = NULL;
    new1 -> next= NULL;
    temp  = start;
    while (temp->next!=NULL)
    {
       temp = temp -> next;
    }
     new1 ->prev = temp;
        temp ->next  = new1;
    
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
  temp = temp -> next;
  free(start);
  start = temp;
}}
void middle_delete()
{
    int n,i=1,index;
    printf("Enter the index ");
    scanf("%d",&index);
    next1 = start;
    while(i<index)
    {
        prev1 = next1;
        next1= next1 ->next;
        i++;
    }
    n = next1 ->data;
    printf("Element deleted  = %d",n);
    temp = next1;
    temp = temp -> next;
    prev1 -> next = temp;
    temp -> prev = prev1;

    free(next1);
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
    while(temp ->next!= NULL)
    {   prev1 = temp;
        temp = temp -> next;     
    } 
    n = temp ->data;
    prev1 -> next = NULL;
    printf(" The deleted element is = %d",n);
    free(temp);
    }
}
void display() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        temp = start;
        while (temp != NULL) {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}



void create()
{
    int n;
    printf("\nEnter the element ");
    scanf("%d",&n);
    start = (struct node*)malloc(sizeof(struct node));
    start -> data = n;
    start -> prev = NULL;
    start -> next = NULL;
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
         new1 -> prev = NULL;
         new1 -> next = NULL;
         new1->prev = temp;
         temp->next = new1;
         temp = temp -> next;
         printf("\nDo you want to continue adding elements ?? ");
         scanf(" %c",&ch);

    }

}
int main ()
{
    int op;
    int t=1 ;

    while (t==1)
    {
        printf("\npress 1 for first insert\npress 2 for middle insert\npress 3 for last insert\npress 4 for first delete\npress 5 for midde delete\npress 6 for last delete\npress 7 for display\npress 8 to quit \npress 9 to create ");
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
         default:
         printf("Enter valid input");
         
        };
    }
}
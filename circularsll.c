#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};

struct node *start = NULL, *temp, *new1;

/* create first node */
void create()
{
    int n;
    printf("Enter element: ");
    scanf("%d", &n);

    start = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    start->data = n;
    start->add = start;      // points to itself (circular)
}

/* traverse / display */
void display()
{
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    temp = start;
    printf("\nCircular list: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->add;
    } while (temp != start);
}

/* insertion at beginning */
void insert_begin()
{
    int n;
    printf("Enter element to insert at beginning: ");
    scanf("%d", &n);

    if (start == NULL)
    {
        create();
        return;
    }

    new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = n;
    new1->add= NULL;
    temp = start;
    while(temp->add!=start)
    {
        temp=temp->add;
    }
    new1->add = start;
    start = new1;
    temp ->add =start;
}
void insert_end()
{
    int n;
    printf("Enter element to insert at end: ");
    scanf("%d", &n);

    if (start == NULL)
    {
        create();
        return;
    }

    new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = n;

    temp = start;
    while (temp->add != start)
        temp = temp->add;

    temp->add = new1;
    new1->add = start;
}

/* deletion at beginning */
void delete_begin()
{
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    // only one node
    if (start->add == start)
    {
        printf("\nDeleted element = %d", start->data);
        free(start);
        start = NULL;
        return;
    }
   struct node * temp2;
    temp =start;
    temp2 = start;
    temp = temp->add;
    while(temp2->add!=start)
    {
         temp2 = temp2->add;
    }
    temp2 ->add =temp;
    free(start);
    start =temp;

}

/* deletion at end */
void delete_end()
{
    struct node * temp2;
    if (start == NULL)
    {
        printf("\nList is empty");
        return;
    }

    // only one node
    if (start->add == start)
    {
        printf("\nDeleted element = %d", start->data);
        free(start);
        start = NULL;
        return;
    }
 temp = start;
 while(temp->add!=start)
 {  temp2 =temp;
    temp =temp->add;
}
free(temp);
temp2->add = start;

}

int main()
{
    int op, t = 1;

    while (t == 1)
    {
        printf("\n\n1.Create first node");
        printf("\n2.Insert at beginning");
        printf("\n3.Insert at end");
        printf("\n4.Delete at beginning");
        printf("\n5.Delete at end");
        printf("\n6.Display");
        printf("\n7.Quit\n");
        printf("Enter choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: create();        break;
        case 2: insert_begin();  break;
        case 3: insert_end();    break;
        case 4: delete_begin();  break;
        case 5: delete_end();    break;
        case 6: display();       break;
        case 7: t = 0;           break;
        default: printf("\nEnter valid input");
        }
    }
    return 0;
}

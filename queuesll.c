#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};

struct node *start , *rear,*new1;
 

void enqueue()
{
    int n;
    printf("\nEnter element to enqueue: ");
    scanf("%d", &n);

    new1 = (struct node *)malloc(sizeof(struct node));
        new1->data = n;
    new1->add = NULL;

    if (start == NULL)  // first element
    {
        start = rear = new1;
    }
    else
    {
        rear->add = new1;  // your last_insert logic
        rear = new1;
    }
    printf("Enqueued %d\n", n);
}

void dequeue()
{
    if (start == NULL)
    {
        printf("Queue underflow (queue is empty)\n");
        return;
    }

    struct node *temp = start;
    int n = temp->data;
    start = start->add;  // your first_delete logic
    if (start == NULL) rear = NULL;
    free(temp);
    printf("Dequeued element = %d\n", n);
}

void display()
{
    if (start == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = start;
    printf("Queue (front to rear): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->add;
    }
    printf("\n");
}

int main()
{
    int op, t = 1;

    while (t == 1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1: enqueue(); break;
        case 2: dequeue(); break;
        case 3: display(); break;
        case 4: t = 0; break;
        default: printf("Enter valid input\n");
        }
    }
    return 0;
}

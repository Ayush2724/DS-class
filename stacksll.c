#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};

struct node *start,*temp ;   // start of stack

void push()
{
    int n;
    struct node *top;
    printf("\nEnter element to push: ");
    scanf("%d", &n);

    top = (struct node *)malloc(sizeof(struct node));
    top->data = n;
    top->add = start;   // link new node to current start
 start = top;        // update start
    printf("Pushed %d onto stack\n", n);
}

void pop()
{
    if (start == NULL)
    {
        printf("Stack underflow (stack is empty)\n");
        return;
    }

    temp = start;
    int n = temp->data;
    start = start->add;  // move start down
    free(temp);
    printf("Popped element = %d\n", n);
}

void peek()
{
    if (start == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("start element = %d\n", start->data);
}

void display()
{
    if (start == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    struct node *temp = start;
    printf("Stack (start to bottom): ");
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
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Quit\n");
        printf("Enter tempur choice: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            t = 0;
            break;
        default:
            printf("Enter valid input\n");
        }
    }

    return 0;
}

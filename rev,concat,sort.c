#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *add;
};

struct node *head1 = NULL, *head2 = NULL;
struct node *temp, *new1;

/* create a list (insert at end), return head */
struct node* create(struct node *start)
{
    int x;
    char ch;

    printf("Enter first element: ");
    scanf("%d", &x);

    start = (struct node*)malloc(sizeof(struct node));
    start->data = x;
    start->add  = NULL;
    temp = start;

    printf("Do you want to continue adding elements (y/n)? ");
    scanf(" %c", &ch);

    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter element: ");
        scanf("%d", &x);

        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = x;
        new1->add  = NULL;

        temp->add = new1;
        temp = temp->add;

        printf("Do you want to continue adding elements (y/n)? ");
        scanf(" %c", &ch);
    }

    return start;
}

/* display any list */
void display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->add;
    }
    printf("\n");
}

/* reverse list using global head1 */
void reverse1()
{
    struct node *prev = NULL, *current = head1, *next;

    if (head1 == NULL)
    {
        printf("First list empty\n");
        return;
    }

    while (current != NULL)
    {
        next = current->add;
        current->add = prev;
        prev = current;
        current = next;
    }
    head1 = prev;

    printf("Reversed first list: ");
    display(head1);
}

/* sort list using ONLY while loops (NO swapped flag) */
void sort1()
{
    struct node *p1, *p2, *last = NULL;
    int tempData;

    if (head1 == NULL)
    {
        printf("First list empty\n");
        return;
    }

    // Outer loop using while
    p1 = head1;
    while (p1 != NULL)
    {
        p2 = head1;
        while (p2->add != last)
        {
            if (p2->data > p2->add->data)
            {
                tempData       = p2->data;
                p2->data       = p2->add->data;
                p2->add->data  = tempData;
            }
            p2 = p2->add;
        }
        last = p2;
        
        // Reset p1 for next pass
        p1 = head1;
    }

    printf("Sorted first list: ");
    display(head1);
}

/* concatenate head2 at end of head1 */
void concatenate12()
{
    if (head1 == NULL && head2 == NULL)
    {
        printf("Both lists empty\n");
        return;
    }
    if (head1 == NULL)
    {
        head1 = head2;
        head2 = NULL;
        printf("Result (first list): ");
        display(head1);
        return;
    }
    if (head2 == NULL)
    {
        printf("Second list empty\n");
        return;
    }

    temp = head1;
    while (temp->add != NULL)
        temp = temp->add;

    temp->add = head2;
    head2 = NULL;
    printf("Concatenated list: ");
    display(head1);
}

int main()
{
    int op, t = 1;

    while (t)
    {
        printf("\n1. Create first list");
        printf("\n2. Create second list");
        printf("\n3. Display first list");
        printf("\n4. Display second list");
        printf("\n5. Sort first list");
        printf("\n6. Reverse first list");
        printf("\n7. Concatenate (head1 + head2 → head1)");
        printf("\n8. Exit\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1: head1 = create(head1); break;
        case 2: head2 = create(head2); break;
        case 3: printf("List 1: "); display(head1); break;
        case 4: printf("List 2: "); display(head2); break;
        case 5: sort1(); break;
        case 6: reverse1(); break;
        case 7: concatenate12(); break;
        case 8: t = 0; break;
        default: printf("Invalid choice\n");
        }
    }
    return 0;
}

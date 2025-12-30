#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL, *new1;

/* create / insert ONE element into BST */
struct node* insert_bst(struct node *r, int x)
{
    if (r == NULL)
    {
        new1 = (struct node*)malloc(sizeof(struct node));
        new1->data = x;
        new1->left = new1->right = NULL;
        r = new1;
    }
    else if (x < r->data)
        r->left  = insert_bst(r->left, x);
    else if (x > r->data)
        r->right = insert_bst(r->right, x);
    else
        printf("\nDuplicate key %d not inserted", x);

    return r;
}

/* (a) construct BST with N elements */
void create_bst()
{
    int n, x;
    printf("\nHow many elements? ");
    scanf("%d", &n);

    root = NULL;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x);
        root = insert_bst(root, x);
    }
}

/* (b) traversals */

/* inorder: left, root, right */
void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

/* preorder: root, left, right */
void preorder(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

/* postorder: left, right, root */
void postorder(struct node *r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}


int main()
{
    int op, x, t = 1;

    while (1)
    {
        printf("\n1. Create BST");
        printf("\n2. Insert one element");
        printf("\n3. Display all traversals");
        printf("\n4. Exit\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            create_bst();
            break;

        case 2:
            printf("Enter element to insert: ");
            scanf("%d", &x);
            root = insert_bst(root, x);
            break;

        case 3:
            printf("Inorder   : ");
            inorder(root);
            printf("\n");
             printf("Preorder  : ");
            preorder(root);
            printf("\n");
            printf("Postorder : ");
            postorder(root);
            printf("\n");
            break;

        case 4:exit(0);
             break;
            

        default:
            printf("Enter valid input\n");
        }
    }
    return 0;
}

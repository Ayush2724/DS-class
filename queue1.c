#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

struct queue *q;

int isEmpty() {
    return (q->f == q->r);
}

int isFull() {
    return (q->r == q->size - 1);
}

void enqueue(int val) {
    if(isFull()) {
        printf("Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        printf("Enqueued: %d\n", val);
    }
}

void dequeue() {
    if(isEmpty()) {
        printf("Queue is empty\n");
    } else {
        q->f++;
        printf("Dequeued: %d\n", q->arr[q->f]);
    }
}

void display() {
    if(isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for(int i = q->f + 1; i <= q->r; i++) {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch, x, n;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    q = (struct queue*)malloc(sizeof(struct queue));
    q->size = n;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    while(1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                enqueue(x);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                free(q->arr);
                free(q);
                printf("Queue destroyed\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

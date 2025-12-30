#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

struct queue *q;

int isEmpty() {
    return (q->f == q->r);
}

int isFull() {
    return (q->r == q->size - 1);
}

void enqueue(int val) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue() {
    int a = -1;
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main() {
    q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 50;
    q->f = q->r = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));

    int visited[7] = {0,0,0,0,0,0,0};
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };

    int i = 0;
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty()) {
        int node = dequeue();
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    return 0;
}

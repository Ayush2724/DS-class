#include<stdio.h>
#include<stdlib.h>

struct circularQueue {
    int size;
    int f;
    int r;
    int* arr;
};


struct circularQueue *q;

int isEmpty(){
    return (q->r == q->f);
}

int isFull(){
    return ((q->r + 1) % q->size == q->f);
}

void enqueue(int val){
    if(isFull()){
        printf("This Queue is full\n");
    }
    else{
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val; 
        printf("Enqueued element: %d\n", val);
    }
}

void dequeue(){
    int a = -1;
    if(isEmpty()){
        printf("This Queue is empty\n");
        return;
    }
    q->f = (q->f + 1) % q->size;
    a = q->arr[q->f]; 
    printf("Dequeued element: %d\n", a);
}

void display(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = (q->f + 1) % q->size;
    while(i != (q->r + 1) % q->size){
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("\n");
}

int main(){
    
    q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
    
    q->f = q->r = 0;  
    int n, ch, x;
    
    printf("Enter the size of queue: ");
    scanf("%d", &n);
    q->size = n;
    q->arr = (int*)malloc(q->size * sizeof(int));
    
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter value: ");
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
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}

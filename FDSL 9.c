#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} CircularQueue;

void initialize(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(CircularQueue *q) {
    return (q->front == (q->rear + 1) % MAX);
}

int isEmpty(CircularQueue *q) {
    return (q->front == -1);
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
    printf("Enqueued %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue\n");
        return -1;
    }
    int removed = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    printf("Dequeued %d\n", removed);
    return removed;
}

void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int peek(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to peek.\n");
        return -1;
    }
    return q->items[q->front];
}

int main() {
    CircularQueue cq;
    initialize(&cq);

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);

    display(&cq);

    dequeue(&cq);
    dequeue(&cq);

    enqueue(&cq, 60);
    enqueue(&cq, 70);

    display(&cq);

    printf("Front element is: %d\n", peek(&cq));

    return 0;
}

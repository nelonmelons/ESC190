#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    char *string;
    int front;
    int rear;
    int sz;
}queue;

void enqueue(queue *q, int val){
    if (q->rear == q->sz - 1){
        q->rear = 0;
    }
    else{
        q->rear++;
    }
    q->string[q->rear] = val;
}

char dequeue(queue *q){
    int val;
    if (q->front == q->sz - 1){
        val = q->front;
        q->front = 0;
    }
    else{
        val = q->front;
        q->front++;
    }
    return q->string[val];
}
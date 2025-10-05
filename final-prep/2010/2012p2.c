#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    Node *next;
}Node;

typedef struct Queue{
    Node *front;
    Node *end;
}Queue;

struct Queue * initQueue(){
    Queue *q = malloc(sizeof(Queue));
    return q;
}

int dequeue(struct Queue *q){
    Node *temp = q->front->next;
    int val = q->front->val;
    free(q->front);
    q->front = temp;
    return val;
}

void enqueue(struct Queue * q, int data){
    Node *n = malloc(sizeof(Node));
    n->val = data;
    n->next = NULL;
    q->end->next = n;
    q->end = n;
}


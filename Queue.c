#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue{
    int start;
    int end;
    int queueSize;
    int capacity;
    int* arr;
} queue;

struct Queue* creatQueue(int size){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = size;
    q->start = 0;
    q->queueSize = 0; // start size
    q->end = q->capacity-1;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

//function to check if the queue is empty
int isEmpty(struct Queue* q){
    return (q->queueSize) == 0;
}

//function to check if the queue is full
int isFull(struct Queue* q){
    return(q->queueSize == q->capacity);
}

//function to get the first place in the queue
int start(struct Queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    else{
        return q->arr[q->start];
    }
}

//function to get the last place in the queue
int end(struct Queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    else{
        return q->arr[q->end];
    }
}

//function to add a node id to the queue
void enqueue(struct Queue* q, int node_id){
    if(isFull(q)){
        return;
    }
    q->end = (q->end+1) % q->capacity; // in the function creatQueue we initialize the end to be the size of the capacity-1,
    // and we want to add the node's id in the current place, so we need to do modulo of the size so the end will start with 0
    // and will continue until the capacity instead of the end will start from the capacity-1
    q->arr[q->end] = node_id;
    q->queueSize=q->queueSize+1;
}

//function to add a node id to the queue
int dequeue(struct Queue* q){
    if(isFull(q)){
        return INT_MIN;
    }
    int firstNode = q->arr[q->start];
    q->start = (q->start+1) % q->capacity; // in the function creatQueue we initialize the end to be the size of the capacity-1,
    // and we want to add the node's id in the current place, so we need to do modulo of the size so the end will start with 0
    // and will continue until the capacity instead of the end will start from the capacity-1
    q->queueSize--;
    return firstNode;
}

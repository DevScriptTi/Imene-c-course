#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node * next ;
}Node ; 

typedef struct  Queue{
   Node * front , * rear ;
}Queue ;

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data ;
    newNode->next = NULL ;
    return newNode ;
}

void initQueue(Queue * q){
    q->front = q->rear = NULL ;
}

int isEmptyQueue(Queue * q){
    return q->front == NULL;
}

void enqueue(Queue * q , int data){
    Node * newNode = createNode(data);
    if(isEmptyQueue(q)){
        q->front = q->rear = newNode ;
    }else{
        q->rear->next = newNode ;
        q->rear = newNode;
    }
}

void dequeue(Queue * q){
    if(isEmptyQueue(q)){
        printf("Queue is empty!!\n");
        return ;
    }
    Node *temp = q->front ;
    q->front = q->front->next ;
    if(q->front == NULL){
        q->rear = NULL ;
    }
    free(temp);
}

int peekQueue(Queue * q){
    if(isEmptyQueue(q)){
        printf("Queue is empty!!\n");
        return -1 ;
    }
    return q->front->data ;
}

void displayQueue(Queue * q){
    if(isEmptyQueue(q)){
        printf("Queue is empty!!\n");
        return  ;
    }
    Node *temp = q->front ;
    while(temp != NULL){
        printf("%d => ",temp->data);
        temp = temp->next ;
    }
    printf(" NULL\n");
    
}

int main(){
    Queue q ;
    initQueue(&q);
    enqueue(&q , 12);
    enqueue(&q , 120);
    enqueue(&q , -4);
    enqueue(&q , 18);
    displayQueue(&q);
    dequeue(&q );
    dequeue(&q );
    displayQueue(&q);
    printf("peek of the queue is %d\n",peekQueue(&q));
    dequeue(&q );
    displayQueue(&q);
    dequeue(&q );
    displayQueue(&q);
    dequeue(&q );
    printf("peek of the queue is %d\n",peekQueue(&q));
    return  0 ;
    
    
    
}
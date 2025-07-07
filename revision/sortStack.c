#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node * next ;
}Node ; 

typedef struct  Stack{
    Node * top ;
    int counter ;
}Stack ;

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

int dequeue(Queue * q){
    if(isEmptyQueue(q)){
        printf("Queue is empty!!\n");
        return -1;
    }
    Node *temp = q->front ;
    q->front = q->front->next ;
    if(q->front == NULL){
        q->rear = NULL ;
    }
    int popped = temp->data;
    free(temp);
    return popped ;
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

void initStack(Stack * s){
    s->top = NULL;
}

void push(Stack * s , int data){
    Node * newNode = createNode(data);
    newNode->next = s->top ;
    s->top = newNode ;
    s->counter++ ;
}

int isEmptyStack(Stack * s){
    return s->top == NULL ;
}

int pop(Stack * s){
    if(isEmptyStack(s)){
        printf("The Stack is empty you cannot pop any element");
        return -1;
    }
    int popped ;
    Node * temp = s->top ;
    s->top = s->top->next ;
    s->counter--;
    popped = temp->data;
    free(temp);
    return popped;
    
}

int peekStack(Stack * s ){
    if(isEmptyStack(s)){
        printf("Stack is empty there is no peek !!\n");
        return -1 ;
    }
    return s->top->data ;
}

void displayStack(Stack * s){
    if(isEmptyStack(s)){
        printf("Stack is empty\n");
        return ;
    }
    Node * temp = s->top ;
    while(temp != NULL){
        printf("%d => ",temp->data);
        temp = temp->next ;
    }
    printf(" NULL\n");
}

void sortStack(Stack *s){
    Queue F1 , F2 ;
    initQueue(&F1);
    initQueue(&F2);
    
    while(!isEmptyStack(s)){
        int current =  pop(s);
        if(isEmptyQueue(&F1)){
            enqueue(&F1 , current);
        }else{
            while(!isEmptyQueue(&F1) && current > F1.front->data){
                enqueue(&F2 , dequeue(&F1));
            }
            enqueue(&F1 , current);
            while(!isEmptyQueue(&F2)){
                enqueue(&F1 , dequeue(&F2));
            }
        }
    }
    
    while(!isEmptyQueue(&F1)){
        push(s , dequeue(&F1));
    }
}
int main() {
    Stack s ;
    initStack(&s);
    
    push(&s , 5);
    push(&s , 2);
    push(&s , 7);
    push(&s , 1);
    push(&s , 4);
    
    printf("Original stack : ");
    displayStack(&s);
    
    sortStack(&s);
    
    printf("sorted stack : ");
    displayStack(&s);
    return 0;
    
    
    
    
    
    
    
    
    
}
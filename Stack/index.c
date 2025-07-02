// Online C compiler to run C program online
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

Node * createNode(int data){
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data ;
    newNode->next = NULL ;
    return newNode ;
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

void pop(Stack * s){
    if(isEmptyStack(s)){
        printf("The Stack is empty you cannot pop any element");
        return ;
    }
    Node * temp = s->top ;
    s->top = s->top->next ;
    s->counter--;
    free(temp);
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

int main() {
    Stack s ;
    initStack(&s);
    push(&s , 4);
    push(&s , 21);
    push(&s , 11);
    push(&s , 16);
    displayStack(&s);
    pop(&s);
    displayStack(&s);
    printf("peek of the stack is %d",peekStack(&s));
    return 0;
    
} 
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data ;
    struct Node * next ;
}Node ;

Node * createNode(int data){
    Node * newNode =(Node * ) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("StackOverflow");
        return NULL;
    }
    newNode->data = data ;
    newNode->next = NULL ;
    return newNode ;
    
} 

void addNode(Node * head , int data){
    Node * newNode = createNode(data) ;
    if(head == NULL){
        head = newNode ;
    }
    while(head->next != NULL){
        head = head->next ;
    }
    head->next = newNode ;
}

int main() {
    Node * head = NULL ;  
    addNode(head , 12);
    return 0;
    
    
    
    
    
    
    
    
    
}
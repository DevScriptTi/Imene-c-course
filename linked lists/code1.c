// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data ;
    struct Node * next ;
}Node ;

Node * createNode(int data){
    Node * newNode = (Node * )malloc(sizeof(Node));
    if(newNode == NULL){
        printf("StackOverflow");
        return NULL ;
    }
    newNode->data = data ;
    newNode->next = NULL ;
    return newNode ;
} 

void printList(Node * head){
    printf("\nPrinting Element's List .... \n");
    if(head == NULL){
        printf("Empty list ");
        return ;
    }
    while(head != NULL){
        printf("%d -> " , head->data);
        head = head->next ;
    }
    printf("NULL");
}

void push(Node ** head , int data){
    Node * newNode = createNode(data);

    if(*head == NULL){
        (*head) = newNode ;
        return ;
    }
     
    Node * temp = *head;
    while(temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newNode ;
    
   
}

void insertAtPosition(Node ** head , int data , int position){
    Node * newNode = createNode(data);
    if(position == 0){
        newNode->next = *head ;
        *head = newNode ;
        return ;
    }
    
    Node *temp = *head ;
    int i = 1 ;
    while(i < (position - 1) && temp != NULL){
        temp = temp->next ;
        i++ ;
    }
    
    if(temp == NULL){
        printf("\nPosition %d is out of range , Insertion failed .\n" , position);
        free(newNode);
        return ;
    }
    
    newNode->next = temp->next ;
    temp->next  = newNode ;
}

int countList(Node * head ){
    int counter = 0 ;
    if(head == NULL){
        return counter ;
    }
    
    while(head != NULL){
        head = head->next ;
        counter++;
    }
    
    return counter ;
    
}

int main() {
    Node * head = NULL ;
    push(&head , 12);
    push(&head , 112);
    push(&head , -3);
    printList(head);
    insertAtPosition(&head , 4 , 3 );
    printList(head);
    insertAtPosition(&head , 33 , 0 );
    printList(head);
    insertAtPosition(&head , 33 , 10 );
    printList(head);
    
    printf("\nThe number of the elements in the list = %d" , countList(head));
    return 0;
}
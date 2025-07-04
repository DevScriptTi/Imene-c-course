#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Define the structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


bool hasCycle(Node * head){
  if(head == NULL || head->next == NULL){
    return false;
  }  
  Node * slow = head ;
  Node * fast = head->next ;
  while(slow != fast){
      if(fast  == NULL || fast->next == NULL){
          return false ;
      }
      slow = slow->next ;
      fast = fast->next->next ;
  }
  return true ;
}
int main() {
    // Create nodes
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);

    // Link nodes: head -> second -> third -> fourth
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle: fourth -> second
    fourth->next = second;
    
    if(hasCycle(head)){
        printf("There is a cycle ");
    }else{
        printf("There is no a cycle ");
    }
    
    
    return 0;
}
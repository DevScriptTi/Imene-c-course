// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack{
    Node * top ;
}Stack ;

void initStack(Stack * s){
    s->top = NULL;
};

void push(Stack * s , char c){
    Node * newNode = (Node * )malloc(sizeof(Node));
    newNode->data = c ;
    newNode->next = s->top ;
    s->top = newNode ;
}

char pop(Stack * s ){
    if (s->top == NULL) return '\0';
    Node* temp = s->top;
    char popped = temp->data;
    s->top = s->top->next;
    free(temp);
    return popped;
}

bool isBlanced(char * exp){
    Stack s ; 
    initStack(&s);
    
    for(int i = 0 ; exp[i] !='\0' ; i++){
        if(exp[i] == '('|| exp[i] == '['|| exp[i] == '{') {
            push(&s , exp[i]);
        }else if(exp[i] == ')'|| exp[i] == ']'|| exp[i] == '}'){
            if(s.top == NULL) return false ;
            char popped = pop(&s); //
            if(
                (exp[i] == ')' && popped != '(') ||
                (exp[i] == ']' && popped != '[') ||
                (exp[i] == '}' && popped != '{') 
            ){
                return false;
            }
        }
    }
    return s.top == NULL ;
}

int main() {
    // ((does the hore have ), my name is ( ali mansour ) ((.... (())
    char exp[100] ;
    printf("Enter expression : ");
    scanf("%s",exp);
    printf(isBlanced(exp) ? "Balanced\n" :"Not Balanced\n" );
    

    return 0;
}
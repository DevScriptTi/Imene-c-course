// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef struct Number{
    int val ;
    struct Number * next  ;
}Number ;



Number * createNumber(int digits[] , int size){
    Number * dummy = (Number *) malloc(sizeof(Number));
    Number * current = dummy ;
    for(int i = size-1 ; i>=0 ; i--){
        current->next = (Number * ) malloc(sizeof(Number));
        current->next->val = digits[i];
        current->next->next = NULL;
        current = current->next ;
    }
    Number * head = dummy->next ;
    free(dummy);
    return head;
}

Number * addTwoNumbers(Number * n1 , Number * n2){
    Number * dummy = (Number *) malloc(sizeof(Number));
    dummy->val = 0 ;
    dummy->next = NULL ;
    Number * current = dummy ;
    int carry = 0 ;
    while(n1 != NULL || n2 != NULL || carry != 0 ){
       int val1= (n1!=NULL) ? n1->val : 0 ;
       int val2= (n2!=NULL) ? n2->val : 0 ;
       int total = val1 + val2 + carry ;
       carry = total/10 ;
       int digit = total % 10 ;
       current->next = (Number *) malloc(sizeof(Number));
       current->next->val = digit ;
       current->next->next = NULL ;
       current = current->next ;
       if(n1!= NULL) n1 = n1->next ;
       if(n2!= NULL) n2 = n2->next ;
    }
    Number * head = dummy->next ;
    free(dummy);
    return head ;
}

void printNumber(Number * head){
    while(head != NULL){
        printf("%d", head->val);
        head = head->next ;
    }
    printf("\n");
} 

int main() {
    int number1[3] = {2,1,5};// 5->1->2
    int number2[3] = {5,4,5};// 5->4->5
    Number * n1 = createNumber(number1,3);
    Number * n2 = createNumber(number2,3);
    
    Number * result = addTwoNumbers(n1,n2);
    printNumber(result);
    

    return 0;
}
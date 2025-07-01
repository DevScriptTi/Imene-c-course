// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef struct Monomial{
    float coeff ;
    int exponent ;
    struct Monomial * next ;
}Monomial ;

Monomial * createMonomial(float coeff , int exponent){
    if(coeff == 0) return NULL; 
    Monomial * newNode = (Monomial * ) malloc(sizeof(Monomial)); 
    newNode->coeff = coeff;
    newNode->exponent = exponent;
    newNode->next = NULL;
    
    return newNode ;
}

void insetMonomial(Monomial ** poly , float coeff , int  exponent){
    if(coeff == 0 ) return ;
    Monomial * newNode = createMonomial(coeff , exponent);
    if(*poly == NULL || (*poly)->exponent > exponent){
        newNode->next = *poly ;
        *poly = newNode ;
        return ;
    }
    
    Monomial * temp = *poly ;
    while(temp->next != NULL && temp->next->exponent < exponent){
        temp = temp->next ;
    }
    
    if(temp->next != NULL && temp->next->exponent == exponent){
        temp->next->coeff = coeff ;
        free(newNode);
    }else{
        newNode->next = temp->next ;
        temp->next = newNode ;
    }
}

void printPoly(Monomial *poly){
    if(poly == NULL) {
        printf("This is an empty poly \n");
        return ;
    }
    while(poly != NULL){
        printf("%.2fX^%d => ",poly->coeff , poly->exponent);
        poly = poly->next ;
        
    }
    printf("NULL\n");
    
}

float evalutePoly(Monomial * poly , float x){
    float result = 0.0 ;
    while(poly != NULL){
        float pw = 1 ;
        for(int i = 1 ; i<= poly->exponent ; i++){
            pw *= x ;
        }
         result += pw*(poly->coeff) ;
         poly = poly->next ;
    }
    return result ;
}

int main() {
    Monomial * poly = NULL ;
    insetMonomial(&poly , 2 , 1);
    insetMonomial(&poly , 4 , 2);
    printPoly(poly);
    printf("%f",evalutePoly(poly,2.0) );
   
    return 0;
}
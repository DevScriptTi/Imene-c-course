#include <stdio.h>

/*

variable = space in the memory 
predefine types = integer flaots boolean chars strings .... 
userdefine types = point (x , y)
*/

struct Point {
    float x ; // members 
    float y ; 
}

typedef struct Employee{
    char name[] ;
    char last[] ;
    float salary ;
    char grade ;
}Emp;

int main() {
    int x , y , z , age  ;
    struct Point p1 , p2 , p3 ;
    x = 4 ;
    x = 12 ;
    x = - 3 ;
    p1.x = 3.23;
    p1.y = 1.12;
    
    Emp e1 ; 
    e1.name = "Ali";
    e1.last = "Ali";
    e1.salary = 12000.00;
    e1.grade = 'A';
    
    Emp e[5] ;
    for(int i = 0 ; i< 5 ; i++){
        printf("Enter the name : ");
        scanf("%s",&e1.name);
        printf("Enter the last : ");
        scanf("%s",&e1.last);
        printf("Enter the salary : ");
        scanf("%f",&e1.salary);
        printf("Enter the grade : ");
        scanf("%c",&e1.grade);
    }
    for(int i = 0 ; i< 5 ; i++){
        printf("Enter the name : ");
       
        printf("Enter the last : ");
       
        printf("Enter the salary : ");
    
        printf("Enter the grade : ");
        
    }
    
    
    

    return 0;
}
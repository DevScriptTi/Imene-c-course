// Online C compiler to run C program online
#include <stdio.h>

void swap(int * x , int * y){
    int temp ;
    temp = *x ;
    *x = *y ;
    *y = temp ;
}

int main() {
    int a = 5 , b = 10 ;
    swap(&a , &b);
    printf("a = %d \nb = %d",a,b);

    return 0;
}
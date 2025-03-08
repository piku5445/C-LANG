#include<stdio.h>

int main(){
    int a=52;
    int b=18;
    int *ptr1=&a;
    int *ptr2=&b;
    if(*ptr1>*ptr2){
        printf("%d\n is greater",*ptr1);
    }
    else{
 printf("%d\n is greater",*ptr1);
    }
       

    

    return 0;
}
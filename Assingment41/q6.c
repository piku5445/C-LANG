#include<stdio.h>

int main(){
   
    // int a = 12, b = 52, c =18;
    // int *ptr1 = &a, *ptr2 = &b, *ptr3 = &c;

    // *ptr1 += 10;
    // *ptr2 += 10;
    // *ptr3 += 10;

    // printf("Updated values: a = %d, b = %d, c = %d\n", a, b, c);
int a=12;
int b=52;
int c=8;
int *ptr1=&a;
int *ptr2=&b;
int *ptr3=&c;
printf("%d\n",*ptr1+10);
printf("%d\n",*ptr2+10);
printf("%d\n",*ptr3+10);




    return 0;
}
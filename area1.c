#include<stdio.h>

int main(){
    // int length=6;
    // int breadth=4;
    int length;
    int breadth;
    printf("Enter the length");

    scanf("%d",&length);
    printf("enter the breadth of the rectangle");
    scanf("%d",&breadth);
    int area=length*breadth;
    printf("the area of the rectangle is %d",area);

    return 0;
}
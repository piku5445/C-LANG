#include<stdio.h>

int main(){
    int age;
    printf("enter your age");
    scanf("%d",age);
    if(age<45){
        printf("you can apply for job");
    }
    else{
        printf("you cant apply for job");
    }

    return 0;
}
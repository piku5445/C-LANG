#include<stdio.h>

int main(){
    int a=55;
    int b=105;
    int c=89;
    int d=68;
    int *p=&a;
    int *p1=&b;
    int *p2=&c;
    int *p3=&d;
    // int ar[4]={*p,*p1,*p2,*p3};
    // int max=0;
    // for(int i=0;i<4;i++){
    //     if(ar[i]>max){
    //         max=ar[i];

    //     }

    // }
    // printf("max=%d",max);
    int max=*p;
    if(*p1>max) max=*p1;
    if(*p2>max)max=*p2;
    if(*p3>max)max=*p3;
    printf("max=%d",max);

    return 0;
}
#include<stdio.h>
void sumarr(int a[],int b[],int r[],int size){
    for(int i=0;i<size;i++){
       r[i]=a[i]+b[i]; 
    }
}
int main(){
    int a[5]={1,2,3,4,5};
    int b[5]={6,7,8,9,10};
    int r[5];
    sumarr(a,b,r,5);
    for(int i=0;i<5;i++){
        printf("%d\n",r[i]);

    }
    return 0;
}
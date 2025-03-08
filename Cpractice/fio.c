#include<stdio.h>
int fibo(int n){
    if(n==1){
        return 0;

    }
    else if(n==2){
        return 1;
    }
    else
        return fibo(n-1)+fibo(n-2);
    
    
    }
    
int main(){

    printf("%d",fibo(5));

    for(int i=1;i<=5;i++){

        printf("%d",fibo(i));
    }
    printf("/n");
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/wait.h>


  void fibonacci(int n){
       int a=0;int b=1;
       int temp;
       for(int i=0;i<n;i++){
           
           if(i==0){
            printf("%d ",a);
           }
           if(i==1){
            printf("%d ",b);
           }
           temp=a+b;
            printf("%d ",temp);


           a=b;
           b=temp;
          

    }}

int main(int argc ,char *argv[]){
    int n=atoi(argv[1]);
 if(fork()==0){
    printf("the child process");
    fibonacci(n);
    exit(0);
 
 } 
 else{
    wait(NULL);
    printf("the parent process%d",getpid());
 }




return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
       if(fork()>0){
              sleep(1);

       }
       else{
              printf("%d  %d",getpid(),getppid());
              printf("copying the file content from f1.txt to f2.txt    \n");
              execlp("cp","cp","-f","f1.txt","f2.txt",NULL);
              perror("execlp failed");
       }
       if(fork()>0){
              sleep(1);
       }
       else{
              printf("%d  %d",getpid(),getppid());
              execlp("cat","cat","f2.txt",NULL);
              perror("execlp failed");
              return 1;
       }
       if(fork()>0){
              sleep(1);
       }
       else{
              printf("%d  %d",getpid(),getppid());
              printf("content of f2.txt in  reversed order\n");
              execlp("sort","sort","-r","f2.txt",NULL);

       }
       wait(NULL);
       wait(NULL);
       wait(NULL);
       printf("i am parent process with ID =%d\n",getpid());



    
       return 0;
}
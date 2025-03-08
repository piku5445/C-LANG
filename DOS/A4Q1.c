#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    pid_t pid=fork();
    if(pid==0){
        printf("the child process is exceuting %d %d",getpid(),getppid());
        while(1){
            sleep(1);
        }
    }
    else if(pid<0){
       perror("Fork Failed");
       exit(EXIT_FAILURE);

    }
    else{
     printf("parent PID=%d ,child PID=%d",getpid(),pid);
     while(1){
        sleep(1);
     }

    }
    
    return 0;
}
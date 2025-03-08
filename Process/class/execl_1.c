#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>

int main(){
    printf("Main: PID : %d PPID %d\n",getpid(),getppid());
    pid_t chpid = fork();
    if(chpid){
        printf("Parent: PID : %d PPID %d\n",getpid(),getppid());
        printf("Parent: waiting for child\n");
        wait(NULL);
        printf("Parent: terminating\n");
    }else{
        printf("Child: PID : %d PPID %d\n",getpid(),getppid());
        sleep(5);
        int p = execle("/usr/bin/cat","cat","File1.c",NULL,NULL);
        printf("Hey Child Again\n");
        if (p==-1)
            perror("Error");
    }

}
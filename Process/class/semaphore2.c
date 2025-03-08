//Using Unnamed Semaphore

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>

#define S_NAME "/s_file"
#define T_NAME "/t_file"
void processP(){
    sem_t *S = sem_open(S_NAME,0);
    sem_t *T = sem_open(T_NAME,0);

    printf("Parent: pid=%d\n",getpid());
    while(1){
        fprintf(stdout,"Child waiting for S\n");
        sem_wait(S);
        fprintf(stdout,"0");
        sleep(1);
        fprintf(stdout,"0");
        sem_post(T);
    }
    sem_close(S);
    sem_close(T);
}

void processQ(){
    sem_t *S = sem_open(S_NAME,0);
    sem_t *T = sem_open(T_NAME,0);
    
    printf("Child: pid=%d\n",getpid());
    while(1){
        fprintf(stdout,"Parent waiting for T\n");
        sem_wait(T);
        fprintf(stdout,"1");
        sleep(1);
        fprintf(stdout,"1");
        sem_post(S);
    }
    sem_close(S);
    sem_close(T);
}
int main(){
    sem_t *S, *T;
    S = sem_open(S_NAME,O_CREAT|O_EXCL,0664,1);
    T = sem_open(T_NAME,O_CREAT|O_EXCL,0664,0);

    if(S == SEM_FAILED || T == SEM_FAILED){
        perror("Error openinf Semaphore: ");
        exit(0);
    }

    pid_t chpid = fork();
    if(chpid){
        //Parent block
        processP();
        wait(NULL);
    }else{
        //Child block
        processQ();
    }
    sem_unlink(S_NAME);
    sem_unlink(T_NAME);
    return 0;
}
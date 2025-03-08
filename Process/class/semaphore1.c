//Using Unnamed Semaphore

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>


void processP(sem_t *S, sem_t *T){
    printf("Parent: pid=%d\n",getpid());
    while(1){
        fprintf(stdout,"Child waiting for S\n");
        sem_wait(S);
        fprintf(stdout,"0");
        sleep(1);
        fprintf(stdout,"0");
        int pp;
        sem_getvalue(T,&pp);
        fprintf(stdout,"before post: T =%d",pp);
        sem_post(T);
        sem_getvalue(T,&pp);
        fprintf(stdout,"after post: T =%d",pp);
    }
}

void processQ(sem_t *S, sem_t *T){
    printf("Child: pid=%d\n",getpid());
    while(1){
        fprintf(stdout,"Parent waiting for T\n");
        sem_wait(T);
        fprintf(stdout,"1");
        sleep(1);
        fprintf(stdout,"1");
        sem_post(S);
    }
}
int main(){
    sem_t S, T;
    sem_init(&S,0,1);
    sem_init(&T,0,0);

    pid_t chpid = fork();
    if(chpid){
        //Parent block
        processP(&S,&T);
        wait(NULL);
    }else{
        //Child block
        processQ(&S,&T);
    }
    sem_destroy(&S);
    sem_destroy(&T);
    return 0;
}
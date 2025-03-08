#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define MAX_NUM  20


sem_t sem_A,sem_B;
void *print_A(void *args){
    for(int i=0;i<MAX_NUM;i++){
        sem_wait(&sem_A);
        printf("A");
        fflush(stdout);
        sem_post(&sem_B);
    }
    return NULL;
}

void *print_B(void *args){
    for(int i=0;i<MAX_NUM;i++){
        sem_wait(&sem_B);
        printf("B");
        sem_post(&sem_A);
}
return NULL;
}
int main(){
    pthread_t t1,t2;
    sem_init(&sem_A,0,1);
    sem_init(&sem_B,0,0);
    pthread_create(&t2,NULL,print_A,NULL);
    pthread_create(&t2,NULL,print_B,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
    return 0;
}
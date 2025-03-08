#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#define MAX_COUNT 10
sem_t sem_A,sem_B;
void *countdown(void *args){
    for(int i=MAX_COUNT;i>=1;i--){
        sem_wait(&sem_A);
        printf("Thread A (countup):%d\n",i);
        sem_post(&sem_B);

    }
    return NULL;
}
void *countup(void *args){
    for(int i=1;i<=MAX_COUNT;i++){
        sem_wait(&sem_B);
        printf("Thread B (countdown):%d\n",i);
        sem_post(&sem_A);
    }
    return NULL;
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem_A,0,1);
    sem_init(&sem_B,0,0);
    pthread_create(&t1,NULL,countdown,NULL);
    pthread_create(&t2,NULL,countup,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&sem_A);
    sem_destroy(&sem_B);
  return 0;
}
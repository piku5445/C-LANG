#include<stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define MAX_NUM  20
sem_t sem_odd,sem_even;
void *odd(void *args){
    for(int i=1;i<=MAX_NUM;i+=2){
        sem_wait(&sem_odd);
        printf("Thread A(odd):%d\n",i);
        sem_post(&sem_even);
        
    }
    return NULL;
}
void *even(void *args){
    for(int i=2;i<=MAX_NUM;i+=2){
        sem_wait(&sem_even);
        printf("Thread B (even):%d\n",i);
        sem_post(&sem_odd);

    }
    return NULL;
}
int main(){
    pthread_t t1,t2;
    //initalization semaphore
    sem_init(&sem_odd,0,1);
    sem_init(&sem_even,0,0);
    //create threads
    pthread_create(&t1,NULL,odd,NULL);
    pthread_create(&t2,NULL,even,NULL);
    //join threads
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);

    return 0;
}
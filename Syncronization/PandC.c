#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
# define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int in=0;
int out=0;
sem_t mutex;
sem_t empty;
sem_t full;
void *producer(void *args){
    int item;
    while(1){
        item=rand()%100;
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in]=item;
        printf("Producer produce the item :%d\n",item);
        in=(in+1)%BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}
void *consumer(void *args){
    int item;
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
       item= buffer[out];
       printf("consumer consumed the item :%d\n",item);
       out=(out+1)%BUFFER_SIZE;
       sem_post(&mutex);
       sem_post(&empty);
       sleep(1);
    }
    return NULL;
}
int main(){
   pthread_t prod_thread ,cons_thread; 
   sem_init(&mutex,0,1);
   sem_init(&empty,0,BUFFER_SIZE);
   sem_init(&full,0,0);
   pthread_create(&prod_thread,NULL,producer,NULL);
   pthread_create(&cons_thread,NULL,consumer,NULL);
   pthread_join(prod_thread,NULL);
   pthread_join(cons_thread,NULL);
   sem_destroy(&mutex);
   sem_destroy(&empty);
   sem_destroy(&full);
    return 0;
}
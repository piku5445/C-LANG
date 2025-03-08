#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX 20
sem_t semA,semB,semC;

void *threadA(void *args){
    for(int i=1;i<=MAX;i+=3){
    sem_wait(&semA);
    printf("THread A is executing %d\n",i);
    sem_post(&semB);
    }
}


void *threadB(void *args){
    for(int i=2;i<=MAX;i+=3){
        sem_wait(&semB);
        printf("Thread B is excuting %d\n",i);
        sem_post(&semC);
    }
}

void *threadC(void *args){
    for(int i=3;i<=MAX;i+=3){
        sem_wait(&semC);
        printf("THread C is executing %d\n",i);
        sem_post(&semA);
    }


}


int main(){
    sem_init(&semA,0,1);
    sem_init(&semB,0,0);
    sem_init(&semC,0,0);
    pthread_t t1,t2,t3;
    pthread_create(&t1,NULL,threadA,NULL);
    pthread_create(&t2,NULL,threadB,NULL);
    pthread_create(&t3,NULL,threadC,NULL);
    

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    
    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);
      

  return 0;    
}
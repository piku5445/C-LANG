#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<semaphore.h>
sem_t sema;
void *thread1(void *args){
    sleep(1);
    printf("process 1 is executing....");
    sem_post(&sema);
    return NULL;
}
void *thread2(void *args){
    sem_wait(&sema);
    printf("process 2 is executing....");
    return NULL;

}

int main(){
    sem_init(&sema,0,0);
    pthread_t t1,t2;


    pthread_create(&t1,NULL,thread1,NULL);
    pthread_create(&t2,NULL,thread2,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&sema);
}
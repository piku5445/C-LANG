#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void myturn(void *arg){
    int *iptr=(int *)malloc(sizeof(int));
    *iptr=5;
    for(int i=0;i<5;i++){
        sleep(1);
        printf("my turn\n",i,*iptr);
        (*iptr)++;


    }
    return iptr;
}

void yourturn(void *arg){
   for(int i=0;i<5;i++){
    sleep(1);
    printf("your turn\n");

   } 
}
int main(){
    pthread_t newthread;
    int *result;
    // int v=0;
    int v=5;

    pthread_create(&newthread,NULL,myturn,&v);
    yourturn(NULL);
    pthread_join(newthread,(void *)&result);
    printf("thread's done: v=%d\n",v); 
    return 0;
}
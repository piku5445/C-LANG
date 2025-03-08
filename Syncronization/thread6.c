#include<stdio.h>
#include <stdlib.h>
#include<pthread.h>
void *myfun(void *args){
    int *argint=(int *)args;
    argint[1]=100;
    return(void *)(argint+1);
}

int main(){
    pthread_t tid;
    int *p;
    int a[2];
    if(pthread_create(&tid,NULL,myfun,(void *)!=0)){
        perror("pthread_create failed");
        exit(EXIT_FAILURE);
    }
    if(pthread_join(tid,(void **)&p)!=0){
        perror("pthread_join failed");
        exit(EXIT_FAILURE);

    }
    printf("Return value from thread =%d\n",*p);
    printf(value in array[1]=%d\n",a[1]);
    
    return 0;
}
#include <stdio.h>
#include<pthread.h>
void *print_number(void *args){
    int *num=(int *)args;
    printf("Thread received %d\n",*num);
    return NULL;
}
int main(){
    pthread_t thread;
    int value=42;
if (pthread_create(&thread,NULL,print_number,(void *)&value)!=0)
    {
        perror("pthread create failed");
        return 1;
    }
    pthread_join(thread,NULL);
    printf("Main thread completed\n");
    
}
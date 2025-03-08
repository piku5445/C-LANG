#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void myturn(void *arg){
    while(1){
        sleep(1);
        printf("my turn\n");

    }
    return NULL;
}

void yourturn(void *arg){
   while(1){
    sleep(1);
    printf("your turn\n");

   } 
}
int main(){
    pthread_t newthread;
    pthread_create(&newthread,NULL,myturn,NULL);
    yourturn(NULL);
    pthread_join(newthread,NULL);
    return 0;
}
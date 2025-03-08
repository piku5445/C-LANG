#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
   printf("p%d\n",getpid());
   if(fork()==0){
    printf("c1=%d p1=%d\n", getpid(), getppid());
    if(fork()==0){
        printf("c2=%d p2=%d\n",getpid() ,getppid());
        if(fork()==0){
            printf("c3=%d p3=5%d\n",getpid(),getppid());
            return 0;
        }
        if(fork()==0){
            printf("c4=%d p4=%d\n",getpid(),getppid());
            if(fork()==0){
                printf("c5=%d p5=%d\n",getpid(),getppid());
                return 0;
            }
            wait(NULL);
            return 0;
        }
        if(fork()==0){
        printf("c6=%d p6=%d\n",getpid(),getppid());
        return 0;
    }
    wait(NULL);
    wait(NULL);
    wait(NULL);
    return 0;
    }
    wait(NULL);
    return 0;
    

   }
   wait(NULL);
   return 0;
  

}

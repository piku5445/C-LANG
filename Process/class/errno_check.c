#include <stdio.h>
#include <errno.h>

int main(){
    int errno;
    for(int i = 0;i<200;i++){
        errno = i;
        fprintf(stdout,"i = %d\n",errno);
        perror("error");
    }
}
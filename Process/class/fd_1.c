#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

int main(){
    printf("Main: PID : %d PPID %d\n",getpid(),getppid());
    int n;
    int fd = open("./File1.c",O_RDONLY);
    int fd2 = open("./File2",O_WRONLY|O_CREAT,0664);

    if(fd == -1)
        perror("error");
    else
        fprintf(stdout,"File opened succesfuly\n");
    if(fd2 == -1)
        perror("error");
    else
        fprintf(stdout,"File opened succesfuly\n");
    int backup_stdout = dup(1);
    close(1);
    dup(fd2);

    char str[1000];
    read(fd,str,100);
    printf("Hello Content : %s\n",str);
    close(1);
    dup(backup_stdout);
    printf("Hello again");
    return 0;
}
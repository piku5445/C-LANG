#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(void)
{
    pid_t childpid;
    printf("Main Pocess: PID: %d, PPID: %d\n\n",getpid(),getppid());

    if (fork() && fork() || fork());
    printf("PID: %d, PPID: %d\n",getpid(),getppid());
    return 0;
}
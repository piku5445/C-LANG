#include <stdio.h>
#include <unistd.h>
// int main(void)
// {
//     printf("I am process %ld\n", (long)getpid());
//     printf("My parent is %ld\n", (long)getppid());
//     sleep(30);
//     return 0;
// }

#include <stdio.h>
#include <unistd.h>
#include<sys/types.h>
int main(void)
{
    // int x;
    // x = 0;
    // pid_t p= fork();
    // x = 1;
    // printf("Pid= %ld, p = %ld, ppid %ld\n", (long)getpid(),p ,(long)getppid());
    // sleep(30);
    int fd =55;
    open(fd);
    perror("Error");
    return 0;
}
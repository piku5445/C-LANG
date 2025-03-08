#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>

int main(){
printf("Parent Process: PID = %d\n", getpid());
//First Child
if(fork()==0){
    printf("c=%d p=%d\n", getpid(), getppid());
    return 0;
}
//second child
if(fork()==0){
printf("c=%d p=%d\n", getpid(), getppid());
//second child  first grandchild
if(fork()==0){
    printf("c=%d p=%d\n", getpid(), getppid());
    return 0;
}
//second child second grandchild
if (fork()==0){
    printf("c=%d p=%d\n", getpid(), getppid());
    if(fork()==0){
        printf("c=%d p=%d\n", getpid(), getppid());
         if(fork()==0){
        printf("c=%d p=%d\n", getpid(), getppid());
        return 0;
         }
         wait(NULL);
         return 0;
    }
    wait(NULL);
    return 0;
    }
    wait(NULL);
    wait(NULL);
    return 0;

}
if(fork()==0){
    printf("c=%d p=%d\n", getpid(), getppid());
    return 0;
}
wait(NULL);
wait(NULL);
wait(NULL);
printf("Parent Process: All children have exited.\n");
return 0;
}

// #include <stdio.h>
// #include <unistd.h>
// #include <sys/wait.h>

// int main() {
//     printf("Parent Process: PID = %d\n", getpid());

//     // First child
//     if (fork() == 0) {
//         printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
//         return 0; // First child exits
//     }

//     // Second child
//     if (fork() == 0) {
//         printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());

//         // First grandchild of second child
//         if (fork() == 0) {
//             printf("Grandchild 1 of Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
//             return 0; // Grandchild exits
//         }

//         // Second grandchild of second child
//         if (fork() == 0) {
//             printf("Grandchild 2 of Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());

//             // Great-grandchild of second child (from Grandchild 2)
//             if (fork() == 0) {
//                 printf("Great-Grandchild of Grandchild 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
//                 return 0; // Great-grandchild exits
//             }

//             wait(NULL); // Wait for great-grandchild
//             return 0; // Grandchild 2 exits
//         }

//         wait(NULL); // Wait for Grandchild 1
//         wait(NULL); // Wait for Grandchild 2
//         return 0; // Second child exits
//     }

//     // Third child
//     if (fork() == 0) {
//         printf("Child 3: PID = %d, Parent PID = %d\n", getpid(), getppid());
//         return 0; // Third child exits
//     }

//     // Parent process waits for all children
//     wait(NULL);
//     wait(NULL);
//     wait(NULL);

//     printf("Parent Process: All children have exited.\n");
//     return 0;
// }

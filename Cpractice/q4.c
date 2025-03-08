// #include<stdio.h>
// #include<unistd.h>
// #include<sys/wait.h>
// int main(){
//     printf("the parent process %d\n",getpid());
//     if(fork()==0){
//         printf("child 1=%d parent 1=%d\n",getpid(),getppid());
//         if(fork()==0){
//             printf("child 2=%d parent 2=%d\n",getpid(),getppid());
//             if(fork()==0){
//                 printf("child 3=%d parent 3=%d\n",getpid(),getppid());
//                 if(fork()==0){
//                     printf("child 4=%d parent 4=%d\n",getpid(),getppid());
//                     if(fork()==0){
//                         printf("child 5=%d parent 5=%d\n",getpid(),getppid());
//                         return 0;
//                     }
//                     wait(NULL);
//                     return 0;
//                 }
//                 else if(fork()>0){
//                     wait(NULL);
//                     printf("child 4=%d parent 4=%d\n",getpid(),getppid());
//                     return 0;
//                 }
//             }
//             else if(fork()>0){
//                 wait(NULL);
//                 printf("child 3=%d parent 3=%d\n",getpid(),getppid());
//                 return 0;
//             }
//         }
//         else if(fork()>0){
//             wait(NULL);
//             printf("child 2=%d parent 2=%d\n",getpid(),getppid());
//             return 0;
//         }
        
//     }
//     else if(fork()>0){
//         wait(NULL);
//         printf("child 1=%d parent 1=%d\n",getpid(),getppid());
//         return 0;
//     }
//     return 0;
// }



#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void create_figure_b() {
    printf("Parent Process: PID = %d\n", getpid());

    // First child
    if (fork() == 0) {
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Second child
        if (fork() == 0) {
            printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());

            // Third child
            if (fork() == 0) {
                printf("Child 3: PID = %d, Parent PID = %d\n", getpid(), getppid());

                // Fourth child
                if (fork() == 0) {
                    printf("Child 4: PID = %d, Parent PID = %d\n", getpid(), getppid());
                    return; // Exit after creation
                }

                wait(NULL); // Wait for fourth child
                return; // Exit third child
            }

            wait(NULL); // Wait for third child
            return; // Exit second child
        }

        wait(NULL); // Wait for second child
        return; // Exit first child
    }

    wait(NULL); // Wait for first child
    printf("Parent Process: All children have exited.\n");
}

int main() {
    create_figure_b();
    return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/wait.h>


// int main(int argc,char *argv[]){
//     if(fork()==0){


//         execlp("./q51.c","./q51.c",argv[1],NULL);
//         perror("execlp failed");
//         exit(1);
//     }

//     else{
//         wait(NULL);
//         printf("parent process is excuting %d",getpid());
//     }

    

    
//     return 0;
// }



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the required argument is provided
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    if (fork() == 0) {
        // Child process
        // Use execlp to execute the compiled q51.c program (e.g., q51.out)
        execlp("./q51.out", "./q51.out", argv[1], NULL);
        
        // If execlp fails, print an error and exit
        perror("execlp failed");
        exit(1);
    } else {
        // Parent process
        wait(NULL); // Wait for the child process to finish
        printf("Parent process is executing, PID = %d\n", getpid());
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number of Fibonacci terms>\n", argv[0]);
        exit(1);
    }

    pid_t pid;
    int n = atoi(argv[1]); // Convert input to integer

    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        exit(1);
    }

    pid = fork(); // Create child process

    if (pid == 0) {
        // Child process
        printf("Child Process: Executing Fibonacci Generator\n");
        
        // Using execv
        char *args[] = {"./fibonacci", argv[1], NULL}; // Pass program name and number
        execv("./fibonacci", args);

        // Uncomment one of the exec versions below to test other methods
        Using execlp
        execlp("./fibonacci", "./fibonacci", argv[1], NULL);

        Using execvp
        execvp("./fibonacci", args);

        // Using execle
        char *env[] = {NULL};
        execle("./fibonacci", "./fibonacci", argv[1], NULL, env);

        // Using execve
        execve("./fibonacci", args, env);

        // If exec fails
        perror("exec failed");
        exit(1);
    } else if (pid > 0) {
        // Parent process
        wait(NULL); // Wait for child process to complete
        printf("Parent Process: Child execution finished.\n");
    } else {
        // Fork failed
        perror("fork failed");
        exit(1);
    }

    return 0;
}

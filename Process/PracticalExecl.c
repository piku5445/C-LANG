#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child Process is executing MultiThread.c\n");
        execl("./MulThread", "./MulThread", "2", "3", "4", (char *)NULL);
        perror("execl failed"); // This will execute only if execl fails
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        int status;
        pid_t child_pid = wait(&status);
        if (child_pid == -1) {
            perror("wait failed");
            exit(EXIT_FAILURE);
        }

        printf("Parent Process is waiting for the child process to complete\n");
        printf("Child Process (PID %d) exited\n", child_pid);

        if (WIFEXITED(status)) {
            printf("Child exited normally with status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Child was killed by signal %d\n", WTERMSIG(status));
        } else {
            printf("Child did not exit normally\n");
        }
    }
    return 0;
}

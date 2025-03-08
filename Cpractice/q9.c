#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int shrd = 10; // Shared variable
    pid_t pid;

    printf("Initial value of shrd: %d\n", shrd);

    pid = fork(); // Create a child process

    if (pid == 0) { 
        // Child process (P1)
        printf("P1 executing...\n");
        int temp = shrd;
        temp = temp + 5;
        sleep(1); // Simulate delay
        shrd = temp;
        printf("P1 updated shrd to: %d\n", shrd);
        exit(0);
    } else {
        // Parent process (P2)
        printf("P2 executing...\n");
        int temp = shrd;
        temp = temp * 2;
        sleep(1); // Simulate delay
        shrd = temp;
        printf("P2 updated shrd to: %d\n", shrd);
    }

    wait(NULL); // Wait for child process to complete
    printf("Final value of shrd: %d\n", shrd);

    return 0;
}

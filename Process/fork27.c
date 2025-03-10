
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 5

int nums[SIZE] = { 0, 1, 2, 3, 4 };

int main() {
    int i;
    pid_t pid;

    pid = fork();

    if (pid == 0) { // Child process
        for (i = 0; i < SIZE; i++) {
            nums[i] = nums[i] * nums[i] - i;
            printf("CHILD: %d\n", nums[i]); /* LINE X */
        }
    } else if (pid > 0) { // Parent process
        wait(NULL); // Wait for the child process to finish
        for (i = 0; i < SIZE; i++) {
            printf("PARENT: %d\n", nums[i]); /* LINE Y */
        }
    }

    return 0;
}

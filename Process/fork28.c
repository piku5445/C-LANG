#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>  // For wait()

int fibo(int n) {
    if (n == 1) {
        return 0;
    } else if (n == 2) {
        return 1;
    } else {
        return fibo(n - 1) + fibo(n - 2);
    }
}
void printFibo(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Sequence up to position %d:\n", n);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", a); // First Fibonacci number
            continue;
        }
        if (i == 2) {
            printf("%d ", b); // Second Fibonacci number
            continue;
        }
        next = a + b; // Compute the next number in the sequence
        printf("%d ", next);
        a = b;        // Update values for the next iteration
        b = next;
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./fibonacci <number>\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process: compute Fibonacci number
        // printf("Fibonacci number at position %d is: %d\n", n, fibo(n));
        printf("the sequence is");
        printFibo(n);
        exit(EXIT_SUCCESS);  // End child process
    } else {
        // Parent process: wait for child to finish
        wait(NULL);
    }

    return 0;
}

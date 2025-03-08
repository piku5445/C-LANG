#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent Process: PID = %d\n", getpid());

    // First child
    if (fork() == 0) {
        printf("\tFirst Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0; // First child exits
    }

    // Second child
    if (fork() == 0) {
        printf("\tSecond Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // First grandchild of second child
        if (fork() == 0) {
            printf("\t\tGrandchild 1 of Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

            // Great-grandchild of second child
            if (fork() == 0) {
                printf("\t\t\tGreat-Grandchild of Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

                // Great-great-grandchild of second child
                if (fork() == 0) {
                    printf("\t\t\t\tGreat-Great-Grandchild of Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
                    return 0;
                }

                wait(NULL); // Wait for great-great-grandchild
                return 0;   // Great-grandchild exits
            }

            wait(NULL); // Wait for great-grandchild
            return 0;   // Grandchild exits
        }

        // Second grandchild of second child
        if (fork() == 0) {
            printf("\t\tGrandchild 2 of Second Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
            return 0; // Second grandchild exits
        }

        wait(NULL); // Wait for grandchildren
        wait(NULL);
        return 0; // Second child exits
    }

    // Third child
    if (fork() == 0) {
        printf("\tThird Child: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0; // Third child exits
    }

    // Parent process waits for all children
    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}


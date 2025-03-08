#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent Process: PID = %d\n", getpid());

    // First child
    if (fork() == 0) {
        printf("\tFirst Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Grandchild
        if (fork() == 0) {
            printf("\t\tGrandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());

            // First child of grandchild
            if (fork() == 0) {
                printf("\t\t\tFirst Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
                return 0;
            }

            // Second child of grandchild
            if (fork() == 0) {
                printf("\t\t\tSecond Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());

                // Child of the second child of grandchild
                if (fork() == 0) {
                    printf("\t\t\t\tChild of Second Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
                    return 0;
                }

                wait(NULL); // Wait for child
                return 0;
            }

            // Third child of grandchild
            if (fork() == 0) {
                printf("\t\t\tThird Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
                return 0;
            }

            wait(NULL); // Wait for first child of grandchild
            wait(NULL); // Wait for second child of grandchild
            wait(NULL); // Wait for third child of grandchild
            return 0;
        }

        wait(NULL); // Wait for grandchild
        return 0;
    }

    wait(NULL); // Wait for first child
    return 0;
}
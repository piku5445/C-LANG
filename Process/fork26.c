#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Parent Process: PID = %d\n", getpid());

    // First child process
    pid_t first_child = fork();
    if (first_child == 0) {
        // Inside the first child
        printf("\tFirst Child: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Grandchild process
        pid_t grandchild = fork();
        if (grandchild == 0) {
            // Inside the grandchild
            printf("\t\tGrandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());

            // First child of the grandchild
            pid_t gc_child1 = fork();
            if (gc_child1 == 0) {
                printf("\t\t\tFirst Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
            } else if (gc_child1 > 0) {
                // Second child of the grandchild
                pid_t gc_child2 = fork();
                if (gc_child2 == 0) {
                    printf("\t\t\tSecond Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());

                    // Child of the second child of the grandchild
                    pid_t gc2_child = fork();
                    if (gc2_child == 0) {
                        printf("\t\t\t\tChild of Second Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
                    } else if (gc2_child > 0) {
                        wait(NULL); // Wait for child of second child
                    }
                } else if (gc_child2 > 0) {
                    // Third child of the grandchild
                    pid_t gc_child3 = fork();
                    if (gc_child3 == 0) {
                        printf("\t\t\tThird Child of Grandchild: PID = %d, Parent PID = %d\n", getpid(), getppid());
                    } else if (gc_child3 > 0) {
                        // Wait for all children of the grandchild
                        wait(NULL);
                        wait(NULL);
                        wait(NULL);
                    }
                }
            }
        } else if (grandchild > 0) {
            wait(NULL); // Wait for grandchild
        }
    } else if (first_child > 0) {
        // Parent process waits for the first child
        wait(NULL);
    }

    return 0;
}

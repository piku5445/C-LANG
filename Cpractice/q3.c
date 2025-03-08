#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void create_figure_a() {
    printf("Parent Process: PID = %d\n", getpid());

    // First child
    if (fork() == 0) {
        printf("Child 1: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // First grandchild
        if (fork() == 0) {
            printf("Grandchild 1: PID = %d, Parent PID = %d\n", getpid(), getppid());
            return; // Exit after creation
        }

        // Second grandchild
        if (fork() == 0) {
            printf("Grandchild 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
            return; // Exit after creation
        }

        wait(NULL); // Wait for both grandchildren
        wait(NULL);
        return; // Exit first child
    }

    // Second child
    if (fork() == 0) {
        printf("Child 2: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return; // Exit after creation
    }

    wait(NULL); // Wait for first child
    wait(NULL); // Wait for second child
    printf("Parent Process: All children have exited.\n");
}

int main() {
    create_figure_a();
    return 0;
}

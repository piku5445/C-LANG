#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t p1, p2;
    p2 = 0; // Initialize p2 to 0

    p1 = fork(); // First fork
    if (p1 == 0) {
        p2 = fork(); // Second fork (only in the child process created by p1)
    }

    if (p2 > 0) {
        fork(); // Third fork (only if p2 > 0)
    }

    printf("done\n"); // This will execute in all processes
    return 0;
}

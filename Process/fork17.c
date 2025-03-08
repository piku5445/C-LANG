#include <stdio.h>
#include <unistd.h> // For fork()
#include <sys/types.h> // For pid_t

int main() {
    pid_t c1 = 1, c2 = 1;

    c1 = fork(); // First fork

    if (c1 != 0) {
        c2 = fork(); // Second fork (only in the parent process of the first fork)
    }

    if (c2 == 0) {
        fork(); // Third fork (only in the child process of the second fork)
        printf("1\n");
    }

    return 0;
}

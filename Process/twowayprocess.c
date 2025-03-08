#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int p1[2];
    if (pipe(p1) == -1) {
        return 1; // Pipe creation failed
    }

    int pid = fork();
    if (pid == -1) {
        return 2; // Fork failed
    }

    if (pid == 0) {
        // Child process
        int x;
        if (read(p1[0], &x, sizeof(x)) == -1) {
            return 3; // Read error in child
        }
        printf("Received %d\n", x);
        x *= 4;
        if (write(p1[1], &x, sizeof(x)) == -1) {
            return 4; // Write error in child
        }
        printf("Wrote %d\n", x);
    } else {
        // Parent process
        srand(time(NULL));
        int y = rand() % 10;
        if (write(p1[1], &y, sizeof(y)) == -1) {
            return 5; // Write error in parent
        }
        printf("Wrote %d\n", y);
        if (read(p1[0], &y, sizeof(y)) == -1) {
            return 6; // Read error in parent
        }
        printf("Result is %d\n", y);
        wait(NULL); // Wait for the child process to finish
    }

    close(p1[0]);
    close(p1[1]);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    pid_t childpid = 0; // Variable to hold child process ID
    int i, n;

    // Check if the number of command-line arguments is exactly 2 (the program name + one argument)
    if (argc != 2) {
        fprintf(stderr, "Usage: %s processes\n", argv[0]);
        return 1;
    }

    // Convert the second argument to an integer to determine the number of processes to create
    n = atoi(argv[1]);

    // Create child processes in a loop
    for (i = 1; i < n; i++) {
        if (childpid = fork())  // If fork() returns a non-zero value (parent process)
            break;               // Exit the loop in the parent process
    }

    // Print process information: i (loop index), process ID (getpid), parent process ID (getppid), child process ID (childpid)
    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", i, (long)getpid(), (long)getppid(), (long)childpid);

    return 0;
}

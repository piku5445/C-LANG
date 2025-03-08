#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    pid_t childpid = 0;  // Variable to hold child process ID
    int i, n;

    // Check if the program is called with exactly one command-line argument
    if (argc != 2) {
        // If not, print usage information and return an error code
        fprintf(stderr, "Usage: %s processes\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument (number of processes to create) into an integer
    n = atoi(argv[1]);

    // Loop to create `n-1` child processes
    for (i = 1; i < n; i++) {
        // Create a new process using fork()
        // fork() returns:
        //  - `0` in the child process (because it's the child)
        //  - a positive number (child PID) in the parent process
        if ((childpid = fork()) <= 0) 
            break;  // Break out of the loop in both parent and child
    }

    // Print process details (PID, PPID, and child PID) for each process
    fprintf(stderr, "i:%d process ID:%ld parent ID:%ld child ID:%ld\n", 
            i, (long)getpid(), (long)getppid(), (long)childpid);

    return 0;
}

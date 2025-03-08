#include <stdio.h>
#include <unistd.h>

int main(void) {
    fprintf(stderr, "PID=%ld\n", (long)getpid());  // Print the PID of the current process
    while (1);  // Infinite loop, process never exits
    return 0;
}


// R (Running): The process is currently being executed.
// S (Sleeping): The process is sleeping (waiting for some event, like I/O).
// T (Stopped): The process has been stopped (e.g., by a signal).
// Z (Zombie): The process has completed execution, but its parent hasn't yet read its exit status (i.e., it's waiting to be cleaned up).
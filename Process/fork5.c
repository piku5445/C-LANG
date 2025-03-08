#include <stdio.h>    // For printf
#include <unistd.h>   // For fork()

int main() {
    // First fork - creates one additional process
    fork(); 

    // Second fork with a logical AND condition
    // fork() && fork() ensures that the second fork executes only 
    // if the first fork (left-hand side of &&) returns non-zero (i.e., not the child process)
    fork() && fork();

    // Third fork - creates more processes
    fork();

    // Print statement executed by all processes
    printf("Got!!!\n");

    return 0;
}

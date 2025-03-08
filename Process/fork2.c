#include <stdio.h>    // For printf
#include <unistd.h>   // For fork

int main() {
    fork();                   // First fork
    fork() + fork();          // Two forks in a single statement
    fork();                   // Another fork
    printf("doing!\n");       // Print statement executed by all processes
    return 0;
}

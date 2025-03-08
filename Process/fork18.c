#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

// Define the structure
struct stud {
    int r; // Roll number
    int m; // Marks
};

int main() {
    struct stud s1 = {1, 20};         // Initialize s1
    pid_t pid = fork();              // Create a child process

    if (pid == 0) {                  // Child process
        struct stud s1 = {2, 30};    // Local s1 in child process
        printf("%d %d\n", s1.r, s1.m); // Print child process's s1
        return 0;
    } else {                         // Parent process
        sleep(10);                   // Parent sleeps for 10 seconds
        printf("%d %d\n", s1.r, s1.m); // Print parent process's s1
        return 0;
    }
}

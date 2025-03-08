#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork()) {                  // Parent process
        if (!fork()) {             // Child of the parent process
            fork();                // Create another process
            printf("S ");
        } else {
            printf("T ");
        }
    } else {                       // Child process from the first fork
        printf("D ");
    }
    printf("A ");
    return 0;
}

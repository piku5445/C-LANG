#include <stdio.h>
#include <unistd.h>

int main(void) {
    if (fork() == 0) {
        printf("1\n");        // Child process created by the first fork
    } else if (fork() == 0) {
        printf("2\n");        // Child process created by the second fork
    } else if (fork() == 0) {
        printf("3\n");        // Child process created by the third fork
    } else if (fork() == 0) {
        printf("4\n");        // Child process created by the fourth fork
    } else {
        printf("5\n");        // Parent process
    }
    return 0;
}

#include <stdio.h>
#include <unistd.h> // For fork()

void show() {
    if (fork() == 0) {        // First fork
        printf("1\n");
    }
    if (fork() == 0) {        // Second fork
        printf("2\n");
    }
    if (fork() == 0) {        // Third fork
        printf("3\n");
    }
}

int main(void) {
    show();                   // Call the show() function
    return 0;
}

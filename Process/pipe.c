#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int fd[2]; // fd[0] - read end, fd[1] - write end

    // Create the pipe
    if (pipe(fd) == -1) {
        printf("An error occurred with opening the pipe\n");
        return 1;
    }

    // Fork a child process
    int id = fork();
    if (id == -1) {
        printf("An error occurred with fork\n");
        return 2;
    }

    if (id == 0) {
        // Child process
        close(fd[0]); // Close the read end of the pipe

        int x;
        printf("Input a number: ");
        scanf("%d", &x);

        // Write the number to the pipe
        if (write(fd[1], &x, sizeof(int)) == -1) {
            printf("An error occurred while writing to the pipe\n");
            close(fd[1]);
            return 3;
        }

        close(fd[1]); // Close the write end of the pipe
    } else {
        // Parent process
        close(fd[1]); // Close the write end of the pipe

        int y;
        // Read the number from the pipe
        if (read(fd[0], &y, sizeof(int)) == -1) {
            printf("An error occurred while reading from the pipe\n");
            close(fd[0]);
            return 4;
        }

        printf("Received number from child: %d\n", y);
        close(fd[0]); // Close the read end of the pipe
    }

    return 0;
}

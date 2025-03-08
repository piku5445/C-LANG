#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    // Generate an array of 5 random integers
    int arr[5];
    srand(time(NULL)); // Seed for random number generation

    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
    }

    // Open the FIFO for writing
    int fd = open("sum", O_WRONLY);
    if (fd == -1) {
        printf("Could not open FIFO file for writing\n");
        return 1;
    }

    // Write each integer in the array to the FIFO
    for (i = 0; i < 5; i++) {
        if (write(fd, &arr[i], sizeof(int)) == -1) {
            printf("Could not write to FIFO\n");
            close(fd);
            return 2;
        }
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

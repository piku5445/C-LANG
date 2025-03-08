#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the FIFO for reading
    int fd = open("sum", O_RDONLY);
    if (fd == -1) {
        printf("Could not open FIFO file for reading\n");
        return 1;
    }

    int arr[5];
    int i;

    // Read integers from the FIFO into the array
    for (i = 0; i < 5; i++) {
        if (read(fd, &arr[i], sizeof(int)) == -1) {
            printf("Could not read from FIFO\n");
            close(fd);
            return 2;
        }
        printf("Received %d\n", arr[i]); // Print each received integer
    }

    close(fd); // Close the file descriptor

    // Calculate the sum of the integers
    int sum = 0;
    for (i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("Result is %d\n", sum); // Print the sum of the integers

    return 0;
}

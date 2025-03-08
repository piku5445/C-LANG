#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

// int fifo you neeed to have both the ends are opened simultaeousy then only it work else it will hangs at opeaning
// Opening the read or write end of a FIFO block until the other end is also opened (by another process or thread )   
int main(int argc, char* argv[]) {
    // Create a FIFO special file with permissions
    if (mkfifo("myfifo1", 0777) == -1) {
        if (errno != EEXIST) {
            printf("Could not create FIFO file\n");
            return 1;
        }
    }
    printf("Opening...");
    // Open the FIFO file for reading  
    int fd=(open('myfifo1',O_RDWR));
    // Open the FIFO file for writing
    int fd = open("myfifo1", O_WRONLY);
    if (fd == -1) {
        printf("Could not open FIFO file for writing\n");
        return 2;
    }

    // Write data to the FIFO
    int x = 97; // Example data
    if (write(fd, &x, sizeof(x)) == -1) {
        printf("Could not write to FIFO\n");
        close(fd);
        return 3;
    }

    // Close the file descriptor
    close(fd);

    return 0;
}

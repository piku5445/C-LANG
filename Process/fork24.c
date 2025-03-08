#include <stdio.h>
#include <unistd.h>

int main(void) {
    fprintf(stderr, "PID=%ld\n", (long)getpid());  // Print the PID of the current process
    while (1)
        sleep(1);  // Sleep for 1 second in an infinite loop
    return 0;
}

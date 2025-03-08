#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i < 12; i++) {
        if (i % 3 == 0) {   // Fork only when i is divisible by 3
            fork();
        }
    }
    return 0;
}
///there will be no output
// this program does not print anything because there is no printf or similar statement inside the loop or elsewhere in the program.

// However, if you add a printf statement inside the loop (e.g., printf("Process: %d\n", getpid());), you will see output from 16 processes, though the exact order will depend on the scheduling of processes by the operating system
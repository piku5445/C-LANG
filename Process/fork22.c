#include <stdio.h>
#include <stdlib.h>

// Define the exit handlers
void X() {
    printf("1 ");
}

void Y() {
    printf("2 ");
}

void P() {
    printf("3 ");
}

void Q() {
    printf("4 ");
}

int main() {


    // In C, the atexit() function allows you to register multiple exit handlers that will be executed when the program terminates (either via return 0; or exit(0);). 
    // The exit handlers are called in the reverse order in which they were registered.
    // Register the exit handlers in the given order
    atexit(X);  // X will be called last
    atexit(Y);  // Y will be called second last
    atexit(P);  // P will be called third last
    atexit(Q);  // Q will be called first

    // Program termination
    printf("Program is terminating...\n");
    return 0;  // or exit(0);
}

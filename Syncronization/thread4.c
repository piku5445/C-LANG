#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to handle thread work
void *passint(void *arg) {
    int recv;
    
    // Cast the argument to an integer pointer, then dereference it to get the value
    recv = *((int *)(arg));
    
    printf("Parameter value = %d\n", recv);
    
    pthread_exit(NULL); // Exit the thread safely
}

int main() {
    int x = 20;             // Integer value to pass to the thread
    pthread_t t;            // Thread identifier
    
    // Create a thread and pass the address of x as an argument
    if (pthread_create(&t, NULL, passint, (void *)&x) != 0) {
        perror("pthread_create failed");
        return 1;           // Return error code if thread creation fails
    }

    // Wait for the thread to finish execution
    if (pthread_join(t, NULL) != 0) {
        perror("pthread_join failed");
        return 1;           // Return error code if thread join fails
    }
    
    printf("Main thread finished.\n");
    
    return 0;               // Exit successfully
}

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

// This is the thread function that prints "my turn" and modifies the passed variable.
void* myturn(void *arg) {
    int *iptr = (int *)arg;
    for (int i = 0; i < 5; i++) {
        sleep(1);
        printf("my turn: i=%d, v=%d\n", i, *iptr);
        (*iptr)++;
    }
    return NULL;  // Thread function must return void*
}

// This function is running in the main thread and prints "your turn".
void yourturn() {
    for (int i = 0; i < 5; i++) {
        sleep(1);
        printf("your turn\n");
    }
}

int main() {
    pthread_t newthread;  // Declare a new thread variable
    int v = 5;  // Variable passed to the thread

    // Create a new thread to run 'myturn' function
    if (pthread_create(&newthread, NULL, myturn, &v) != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Run 'yourturn' in the main thread
    yourturn();  // No argument needed now

    // Wait for the new thread to finish (which will return NULL)
    pthread_join(newthread, NULL);

    // After the thread is done, print the value of 'v'
    printf("Thread's done: v=%d\n", v);

    return 0;
}


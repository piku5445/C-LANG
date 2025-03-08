// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>

// #define MAX_SIZE 100
// #define MAX_FIB 100

// // Function to check if a number is prime
// bool is_prime(int num) {
//     if (num <= 1) return false;
//     for (int i = 2; i * i <= num; i++) {
//         if (num % i == 0) return false;
//     }
//     return true;
// }

// // Function to generate Fibonacci sequence
// void fibo(int n, int f[]) {
//     int a = 0, b = 1, next;
//     for (int i = 0; i < n; i++) {
//         if (i == 0) {
//             f[i] = a;
//         } else if (i == 1) {
//             f[i] = b;
//         } else {
//             next = a + b;
//             f[i] = next;
//             a = b;
//             b = next;
//         }
//     }
// }

// int main() {
//     printf("Enter the length of Fibonacci series: ");
//     int n;
//     scanf("%d", &n);

//     if (n <= 0 || n > MAX_FIB) {
//         printf("Please enter a positive number less than or equal to %d.\n", MAX_FIB);
//         return EXIT_FAILURE;
//     }

//     int f[MAX_FIB]; // Array to store Fibonacci series
//     pid_t pid = fork();

//     if (pid < 0) {
//         perror("Fork Failure");
//         return EXIT_FAILURE;
//     } else if (pid == 0) {
//         // Child process: Generate Fibonacci series
//         fibo(n, f);
//         printf("Child process generated the Fibonacci series.\n");
//         exit(EXIT_SUCCESS);
//     } else {
//         // Parent process: Wait for the child and display results
//         wait(NULL);
//         printf("Parent process displaying results:\n");
//         printf("Fibonacci series: ");
//         for (int i = 0; i < n; i++) {
//             printf("%d ", f[i]);
//         }
//         printf("\n");

//         // Find and display prime Fibonacci numbers
//         printf("Prime Fibonacci numbers:\n");
//         for (int i = 0; i < n; i++) {
//             if (is_prime(f[i])) {
//                 printf("Position: %d, Value: %d\n", i + 1, f[i]);
//             }
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int prime(int a) {
    if (a == 1)
        return 0;
    for (int i = 2; i < a; i++) {
        if (a % i == 0)
            return 0;
    }
    return a;
}

int main() {
    printf("Enter the length: ");
    int n = 0;
    scanf("%d", &n);

    int fib[n];
    pid_t pid = vfork();

    if (pid == 0) { // Child process
        int a = 0, b = 1;
        fib[0] = a;
        fib[1] = b;
        int k = 2;
        int c = n;

        while (c > 0) {
            a = a + b;
            b = a + b;
            fib[k++] = a;
            fib[k++] = b;
            c -= 2;
        }

        _exit(0);
    } else { // Parent process
        wait(NULL);

        // Print the Fibonacci series
        for (int i = 0; i < n; i++)
            printf("%d, ", fib[i]);
        printf("\n");

        // Find and print prime Fibonacci numbers
        printf("Primes are:\n");
        for (int i = 0; i < n; i++) {
            if (prime(fib[i]))
                printf("%d : %d\n", fib[i], i);
        }
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int x;
    int a[2] = {10, 20};
    x = 5 + a[fork() || fork()];  // Calculate x based on fork()
    printf("%d ", x);             // Print the value of x
    return 0;
}

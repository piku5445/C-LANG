#include <stdio.h>

int main() {
    int n = 1111;
    int sum = 0;
    int pow = 1; // Used to place binary digits in the correct position

    while (n > 0) {
        int r = n % 2; // Get the remainder (0 or 1)
        sum = pow * r + sum; // Accumulate the binary result
        pow = pow * 2; // Move to the next binary place value
        n = n / 10; // Divide n by 2 to shift to the next bit
    }

    // Print the result
    printf("Binary representation: %d\n", sum);

    return 0;
}

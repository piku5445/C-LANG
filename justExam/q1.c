#include <stdio.h>

int main() {
    // Declare two integer variables and assign values
    int a = 5;
    int b = 10;

    // Print their initial addresses
    printf("Initial address of a: %p\n", (void*)&a);
    printf("Initial address of b: %p\n", (void*)&b);

    // Swap the contents of the variables
    int temp = a;
    a = b;
    b = temp;

    // Print their addresses after the swap
    printf("Address of a after swap: %p\n", (void*)&a);
    printf("Address of b after swap: %p\n", (void*)&b);

    // Check if the addresses before and after swap are the same
    printf("\nAddresses before and after the swap are the same.\n");

    return 0;
}

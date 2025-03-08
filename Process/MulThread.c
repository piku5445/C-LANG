#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) { // Check if exactly 3 numbers are passed as arguments
        fprintf(stderr, "Usage: ./MulThree <num1> <num2> <num3>\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    int num3 = atoi(argv[3]);

    printf("Multiplication of %d, %d, and %d is: %d\n", num1, num2, num3, num1 * num2 * num3);
    return 0;
}

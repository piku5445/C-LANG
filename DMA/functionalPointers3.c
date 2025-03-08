#include <stdio.h>

// Function definitions
void add(int a, int b) {
    printf("Addition is: %d\n", a + b);
}

void sub(int a, int b) {
    printf("Subtraction is: %d\n", a - b);
}

void mult(int a, int b) {
    printf("Multiplication is: %d\n", a * b);
}

void div(int a, int b) {
    if (b != 0) {
        printf("Division is: %d\n", a / b);
    } else {
        printf("Division by zero is not allowed.\n");
    }
}

int main() {
    int ch, a, b;
    // Array of function pointers
    void (*fptr[4])(int, int) = {add, sub, mult, div};

    printf("0 for add\n1 for sub\n2 for multiply\n3 for divide:\n");
    printf("Enter choice: ");
    scanf("%d", &ch);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (ch >= 0 && ch < 4) {
        (*fptr[ch])(a, b); // Call the selected function
    } else {
        printf("Enter a valid choice.\n");
    }

    return 0;
}

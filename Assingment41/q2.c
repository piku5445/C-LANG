#include <stdio.h>
// *
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int num1 = 10, num2 = 20;

    printf("Before swap: num1 = %d, num2 = %d\n", num1, num2);
    printf("Addresses: num1 = %p, num2 = %p\n", (void*)&num1, (void*)&num2);//(void*)&num1= it is the generic pointer in the c which is used to it can hold the address of any data type (e.g., int, float, char).

    swap(&num1, &num2);

    printf("After swap: num1 = %d, num2 = %d\n", num1, num2);
    printf("Addresses: num1 = %p, num2 = %p\n", (void*)&num1, (void*)&num2);

    return 0;
}

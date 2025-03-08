#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int x = 10, y = 20;
    printf("Before Swap: x = %d, y = %d\n", x, y);
    printf("Addresses: x = %p, y = %p\n", (void*)&x, (void*)&y);
    swap(&x, &y);
    printf("After Swap: x = %d, y = %d\n", x, y);
    printf("Addresses: x = %p, y = %p\n", (void*)&x, (void*)&y);
    return 0;
}

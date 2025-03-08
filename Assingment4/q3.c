#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 99, 4};
    int *p = arr, max = *p;
    for (int i = 1; i < 5; i++) {
        if (*(p + i) > max) max = *(p + i);
    }
    printf("Largest: %d\n", max);
    return 0;
}

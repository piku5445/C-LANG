#include <stdio.h>

// Function to find the largest value in an array using pointers
int findLargest(int *arr, int size) {
    int *ptr = arr; // Pointer to the first element of the array
    int largest = *ptr; // Initialize largest with the first element

    for (int i = 1; i < size; i++) {
        ptr++; // Move the pointer to the next element
        if (*ptr > largest) {
            largest = *ptr; // Update largest if current element is greater
        }
    }
    return largest;
}

int main() {
    int n;

    // Input size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];

    // Input array elements
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Find the largest value
    int largest = findLargest(arr, n);

    // Output the largest value
    printf("The largest value in the array is: %d\n", largest);

    return 0;
}

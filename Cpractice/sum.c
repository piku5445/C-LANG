#include <stdio.h>

// Function to calculate the sum of array elements using recursion
int sumArray(int arr[], int n) {
    // Base case: If the size is 0, the sum is 0
    if (n == 0) {
        return 0;
    }

    // Recursive case: Sum of the array is the last element + sum of the remaining elements
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of the array using recursion
    int sum = sumArray(arr, n);

    // Output the result
    printf("The sum of the array elements is: %d\n", sum);

    return 0;
}

#include <stdio.h>

// Function to compute the transpose of a matrix
void transposeMatrix(int *matrix, int rows, int cols, int *transpose) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(transpose + j * rows + i) = *(matrix + i * cols + j);
        }
    }
}

int main() {
    int rows, cols;

    // Input the dimensions of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int transpose[cols][rows];

    // Input the elements of the matrix
    printf("Enter the elements of the matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute the transpose
    transposeMatrix((int *)matrix, rows, cols, (int *)transpose);

    // Output the transpose of the matrix
    printf("The transpose of the matrix is:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

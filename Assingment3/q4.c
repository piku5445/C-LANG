#include <stdio.h>

void bubblesort(int ar[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {  
            if (ar[j] > ar[j + 1]) {
                int temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

void merge_sorted_Array(int ar1[], int ar2[], int ar3[], int size1, int size2, int size3) {
    bubblesort(ar1, size1);
    bubblesort(ar2, size2);
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (ar1[i] < ar2[j]) {
            ar3[k] = ar1[i];
            i++;
        } else {
            ar3[k] = ar2[j];
            j++;
        }
        k++;
    }
    while (i < size1) {
        ar3[k] = ar1[i];
        i++;
        k++;
    }
    while (j < size2) {
        ar3[k] = ar2[j];
        j++;
        k++;
    }
}

int main() {
    int ar1[] = {4, 4, 5, 32, 3};
    int ar2[] = {1, 2, 3, 4, 5};
    int ar3[10];
    int size1 = 5;
    int size2 = 5;
    int size3 = 10;
    merge_sorted_Array(ar1, ar2, ar3, size1, size2, size3);
    
    for (int i = 0; i < size3; i++) {
        printf("%d ", ar3[i]);
    }
    return 0;
}

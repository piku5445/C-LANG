#include<stdio.h>

int main(){
    //   int arr1[] = {10, 20, 30, 40, 50};
    // int size = sizeof(arr1) / sizeof(arr1[0]);
    // int arr2[size];

    // int *p1 = arr1;
    // int *p2 = arr2;

    // for (int i = 0; i < size; i++) {
    //     *(p2 + i) = *(p1 + i);
    // }

    // printf("Original Array: ");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr1[i]);
    // }
    // printf("\nCopied Array: ");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr2[i]);
    // }
    // printf("\n");
    int arr1[]={120,502,118,106,447};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int *ptr=arr1;
    for(int i=0;i<n;i++){
        printf("%d\n",*(ptr+i));
    }
    return 0;
}
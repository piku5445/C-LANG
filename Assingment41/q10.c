#include<stdio.h>

int main(){
    // int arr[] = {10, 20, 30, 40, 50};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int *ptr = arr;
    // int sum = 0;

    // for (int i = 0; i < size; i++) {
    //     sum += *(ptr + i);
    // }

    // printf("Sum of array elements: %d\n", sum);
    int ar[]={10,20,30,40,50};
    int n=sizeof(ar)/sizeof(ar[0]);
    int *ptr=ar;
    int sum=0;
    for(int i =0;i<n;i++){
        sum=sum+*(ptr+i);

    }
    printf("the sum of the array is %d\n",sum);
    return 0;
}
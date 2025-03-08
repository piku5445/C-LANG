#include<stdio.h>

int main(){
    // int arr1[] = {10, 13, 20, 33, 44};
    // float arr2[] = {10.2, 13.3, 20.0, 33.3, 45.3};

    // int *p1 = arr1;
    // float *p2 = arr2;

    // for (int i = 0; i < 5; i++) {
    //     printf("arr1[%d] = %d, Address = %p\n", i, *(p1 + i), (void*)(p1 + i));
    //     printf("arr2[%d] = %.2f, Address = %p\n", i, *(p2 + i), (void*)(p2 + i));
    // }

    int ar1[]={10,13,20,33,44};
    int ar2[]={10.2,13.3,20.0,33.3,45.3,89.9};
    int n=sizeof(ar1)/sizeof(ar1[0]);
    int m=sizeof(ar2)/sizeof(ar2[0]);
    int *ptr1=ar1;
    int * ptr2=ar2;



    for(int i=0;i<n;i++){

        printf("the values of the array ar1 is%d\n and the address of the arr1 %p\n the value of the array 2 is %f\n the address of the array 2 is %p\n",*(ptr1+i),(ptr1+i),*(ptr2+i),(ptr2+i));

    }

    return 0;
}
#include<stdio.h>

int main(){
    //  int arr[] = {10, 20, 30, 40, 50};
    // int size = sizeof(arr) / sizeof(arr[0]);

    // for (int i = 0; i < size; i++) {
    //     printf("Element at index %d: Value = %d, Address = %p\n", i, arr[i], &arr[i]);
    // }

   int ar[]={0,10,20,30,40,50,60,70,80,90};
   int n=sizeof(ar)/sizeof(ar[0]);

   for(int i=0;i<n;i++){
    printf("%d\n",*(ar+i));
    printf("%p\n",&ar[i]);
   }





    return 0;
}
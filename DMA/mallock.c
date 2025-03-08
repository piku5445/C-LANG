// #include<stdio.h>
// #include<stdlib.h>
// int main(){
//     int  n,i,*ptr;
//     printf("enter the total number of values");
//     scanf("%d",&n);
//     ptr=(int*)malloc(n*sizeof(int));
//     printf("\n enter the values");
//     for(int i=0;i<n;i++){
//         scanf("%d",(ptr+i));

//     }

// printf("\n enter the values");
//     for(int i=0;i<n;i++){
//         printf("%d",*(ptr+i));
        
//     }
//     return 0;
// }




#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, i, *ptr;  // Declare i once here
    printf("Enter the total number of values: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {  // Check for successful memory allocation
        printf("Memory allocation failed!");
        return 1;
    }

    printf("\nEnter the values:\n");
    for (i = 0; i < n; i++) {  // Use the existing i
        scanf("%d", (ptr + i));
    }

    printf("\nThe entered values are:\n");
    for (i = 0; i < n; i++) {  // Use the existing i
        printf("%d ", *(ptr + i));
    }

    free(ptr);  // Free the allocated memory
    return 0;
}

 #include<stdio.h>
 void swap(int var1, int var2)
 {
 int temp;
 temp = var1;
 var1 = var2;
 var2 = temp;
 printf("After swapping the value in var1 : %d (in function)\n", var1);
 printf("After swapping the value in var2 : %d (in function)\n", var2);
 }
 int main(){
 int var1 = 5, var2=6;
 printf("Before swapping the value in var1 : %d (in main)\n", var1);
 printf("Before swapping the value in var2 : %d (in main)\n", var2);
 swap(var1, var2);
 printf("After swapping the value in var1 : %d (in main)\n", var1);
 printf("After swapping the value in var2 : %d (in main)\n", var2);
 return(0);
 }
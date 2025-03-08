#include <stdio.h>
 #define a_size 5
 int main()
 {
 int square[a_size], i,sum;
 for (i = 0; i < a_size; i++)
 square[i] = i * i;
 for (i = 0; i < a_size; i++)
 printf("square[%d] has address %d and value %d \n",i,&square[i],square[i]);
 sum=0;
 for (i = 0; i < a_size; i++)
 sum=sum+square[i];
 printf("Sum of all the data in square[] is %d \n",sum);
 }
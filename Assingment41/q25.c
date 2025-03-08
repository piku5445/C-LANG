#include<stdio.h>
int  largest(int *ar,int size){
int *ptr=ar;
int max=*ptr;
for(int i=0;i<size;i++){
    if(*(ptr+i)>max){
        max=*(ptr+i);
    }
}
return max;
}
int main(){
   int ar[]={1,2,3,4,5,5};
  int max= largest(ar,6);
  printf("the maximum value is %d",max);


    return 0;
}
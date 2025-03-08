#include<stdio.h>

int main(){
    int count=10;
    int *ptr=&count;
    printf("%d\n",*ptr);
    printf("Adress of the count is %p\n",&count);
    printf("addrss of the ptr is %p\n",ptr);
    printf("the value of the ptr is %d\n",*ptr);
    *ptr=++(*ptr);
    printf("the value of ptr is %d\n",*ptr);





    return 0;
}
#include<stdio.h>

int main(){
    int a[6]={120,502,118,188,106,447};
    int size=sizeof(a)/sizeof(a[0]);
    int *ptr=a;
    for(int i=0;i<size;i++){
        printf("%d\n",*(ptr+i));
    }

    return 0;
}
#include<stdio.h>

int main(){
    int a[]={1,2,3,4};
    int b[]={5,6,7,8};
    int c[]={9,10,11,12};
    int d[]={13,14,15,16};
    int sumarr[4];
    int *arr[4]={a,b,c,d};
    for(int i=0;i<4;i++){
        sumarr[i]=0;
        for(int j=0;j<4;j++){
            sumarr[i]+=arr[i][j];

        }
    }
    printf("Sum Array");
    for(int i=0;i<4;i++){
        printf("%d\n",sumarr[i]);
    }
    return 0;
}
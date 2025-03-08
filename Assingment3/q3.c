#include<stdio.h>
void bubblesort(int ar[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-1;j++){
            if(ar[j]>ar[j+1]){
                int temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
}
void display(int ar[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",ar[i]);
    }
}
int main(){
    int ar[]={14,43,21,3,4,32,4,2,5,6};
    int size=10;
    bubblesort(ar,size);
    display(ar,size);
    
    return 0;
}
#include<stdio.h>
void binarySearch(int ar[],int size,int key,int low,int high){
    int mid=(high+low)/2;
    if(low<=high){
        if(ar[mid]==key){
            printf("key is found");
        }
        else if(ar[mid]>key){
            
            binarySearch(ar,size,key,low,mid-1);
        }
        else if(ar[mid]<key){
            binarySearch(ar,size,key,mid+1,high);
        }
       
    }
}
int main(){
    int ar[]={1,2,3,4,5,6,7,8,9,10};
    int key;
    printf("enter the key");
    scanf("%d",&key);

    int size=10;
    int low=0;
    int high=9;
    binarySearch(ar,size,key,low,high);
    return 0;
}
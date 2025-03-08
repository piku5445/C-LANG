#include<stdio.h>
void checkduplicate(int ar[],int size){
    for(int i=0;i<size;i++){
        int flag=0;
        for(int j=i+1;j<size;j++){

            if(ar[i]==ar[j]){
            flag=1;
            break;
            }
        }
        if(!flag){
            printf("%d",ar[i]);
        }
        
    }
}
int main(){
    int ar[]={3,4,4,5,7,7,3,2,1,3};
    checkduplicate(ar,9);
    return 0;
}
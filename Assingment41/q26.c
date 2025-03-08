#include<stdio.h>
 void transpose(int (*ar)[4],int row,int col){
int temp;
     for(int i =0;i<row;i++){
        for(int j=i+1;j<col;j++){
            temp=*(*(ar+i)+j);
*(*(ar+i)+j)=*(*(ar+j)+i);
*(*(ar+j)+i)=temp;


        }
    }
}
int main() {
    int arr[4][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {8, 9, 10, 11}, {0, 0, 0, 0}};
int row=4;
int col=4;
transpose(arr,row,col);
printf("Transpose of the matrix is :\n");

for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        printf("%d",*(*(arr+i)+j));
    }
    printf("\n");
}

    return 0;
}

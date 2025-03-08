#include<stdio.h>
int main(){
    int a[3][3]={{2,21,2},{2,1,2},{2,2,2}};
    int **ptr=a;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++,ptr++){
            printf("%d ",*ptr);
    }
    printf("\n");
    
}
}

#include<stdio.h>
int main() {
    int a[3][3] = {{2, 21, 2}, {2, 1, 2}, {2, 2, 2}};
    int *ptr = &a[0][0]; 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(ptr + i * 3 + j)); 
        }
        printf("\n");
    }

    return 0; 
}
// int p[]={1,2,3,4};
// int *t=p;   t=&p

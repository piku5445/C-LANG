#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    // char name[5][30];
    // int i;
    // for(i=0;i<5;i++){
    //     gets(name[i]);
    // }
    // printf("Name of students: \n");
    // for(i=0;i<5;i++){
    //     puts(name[i]);
    // }

    // char *name[5],str[100];
    // int i;
    // for(i=0;i<5;i++){
    //     gets(str);
    //     name[i]=(char *)malloc(strlen(str)+1);
    //     strcpy(name[i],str);
    // }
    // printf("Name of students: \n");
    // for(i=0;i<5;i++){
    //     puts(name[i]);
    // }

    char **name,str[100];
    int i,n;
    printf("Enter the number of students:");
    scanf("%d",&n);
    name = (char**)malloc(n*sizeof(char *));
    for(i=0;i<n;i++){
        gets(str);
        name[i]=(char *)malloc(strlen(str)+1);
        strcpy(name[i],str);
    }
    printf("Name of students: \n");
    for(i=0;i<n;i++){
        puts(name[i]);
    }
    return 0;
}

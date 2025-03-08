#include<stdio.h>

int main(){
    int la=345;
float fb=4.5;
char Chvar='Z';
printf("the data int he following table is ");

printf("%d\n",la);
printf("%f\n",fb);
printf("%c\n",Chvar);

printf("the address of the following data is ");
printf("%p\n",(void *)&la);
printf("%p\n",(void *)&fb);
printf("%p\n",(void *)&Chvar);
    return 0;
}
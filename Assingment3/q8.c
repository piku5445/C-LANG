#include<stdio.h>
#include<string.h>
char piku(char *str){
    int n=strlen(str);
    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            if(str[i]==str[j]){

                return str[i];
        }
    }
}
return '\0';
}
int main(){
    
    char p[]="racecar";
    printf("%c",piku(p));
    return 0;

}
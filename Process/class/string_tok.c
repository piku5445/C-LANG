#include<stdio.h>
#include<string.h>

char *mystrtok(char *,const char *);
int main()
{
    char str[]="Hello Good Morning";
    char str2[]="This is PPWC Class";
    char delim[]=" ";
    char *token,*token2;
    // printf("Input: %s\n",str);

    token = strtok(str,delim);
    token2 = strtok(str2,delim);
    while(token2){
        // printf("input: %s\n",str);
        printf("Token: %s\n",token);
        token=strtok(NULL,delim);
    }
    return 0;
}
char *mystrtok(char *str,const char * delim){
    static char * inputStr;
    if(str){
        inputStr = str;
    }
    char * token = inputStr;
    if (*inputStr == 0)
        return NULL;
    while (*inputStr)
    {
        if (*inputStr == *delim){
            *inputStr = 0;
            inputStr++;
            return token;
        }
        inputStr++;
    }
    return token;
}
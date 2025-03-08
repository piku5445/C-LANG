#include<stdio.h>
#include<string.h>

unsigned int xstrlen(const char *);
char * xstrcpy(char *, const char *);
int xstrcmp(const char *, const char *);

int main()
{
    // char str1[] = "Hello Good Morning!!!";
    // char str2[500],*str3;

    char str1[] = "Hello";
    char str2[]="Hi";

    printf("%d \n",xstrcmp("Hi","Hilo"));

    // str3 = xstrcpy(str2,str1);
    // str2[3]='K';
    // printf("STR2: %s\n",str2);
    // printf("STR3: %s\n",str3);
    // int len= xstrlen(str1);
    // printf("Len: %d\n",len);
    return 0;
}
int xstrcmp(const char *s1, const char *s2){
    int i=0;
    while(s1[i]){
        if (s1[i]-s2[i])
            return (s1[i]-s2[i]);
        i++;
    }
    return (s1[i]-s2[i]);
}


char * xstrcpy(char * dest, const char * src){
    int i=0;
    while(src[i]){
        dest[i]=src[i];
        i++;
    }
    dest[i]=0;
    return dest;
}
unsigned int xstrlen(const char * str){
    int i=0;
    while(str[i]!=0)
        i++;
    return i;
}
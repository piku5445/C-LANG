#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    if(argc != 3){
        fprintf(stderr,"Usage: <progname> <arg1> <arg2> \n");
        exit(EXIT_SUCCESS);
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int c = a+b;
    printf("Sum: %d\n",c);
    // printf("argc: %d\n",argc);
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("argv[%d] : %s\n",i,argv[i]);
    // }
    
    return 0;
}

// int main(){

//     printf("hello\n");
// }

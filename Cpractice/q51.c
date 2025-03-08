#include<stdio.h>
#include<stdlib.h>

void fibonacci(int n){
       int a=0;int b=1;
       int temp;
       for(int i=0;i<n;i++){
           
           if(i==0){
            printf("%d ",a);
           }
           if(i==1){
            printf("%d ",b);
           }
           temp=a+b;
            printf("%d ",temp);


           a=b;
           b=temp;
          

    }}
int main(int argc ,char*argv[]){
    int n=atoi(argv[1]);
    fibonacci(n);
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/wait.h>

// void fibonacci(int n) {
//     int a = 0, b = 1, temp;
//     for (int i = 0; i < n; i++) {
//         if (i == 0) {
//             printf("%d ", a);
//         } else if (i == 1) {
//             printf("%d ", b);
//         } else {
//             temp = a + b;
//             printf("%d ", temp);
//             a = b;
//             b = temp;
//         }
//     }
//     printf("\n");
// }

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("Usage: %s <number>\n", argv[0]);
//         return 1;
//     }

//     int n = atoi(argv[1]);

//     if (fork() == 0) {
//         // Child process
//         execlp("./q51.out", "./q51.out", argv[1], NULL);
//         perror("execlp failed");
//         exit(1);
//     } else {
//         // Parent process
//         wait(NULL);
//         printf("Parent process is executing, PID = %d\n", getpid());
//     }

//     return 0;
// }

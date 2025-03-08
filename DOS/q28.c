 #include <stdio.h>
#include <unistd.h>
#include<sys/wait.h>
  //jis time child ka value change hoga then the value of vfork me parent ka value v change hoga beacuse they share same memory space 
  int main( )  
       {          
int i=5;  
         if(vfork( )==0)  
         {  
              printf("Child: %d",i);  
              _exit(0);  
          }           
else  
         {  
              printf("Parent: %d",i);  
          }  
           return 0;  
        }  
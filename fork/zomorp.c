
//zombie process

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

    pid_t childpid = fork();
 

    if (childpid > 0){
        sleep(10); 
printf("parent process\n");
          //parent is sleeping and child becomes zombie 
    }
 
    // Child process
    else {       
printf("child process\n");
        exit(0);    // child process exits
 }
    return 0;
} 

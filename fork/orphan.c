#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{


pid_t pid=fork();  // calling fork



if(pid>0)
{
printf("in parent prcess\n");
}

else if(pid==0)
  {
   sleep(25);  // parent process finishes execution and child is still sleeping
   printf("in child prcess\n");
  }
return 0;
}

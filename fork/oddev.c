#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{
  
    int n;
    printf("enter the value\n");
    scanf("%d", &n);
    


    pid_t pid=fork();  //fork calling
    int i;
    //child process
    if(pid==0)
    {           
      printf("\n the even nos\n");
      for(i=0;i<n;++i)
      {
        if(i%2==0)         // checking od even nos
         {
               printf("%d\n", i);
         }
      }
    }
    //parent process
    else if(pid>0)
    { 
    printf("the odd no\n");
      for(i=0;i<n;++i)
       {
          if(i%2!=0)    // checking of odd nos
          {
          printf("%d \n", i);
          }
       }
    }
return 0;



}
       

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
int main()
{
    
   int   i,n;
  pid_t pid;
 
    printf("Enter an integer: ");
    scanf("%d", &n);
     pid = fork();
 
 
  if(pid == 0)
  { 
    
printf("\neven numbers\n");
for(i=0;i<=n;i++)
      {
        if(i % 2 == 0)
         {
           printf("%d \t",i);
         }   // Do child's job
      }
   }
  else if(pid>0)
  {
printf("\nodd numbers are\n");
    for(i=0;i<=n;i++)
      {

        if(i % 2 != 0)
         {
    // Do parent's job
        printf("%d \t",i);
  }
}
 }


    return 0;
}

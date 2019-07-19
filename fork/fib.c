#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{
    pid_t pid;  
    pid=vfork(); // calling vfork
    int i,n;
    // child process
    if(pid==0)
    {
        printf("enter the VALUE\n");
        scanf("%d", &n);
    }
    // parent process
    else if(pid>0)
    {
    int k[100];
    k[0]=0;
    k[1]=1;
    for(i=0;i<=1;++i)
    {
    printf("%d", k[i]);
    }
    for(i=2;i<n;i++)
    {
    k[i]=k[i-1] + k[i-2];
    printf("%d", k[i]);
    }
    }



return 0;

}


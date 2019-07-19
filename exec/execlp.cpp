#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{
		pid_t pid;
		pid=fork();

		if(pid==0)
		{
			sleep(1);
			execlp("ls", "ls", "-t", "-l", NULL);
		
		} 
		else if(pid>0)
		{		
			execlp("pwd","pwd",NULL);
		}

	
	return 0;
}

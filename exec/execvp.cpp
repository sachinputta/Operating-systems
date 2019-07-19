#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{
	
	char *args[] = {"ls","-t", "-l", NULL };
	execvp("ls", args);

	return 0;
}

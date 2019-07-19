#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{


		execl("/bin/ls", "/bin/ls", "-t", "-l", NULL);
		
	
	return 0;
}

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(void)
{

	char *args[] = {"/bin/pwd", NULL};
	
	execv("/bin/pwd", args);
	


}

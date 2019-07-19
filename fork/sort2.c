#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
   int n, a[n];
   int i,j,temp;

   printf("enter the total no\n");
   scanf("%d", &n);
// enter the array values
for(i=0;i<n;++i)
{
     scanf("%d", &a[i]);
}
int temp1=n/2;    // half array
int temp2=n-temp1;    // last half array
pid_t pid= fork();    // fork calling

// child process
if(pid==0)
{
    printf("aescEnding order\n");
    for(i=0;i<temp1;i++)
    {
         for(j=i+1;j<temp1;j++)
         {
             if(a[i]>a[j])
             {
               temp=a[i];
               a[i]=a[j];
               a[j]=temp;
             }
         }
     }

printf("sorted by child\n");
for(i=0;i<temp1;i++)
{
       printf("%d", a[i]);
}


}
// parent process
else if(pid>0)
	{

		printf("\naescending order is\n");

              for (i = temp1; i < n; ++i)
 		{
                  for (j = i + 1; j < n; ++j)
	           {  
                     if (a[i] >a[j])
                       {
                          temp=a[i];
	   		  a[i] = a[j];
			  a[j] = temp;
 		       }
  		  }
        	}


		for(i=temp1;i<n;++i)
		{
			printf("%d \t",a[i]);
		}


	}


	return 0;
}

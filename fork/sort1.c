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

for(i=0;i<n;++i)
{
     scanf("%d", &a[i]);
}

pid_t pid;
pid=fork();

if(pid==0)
{
    printf("ascending order\n");
    for(i=0;i<n;i++)
    {
         for(j=i+1;j<n;j++)
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
for(i=0;i<n;i++)
{
       printf("%d", a[i]);
}


}
else if(pid>0)
	{

		printf("\nthe array in descending order is\n");

              for (i = 0; i < n; ++i)
 		{
                  for (j = i + 1; j < n; ++j)
	           {  
                     if (a[i] < a[j])
                       {
                          temp=a[i];
	   		  a[i] = a[j];
			  a[j] = temp;
 		       }
  		  }
        	}


		for(i=0;i<n;++i)
		{
			printf("%d \t",a[i]);
		}


	}


	return 0;
}


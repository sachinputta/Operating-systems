#include <iostream>
#include <iomanip>
#include "fcfs.h"

using namespace std;


void swap(int *a, int *b)
{
int temp= *a;
*a=*b;
*b=temp;
}

void fcfs(scheduling array[],int n)
{
for(int i=0; i<n; ++i)
{
  for (int j=i+1; j<n;j++)
   {
     if(array[i].at> array[j].at)
     {
        swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
     }
     else if(array[i].at == array[j].at)
     {
        if( array[i].pid > array[j].pid)
        {
          swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
        }
     }
    }
}

array[0].ct=array[0].at + array[0].bt;
array[0].calculateTAT();
array[0].calculateWT();










for(int i=1;i<n; ++i)
{
   if(array[i].at>array[i-1].ct)
   {
     array[i].ct = array[i].at + array[i].bt;
   }
   else
   {
     array[i].ct= array[i-1].ct + array[i].bt;
   }
       array[i].calculateTAT();
       array[i].calculateWT();

}

}


/*void sjf(scheduling array[],int n)
{
for(int i=0; i<n; ++i)
{
  for (int j=i+1; j<n;j++)
   {
     if(array[i].at> array[j].at)
     {
        swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
     }
     else if(array[i].at == array[j].at)
     {
        if( array[i].pid > array[j].pid)
        {
          swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
        }
     }
    }
}

array[0].ct=array[0].at + array[0].bt;









array[0].calculateTAT();
array[0].calculateWT();


for(int i=1; i<n; ++i)
{
  for (int j=i+1; j<n;j++)
   {
     if(array[i].bt> array[j].bt)
     {
        swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
     }
     else if(array[i].bt == array[j].bt)
     {
        if( array[i].at > array[j].at)
        {
          swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
        }
     }
    }
}

for (int i = 1; i < n; ++i)
	{
		if (array[i].at>array[i-1].ct)
		{
			array[i].ct=array[i].at+array[i].bt;
		}
		else
		{
			array[i].ct=array[i-1].ct+array[i].bt;
			
		}
		array[i].calculateTAT();
		array[i].calculateWT();
	}

}*/

void sort(scheduling array[], int m, int n, int ct)
{
	if (array[m].at<=ct)
	{
		for (int i = m+1; i < n; ++i)
		{
			if (array[i].bt<array[m].bt and array[i].at<=ct)
			{
				swap(array[i].at,array[m].at);
				swap(array[i].bt,array[m].bt);
				swap(array[i].pid,array[m].pid);
			}
			if(array[i].bt==array[m].bt and array[i].at<=ct)
			{
				if (array[i].at<array[m].at)
				{
				    swap(array[i].at,array[m].at);
			            swap(array[i].bt,array[m].bt);
				    swap(array[i].pid,array[m].pid);
				}
				if (array[i].at==array[m].at and array[i].pid<array[m].pid)	
				{
					swap(array[i].at,array[m].at);
                              		swap(array[i].bt,array[m].bt);
				        swap(array[i].pid,array[m].pid);
				}
			}
		}
		array[m].ct=array[m-1].ct+array[m].bt;
		array[m].calculateTAT();
		array[m].calculateWT();
	}
	else
	{
		array[m].ct=array[m].at+array[m].bt;
		array[m].calculateTAT();
		array[m].calculateWT();
	}
}

void sjf(scheduling array[], int n)
{
	array[0].ct=array[0].at+array[0].bt;
	array[0].calculateTAT();
	array[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sort(array,i,n,array[i-1].ct);
	}

}



/*void srtf(scheduling array[],int n)
{
int c=0;
for(int i=0; i<n; ++i)
{
  for (int j=i+1; j<n;j++)
   {
     if(array[i].at> array[j].at)
     {
        swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
     }
     else if(array[i].at == array[j].at)
     {
        if( array[i].pid > array[j].pid)
        {
          swap(array[i].at, array[j].at);
        swap(array[i].pid, array[j].pid);
        swap(array[i].bt, array[j].bt);
        }
     }
    }
}

array[0].bt=array[0].bt-1;
c++;
int min=array[0].bt;
i=0;
for(i=1;i<n;++i)
	{
		if (array[i].at<c)
		{
                   if(array[i].bt< min && array[i].bt>=0)
                    {
                       min=array[i].bt;
                    }
                }
 
        }


                    for(j=0;j<max;++j)
                    {
                        if(array[j].bt>array[i].bt)
                         {
			array[i].bt=array[i].bt-1;
                         c++;
                          }
                     }
		}
		else
		{
			array[i].ct=array[i-1].ct+array[i].bt;
			
		}
		array[i].calculateTAT();
		array[i].calculateWT();
	}


for (int i = 1; i < n; ++i)
	{
		if (array[i].at>array[i-1].ct)
		{
			array[i].ct=array[i].at+array[i].bt;
		}
		else
		{
			array[i].ct=array[i-1].ct+array[i].bt;
			
		}
		array[i].calculateTAT();
		array[i].calculateWT();
	}
 
}*/
void print(scheduling array[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<array[i].pid<<setw(20)<<array[i].at<<setw(20)<<array[i].bt<<setw(20)<<array[i].ct<<setw(20)<<array[i].tat<<setw(20)<<array[i].wt<<endl<<endl;
	}
}


#include <iostream>
#include <iomanip>
#include "prrn.h"

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

void sort(scheduling array[], int m, int n, int ct)
{
	if (array[m].at<=ct)
	{
		for (int i = m+1; i < n; ++i)
		{
			if (array[i].priority>array[m].priority and array[i].at<=ct)
			{
				swap(array[i].at,array[m].at);
				swap(array[i].bt,array[m].bt);
                swap(array[i].priority,array[m].priority);
				swap(array[i].pid,array[m].pid);
			}
               else if ( array[i].priority== array[m].priority)
                        { 
                if( array[i].at< array[m].at and array[m].at<=ct)
                       {
                              swap(array[i].at,array[m].at);
				              swap(array[i].bt,array[m].bt);
                              swap(array[i].priority,array[m].priority);
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
void prn(scheduling array[], int n)
{
	array[0].ct=array[0].at+array[0].bt;
	array[0].calculateTAT();
	array[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sort(array,i,n,array[i-1].ct);
	}

}


void print(scheduling array[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(20)<<"Priority"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<array[i].pid<<setw(20)<<array[i].at<<setw(20)<<array[i].bt<<setw(20)<<array[i].priority<<setw(20)<<array[i].ct<<setw(20)<<array[i].tat<<setw(20)<<array[i].wt<<endl<<endl;
	}
int avg_tat=0, avg_wt=0;
for(int i=0;i<n;i++)
{
avg_tat=avg_tat + array[i].tat;
avg_wt=avg_wt + array[i].wt;
}
avg_tat= avg_tat/n;
avg_wt= avg_wt/n;

cout << "average TAT is  " << avg_tat << endl;
cout << "average wt is  " << avg_wt << endl;
}

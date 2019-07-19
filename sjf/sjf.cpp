#include <iostream>
#include <iomanip>
#include "sjf.h"

using namespace std;


void swap(int *a, int *b)
{
int temp= *a;
*a=*b;
*b=temp;
}



void sort(schudeling array[], int m, int n, int ct)
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

void sjf(schudeling array[], int n)
{
	array[0].ct=array[0].at+array[0].bt;
	array[0].calculateTAT();
	array[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sort(array,i,n,array[i-1].ct);
	}

}


void print(schudeling array[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<array[i].pid<<setw(20)<<array[i].at<<setw(20)<<array[i].bt<<setw(20)<<array[i].ct<<setw(20)<<array[i].tat<<setw(20)<<array[i].wt<<endl<<endl;
	}
}


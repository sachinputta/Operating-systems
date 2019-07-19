#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <sstream>
#include "srt.h"

using namespace std;
bool isDone(process obj[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		if(obj[i].rt!=0)
			return false;
	}
	return true;
}

int findMinPid(process obj[], int n, int time)
{
	int minPid=0;
	for (int i = 1; i < n; ++i)
	{
		while (!obj[minPid].visited)
		{
			minPid++;
		}

		if (obj[i].rt!=0 and obj[i].at<=time)
		{
			if (obj[i].rt<obj[minPid].rt)
			{
				minPid=i;
			}
			else if(obj[i].rt==obj[minPid].rt)
			{
				if(obj[i].at<obj[minPid].at)
					minPid=i;
				else if(obj[i].at==obj[minPid].at and obj[i].pid<obj[minPid].pid)
				{
					minPid=i;
				}
			}
		}
	}
	return minPid;
}

void srt(process obj[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int m = 0; m < n; ++m)
		{
			
				if (obj[i].at<obj[m].at)
				{
					int temp=obj[i].at;
					obj[i].at=obj[m].at;
					obj[m].at=temp;

					temp=obj[i].bt;
					obj[i].bt=obj[m].bt;
					obj[m].bt=temp;

					temp=obj[i].pid;
					obj[i].pid=obj[m].pid;
					obj[m].pid=temp;

					temp=obj[i].rt;
					obj[i].rt=obj[m].rt;
					obj[m].rt=temp;
				}
				if (obj[i].at==obj[m].at and obj[i].pid<obj[m].pid)	
				{
					int temp=obj[i].at;
					obj[i].at=obj[m].at;
					obj[m].at=temp;

					temp=obj[i].bt;
					obj[i].bt=obj[m].bt;
					obj[m].bt=temp;

					temp=obj[i].pid;
					obj[i].pid=obj[m].pid;
					obj[m].pid=temp;

					temp=obj[i].rt;
					obj[i].rt=obj[m].rt;
					obj[m].rt=temp;
				}
			
		}
	}
	int ct;

	int time=obj[0].at;
	obj[0].rt--;
	
	time++;
	cout<<endl<<endl<<"P"<<obj[0].pid<<obj[0].rt<<setw(20)<<setw(5)<<endl;
	
	if (obj[0].rt==0)
	{
		obj[0].ct=time;
		obj[0].visited=false;
	}

	while(!isDone(obj,n))
	{
		int minPid=findMinPid(obj,n, time);
		while(obj[minPid].at>time)
		{
			time++;
		}
		obj[minPid].rt--;
		time++;
		if (obj[minPid].rt==0)
		{
			obj[minPid].ct=time;
			obj[minPid].visited=false;
		}
		
	}
	cout<<endl<<endl;
	for (int i = 0; i < n; ++i)
	{
		obj[i].calculateTAT();
		obj[i].calculateWT();
	}
	printrt(obj,n);
}

float averageWT(process obj[], int n)
{
	float sum=0.0;
	for (int i = 0; i < n; ++i)
	{
		sum=sum+obj[i].wt;
	}
	return sum/n;
}

void print(process obj[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<obj[i].pid<<setw(20)<<obj[i].at<<setw(20)<<obj[i].bt<<setw(20)<<obj[i].ct<<setw(20)<<obj[i].tat<<setw(20)<<obj[i].wt<<endl<<endl;
	}
	cout<<"Average Waiting Time: "<<averageWT(obj,n)<<endl;
}

void printrt(process obj[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(19)<<"RT"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<obj[i].pid<<setw(20)<<obj[i].at<<setw(20)<<obj[i].bt<<setw(20)<<obj[i].rt<<setw(20)<<obj[i].ct<<setw(20)<<obj[i].tat<<setw(20)<<obj[i].wt<<endl<<endl;
	}
	cout<<"Average Waiting Time: "<<averageWT(obj,n)<<endl;
}



#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <string>
#include <sstream>
#include "newschedule.h"

using namespace std;

void fcfs(process obj[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (obj[i].at>obj[j].at)
			{
				int temp=obj[i].at;
				obj[i].at=obj[j].at;
				obj[j].at=temp;

				temp=obj[i].bt;
				obj[i].bt=obj[j].bt;
				obj[j].bt=temp;

				temp=obj[i].pid;
				obj[i].pid=obj[j].pid;
				obj[j].pid=temp;
			}
			if(obj[i].at==obj[j].at)
			{
				if (obj[i].bt>obj[j].bt)
				{
					int temp=obj[i].at;
					obj[i].at=obj[j].at;
					obj[j].at=temp;

					temp=obj[i].bt;
					obj[i].bt=obj[j].bt;
					obj[j].bt=temp;

					temp=obj[i].pid;
					obj[i].pid=obj[j].pid;
					obj[j].pid=temp;
				}
				if (obj[i].bt==obj[j].bt and obj[i].pid>obj[j].pid)
				{
					int temp=obj[i].at;
					obj[i].at=obj[j].at;
					obj[j].at=temp;

					temp=obj[i].bt;
					obj[i].bt=obj[j].bt;
					obj[j].bt=temp;

					temp=obj[i].pid;
					obj[i].pid=obj[j].pid;
					obj[j].pid=temp;
				}

			}
		}
	}
	obj[0].ct=obj[0].bt+obj[0].at;
	obj[0].calculateTAT();
	obj[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		if (obj[i].at>obj[i-1].ct)
		{
			obj[i].ct=obj[i].at+obj[i].bt;
		}
		else
		{
			obj[i].ct=obj[i-1].ct+obj[i].bt;
			
		}
		obj[i].calculateTAT();
		obj[i].calculateWT();
	}
}

void sort(process obj[], int m, int n, int ct)
{
	if (obj[m].at<=ct)
	{
		for (int i = m+1; i < n; ++i)
		{
			if (obj[i].bt<obj[m].bt and obj[i].at<=ct)
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
			}
			if(obj[i].bt==obj[m].bt and obj[i].at<=ct)
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
				}
			}
		}
		obj[m].ct=obj[m-1].ct+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
	else
	{
		obj[m].ct=obj[m].at+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
}

void sjf(process obj[], int n)
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
				}
			
		}
	}
	obj[0].ct=obj[0].at+obj[0].bt;
	obj[0].calculateTAT();
	obj[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sort(obj,i,n,obj[i-1].ct);
	}

}

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

void printpriority(process obj[], int n)
{
	cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(19)<<"Priority"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<obj[i].pid<<setw(20)<<obj[i].at<<setw(20)<<obj[i].bt<<setw(20)<<obj[i].priority<<setw(20)<<obj[i].ct<<setw(20)<<obj[i].tat<<setw(20)<<obj[i].wt<<endl<<endl;
	}
	cout<<"Average Waiting Time: "<<averageWT(obj,n)<<endl;
}

void printpriorityrt(process obj[], int n)
{
	cout<<"PID"<<setw(15)<<"AT"<<setw(15)<<"BT"<<setw(15)<<"Priority"<<setw(15)<<"RT"<<setw(15)<<"CT"<<setw(15)<<"TAT"<<setw(15)<<"WT"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<obj[i].pid<<setw(15)<<obj[i].at<<setw(15)<<obj[i].bt<<setw(15)<<obj[i].priority<<setw(15)<<obj[i].rt<<setw(15)<<obj[i].ct<<setw(15)<<obj[i].tat<<setw(15)<<obj[i].wt<<endl<<endl;
	}
	cout<<"Average Waiting Time: "<<averageWT(obj,n)<<endl;
}

void sort_priority(process obj[], int m, int n, int ct)
{
	if (obj[m].at<=ct)
	{
		for (int i = m+1; i < n; ++i)
		{
			if (obj[i].priority>obj[m].priority and obj[i].at<=ct)
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

				temp=obj[i].priority;
				obj[i].priority=obj[m].priority;
				obj[m].priority=temp;
			}
			
		}
		obj[m].ct=obj[m-1].ct+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
	else
	{
		obj[m].ct=obj[m].at+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
}


void priority_np(process obj[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int m = i+1; m < n; ++m)
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

					temp=obj[i].priority;
					obj[i].priority=obj[m].priority;
					obj[m].priority=temp;
				}
				if (obj[i].at==obj[m].at and obj[i].priority<obj[m].priority)	
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

					temp=obj[i].priority;
					obj[i].priority=obj[m].priority;
					obj[m].priority=temp;
				}
			
		}
	}
	obj[0].ct=obj[0].at+obj[0].bt;
	obj[0].calculateTAT();
	obj[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sort_priority(obj,i,n,obj[i-1].ct);
	}
}

void sortHRRN(process obj[], int m, int n, int ct)
{
	if (obj[m].at<=ct)
	{
		for (int i = m+1; i < n; ++i)
		{
			if (obj[i].findRR(ct)>obj[m].findRR(ct) and obj[i].at<=ct)
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
			}
			else if(obj[i].findRR(ct)==obj[m].findRR(ct) and obj[i].at<=ct)
			{
				if (obj[i].pid<obj[m].pid)	
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
				}
			}
		}
		obj[m].ct=obj[m-1].ct+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
	else
	{
		obj[m].ct=obj[m].at+obj[m].bt;
		obj[m].calculateTAT();
		obj[m].calculateWT();
	}
}

void HRRN(process obj[], int n)
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
				}
			
		}
	}
	obj[0].ct=obj[0].at+obj[0].bt;
	obj[0].calculateTAT();
	obj[0].calculateWT();
	for (int i = 1; i < n; ++i)
	{
		sortHRRN(obj,i,n,obj[i-1].ct);
	}

}

void RoundRobin(process obj[], int n, int tq)
{

}

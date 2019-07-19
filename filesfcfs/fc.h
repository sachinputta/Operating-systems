#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

class fcfs
{
  public:
        int pid,at,bt,wt,tat,ct;
};   

void fcfs1(class fcfs p[],int n)
{
 
 class fcfs a[n],temp;
  int min,loc;
 for(int i=0;i<n;i++)
{
    a[i]=p[i];
}

    for(int i=0;i<n-1;i++)
    {
        min=a[i].at;
        loc=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>a[j].at)
            {
                min=a[j].at;
                loc=j;
            }
        else if(min==a[j].at)
         {
                if(a[j].pid<a[loc].pid)
       loc=j;
          }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 
int w=a[0].bt+a[0].at;
 a[0].wt=0;
 
for(int i=1;i<n;i++)
  {
       a[i].wt=w-a[i].at;
       w+=a[i].bt;
}

for(int i=0;i<n;i++)
{
    a[i].tat=a[i].wt+a[i].bt;
    a[i].ct=a[i].at+a[i].tat;
}

cout<<"PID"<<setw(19)<<"AT"<<setw(19)<<"BT"<<setw(20)<<"CT"<<setw(20)<<"TAT"<<setw(20)<<"WT"<<endl;
for(int i=0;i<n;i++)
{  
   cout<<a[i].pid<< setw(20) <<a[i].at<<setw(20)<<a[i].bt<<setw(20)<<a[i].wt<<setw(20)<<a[i].tat<<setw(20)<<a[i].ct<<endl;

}

}

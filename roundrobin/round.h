#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class roundd
{
public:
int pid;
int at;
int bt;
int wt,tat,ct;
int originalbt;
};

void robin(class roundd pround[], int n, int time)
{
class roundd q[50];
int f,r;
f=-1;
r=-1;
int min,change;
class roundd a[50],swap;

for(int i=0;i<n;i++)
{
  a[i]=pround[i];
}
//Sorting according to arrival time
for(int i=0;i<n-1;i++)
{
        min=a[i].at;
        change=i;
        for(int j=i+1;j<n;j++)
        {
          if(a[j].at<min)
          {
          min=a[j].at;
          change=j;
          }
        }
 swap=a[i];
 a[i]=a[change];
 a[change]=swap;
}
int initial=a[0].at;
q[++f]=a[0];
q[++r]=a[0];
int newl=1;
cout<<"pid          at              bt               wt            tat            ct"<<endl;
//unless the queue never ends
while(f<=r)
{
          
          if(q[f].bt<=time)
          {
          initial=initial +q[f].bt;  //initial is kind off completion time after each process executed
          q[f].ct=initial;
          q[f].tat=q[f].ct-q[f].at;
          q[f].wt=q[f].tat-q[f].bt;
          cout<<q[f].pid<<setw(15)<<q[f].at<<setw(15)<<q[f].bt<<setw(15)<<q[f].wt<<setw(15)<<q[f].tat<<setw(15)<<q[f].ct<<endl;
          q[f].bt=0;
          }
          else
          {
          initial=initial+time;
          cout<<q[f].pid<<setw(15)<<q[f].at<<setw(15)<<q[f].bt<<endl;
          q[f].bt=q[f].bt-time;
          }
                 while( (a[newl].at<=initial) && newl<n)  /*loop actually checks all the processes whose arrival time is less than 
                                                        previous completion process*/ 
                 {
                 q[++r]=a[newl++]; //Adds those processes on the queue sequentially
                 }
                 if(q[f].bt>0)
                 {
                 q[++r]=q[f];
                 }
 f++;
}




int avg_tat=0, avg_wt=0;
for(int i=0;i<n;i++)
{
avg_tat=avg_tat + a[i].tat;
avg_wt=avg_wt + a[i].wt;
}
avg_tat= avg_tat/n;
avg_wt= avg_wt/n;

cout << "average turn around time" << avg_tat << endl;
cout << "average waiting time" << avg_wt << endl;
         
}
        


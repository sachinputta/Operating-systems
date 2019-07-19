#include<iostream>
#include<cstdlib>

using namespace std;

class srtf
{
  public:
        int pid,at,bt,wt,tat,ct,i_bt;
};   

void srtf1(class srtf p[],int n)
{
 
class srtf a[n],temp;
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
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 


  
int max_bt=a[0].bt;
for(int i=1;i<n;i++)
 if(a[i].bt>max_bt)
     max_bt=a[i].bt;
 
int s=0,u; 
  cout<<"pid at bt wt tat ct"<<endl;
 //cout<<"pid at bt"<<endl;


for(int i=1;i<n;i++)
{        min=max_bt;
  for(int j=0;j<i;j++)
         {  
            if((a[j].bt<min)&&(a[j].bt>0))
             {
               min=a[j].bt;
               loc=j;}

           else if(a[j].bt==min)
             {
                if(a[j].at<a[loc].at)
                  {
                    min=a[j].bt;
                     loc=j;
                  }
             }
          }   
               
             a[loc].bt=a[loc].bt-(a[i].at-a[i-1].at);
                if(a[loc].bt< 0)
                     a[loc].bt=0;
         
             
              if(a[loc].bt==0)
              { a[loc].ct=a[i].at;
                a[loc].tat=a[loc].ct-a[loc].at;
                a[loc].wt=a[loc].tat-a[loc].i_bt;
              cout<<a[loc].pid<<"   "<<a[loc].at<<"  "<<a[loc].bt<<"  "<<a[loc].wt<<"  "<<a[loc].tat<<"   "<<a[loc].ct<<endl;}
            else
            cout<<a[loc].pid<<"   "<<a[loc].at<<"  "<<a[loc].bt<<endl;
}
int f=a[n-1].at;

cout<<"after all the processes has arrived we sort according to shortest job next:non preemptive"<<endl;

  for(int i=0;i<n-1;i++)
    {  
        if(a[i].bt>0)
        {
           min=a[i].bt;
           loc=i;
           for(int j=i+1;j<n;j++)
           {  
              if((a[j].bt<min)&&(a[j].bt>0))
              {
               min=a[j].bt;
               loc=j;
              }

              else if(a[j].bt==min)
              {
                 if(a[j].at<a[loc].at)
                  {
                    min=a[j].bt;
                     loc=j;
                  }
              }
            }
  
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
        }
    }

int w=0;
for(int i=0;i<n;i++)
{  if(a[i].bt>0)
   {  a[i].ct=f+w+a[i].bt;
      a[i].tat=a[i].ct-a[i].at;
      a[i].wt=a[i].tat-a[i].i_bt;
      cout<<a[i].pid<<"   "<<a[i].at<<"  "<<a[i].bt<<"  "<<a[i].wt<<"  "<<a[i].tat<<"   "<<a  [i].ct<<endl;
      w+=a[i].bt;
}
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

 
/*for(int i=1;i<n;i++)
  { 
       a[i].wt=w-a[i].at;
       w+=a[i].bt;
}

for(int i=0;i<n;i++)
{
    a[i].tat=a[i].wt+a[i].bt;
    a[i].ct=a[i].at+a[i].tat;
}

 cout<<"pid at bt wt tat ct"<<endl;
for(int i=0;i<n;i++)
{  
   cout<<a[i].pid<<"   "<<a[i].at<<"  "<<a[i].bt<<"  "<<a[i].wt<<"  "<<a[i].tat<<"   "<<a[i].ct<<endl;

}*/

}

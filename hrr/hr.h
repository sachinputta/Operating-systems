#include<iostream>
#include<cstdlib>

using namespace std;

class hrr
{
  public:
        float pid,at,bt,wt,tat,ct,rr;
}; 


void hrr1(class hrr p[],int n)
{
  
 class hrr a[n],temp;
  int loc,u=0,t=0;
 for(int i=0;i<n;i++)
{
    a[i]=p[i];
}

    for(int i=0;i<n-1;i++)
    {
       float  min=a[i].at;
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


float w=a[0].at;
 
 cout<<"pid at bt wt tat ct"<<endl;
 

int k=0;

while(k<n)
{
float max=0;int i=0;

while((a[i].at<=w)&&(i<n))
{ 
float s=a[i].bt;
a[i].rr=((w-a[i].at)+s)/s;
if((a[i].bt!=0)&&(a[i].rr>max))
{
  max=a[i].rr;
  loc=i;
}

  i++;
}

a[loc].wt=w-a[loc].at;
a[loc].tat=a[loc].wt+a[loc].bt;
a[loc].ct=a[loc].at+a[loc].tat;


u+=a[loc].wt;
t+=a[loc].tat; 
cout<<a[loc].pid<<"   "<<a[loc].at<<"  "<<a[loc].bt<<"  "<<a[loc].wt<<"  "<<a[loc].tat<<"   "<<a[loc].ct<<" "<<endl;
w+=a[loc].bt;
a[loc].bt=0;
k++;
}

float m=n;
cout<<"average waiting time:"<<(u/m)<<endl;
cout<<"average turn around time:"<<(w/m)<<endl;

}

#include <iostream>
#include <cstdlib>
#include "round.h"

using namespace std;
int main(void)
{
   
   int n,time;
   cout<<"enter number of process"<<endl;
   cin>>n;
  cout<<"enter the time quantum"<<endl;
  cin>>time;
   class roundd process[n];
for(int i=0;i<n;i++)
 {    process[i].pid=i+1;
    cout<<"enter the at and bt for process "<<i+1<<endl;
     cin>>process[i].at>>process[i].bt;
     process[i].originalbt=process[i].bt;
   cout<<endl;  
}   

 robin(process,n,time);
}

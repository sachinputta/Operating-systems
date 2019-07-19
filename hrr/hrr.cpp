#include<iostream>
#include<cstdlib>
#include "hr.h"


int main(void)
{
   
   int n;
   cout<<"enter number of process"<<endl;
   cin>>n;
   class hrr process[n];
for(int i=0;i<n;i++)
 {    process[i].pid=i+1;
    cout<<"enter the at and bt for process "<<i+1<<endl;
     cin>>process[i].at>>process[i].bt;
   cout<<endl;  
}   

 hrr1(process,n);
}

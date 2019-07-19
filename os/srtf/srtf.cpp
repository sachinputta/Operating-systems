#include<iostream>
#include<cstdlib>
#include "sr.h"

using namespace std;

int main()
{
   
   int n;
   cout<<"enter number of process"<<endl;
   cin>>n;
   class srtf process[n];
for(int i=0;i<n;i++)
 {    process[i].pid=i+1;
    cout<<"enter the at and bt for process "<<i+1<<endl;
     cin>>process[i].at>>process[i].bt;
     process[i].i_bt=process[i].bt;
   cout<<endl;  
}   

 srtf1(process,n);
}

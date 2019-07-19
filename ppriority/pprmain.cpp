#include<iostream>
#include<cstdlib>
#include "p.h"

using namespace std;
int main(void)
{
   
   int n;
   cout<<"enter number of process"<<endl;
   cin>>n;
   class pp process[n];
for(int i=0;i<n;i++)
 {    process[i].pid=i+1;
    cout<<"enter the at and bt for process and priority number "<<i+1<<endl;
     cin>>process[i].at>>process[i].bt>>process[i].pno;
     process[i].i_bt=process[i].bt;
   cout<<endl;  
}   

 pp1(process,n);
}

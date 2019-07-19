#include<iostream>
#include<stdlib.h>

using namespace std;

class pp
{
   public:
           int pid, at, bt, pno, wt,tat, ct, i_bt;
};

void pp1(class pp p[], int n)
{
class pp a[n], temp;
int min,loc,max;
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
}


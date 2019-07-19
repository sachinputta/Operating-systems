#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>
#include "fc.h" 

using namespace std;


int main(void)
{
   
   int n=6;
char str[100];
   
   class fcfs process[n];
for(int i=0;i<n;i++)
 {    process[i].pid=i+1;
    cout<<"enter the at of process"<<i+1<<endl;
     cin>>process[i].at;
  process[i].bt=0;
   cout<<endl;  
} 

int i=0;


ifstream fin;
fin.open("a.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
i++;

fin.open("b.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
i++;

fin.open("d.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
i++;

fin.open("e.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
i++;

fin.open("f.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
i++;

fin.open("g.txt");
while(!fin.eof())
{
fin.getline(str,100);
process[i].bt++;
}
fin.close();
fcfs1(process,n);
}

#include <iostream>
#include "safcfs.cpp"
using namespace std;
int main()
{
	int n;
	cout<<"enter the number of processes:";
	cin>>n;
	scheduling array[n];
	for(int i=0;i<n;i++) 
	{
	cout<<"enter the at and bt";
	array[i].pid=i+1;
	cin>>array[i].at>>array[i].bt;
	} 
	cout<<"FCFS"<<endl;
	fcfs(array,n);
        print(array, n);
        
	return 0;
}

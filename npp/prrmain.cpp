#include <iostream>
#include "np.cpp"
using namespace std;
int main()
{
	int n;
	cout<<"enter the number of processes:";
	cin>>n;
	scheduling array[n];
	for(int i=0;i<n;i++) 
	{
	cout<<"enter the at and bt and priority";
	array[i].pid=i+1;
	cin>>array[i].at>>array[i].bt>> array[i].priority;
	} 
	/*cout<<"FIRST COME FIRST SERVE"<<endl;
	fcfs(array,n);
        print(array, n);*/
        cout<<"Np  priority scheduling"<<endl;
        prn(array,n);
        print(array, n);

	return 0;
}

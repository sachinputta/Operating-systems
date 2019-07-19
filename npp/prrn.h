#include <iostream>
#include <cstdlib>

using namespace std;

class scheduling
{
public:
	int at,bt,ct,tat,wt,pid, priority;
	
	void calculateTAT()
	{
		tat=ct-at;
	}
	void calculateWT()
	{
		wt=tat-bt;
	}
	
};
void fcfs(scheduling array[],int n);                                          

void prn(scheduling array[],int n);

void print(scheduling array[], int n);

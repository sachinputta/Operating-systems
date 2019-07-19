
#ifndef FCFS 
#define FCFS

class scheduling
{
public:
	int at,bt,ct,tat,wt,pid;
	
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

void sjf(scheduling array[],int n);

void print(scheduling array[], int n);


#endif

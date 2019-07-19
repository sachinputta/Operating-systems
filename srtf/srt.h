#include <iostream>
#ifndef SCHEDULE_H
#define SCHEDULE_H


class process
{
public:
	int at,bt,ct,tat,wt,pid,rt;
	int priority;
	bool visited;
	
	void calculateTAT()
	{
		tat=ct-at;
	}
	void calculateWT()
	{
		wt=tat-bt;
	}
	
	
};
void srt(process obj[], int n);
void print(process obj[], int n);

void printrt(process obj[], int n);
#endif
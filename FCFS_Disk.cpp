#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n;
	cout<<"enter the number of sectors in work queue";
	cin>>n;
	int minsec,maxsec,nosec,seclist[n],currpos,total_head_movement=0;
	cout<<"Enter no. of sectors";
	cin>>nosec;
	minsec=0;
	maxsec=minsec+nosec-1;
	cout<<"Enter current position of diskhead";
	cin>>currpos;
	cout<<"enter the sector numbers in work queue";
	for(int i=0;i<n;i++)
	{
		cin>>seclist[i];
	}
	int i=0;
	do
	{
		
	total_head_movement+=abs(currpos-seclist[i]);
	currpos=seclist[i];
	i++;	
		
	}while(i<n);
	cout<<endl;
	cout<<"Total head movement="<<	total_head_movement<<endl;
	return 0;
}

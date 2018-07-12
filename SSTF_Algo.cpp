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
	int i=0,diff[n],flag[n],count;
	
		for(int i=0;i<n;i++)
	{
	   
	     flag[i]=0;
	}
		cout<<endl<<"Here is sequence of sectors accesses "<<"\t";
	while(1)
	{
	
	for(int i=0;i<n;i++)
	{	   
	     diff[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		
		
		diff[i]=abs(currpos-seclist[i]);
				
	    
	}
	int min,index;
	for(int t=0;t<n;t++)
	{
		if(flag[t]!=1&&diff[t]!=0)
		{
			min=diff[t];
			index=t;
			break;
		}
	}
	
	for(int t=1;t<n;t++)
	{
		if(flag[t]!=1&&diff[t]!=0)
		{
			if(diff[t]<min)
			{
			min=diff[t];
			index=t;
				
			}
		}
	}
	cout<<seclist[index]<<"\t";
	total_head_movement+=abs(currpos-seclist[index]);
	currpos=seclist[index];
	flag[index]=1;
	count=0;

	for(int t=0;t<n;t++)
	{
		if(flag[t]==1)
		{
			count++;
		}
	}
	
	if(count==n)
	{
		break;
	}
	
	
    }
	cout<<endl;
	cout<<"Total head movement="<<	total_head_movement<<endl;
	return 0;
}

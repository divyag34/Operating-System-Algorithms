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
	
	int minseclist=seclist[0];
	
	for(int i=1;i<n;i++)
	{
		if(seclist[i]<minseclist)
		{
			minseclist=seclist[i];
		}
	}
	int i=0,diff[n],flag[n],count;
	
		for(int i=0;i<n;i++)
	{
	   
	     flag[i]=0;
	}
		cout<<endl<<"Here is sequence of sectors accesses "<<"\t";
		
		i=currpos;
		while(1)
		{
			for(int t=0;t<n;t++)
			{
				if(seclist[t]==i)
				{
				total_head_movement+=abs(currpos-i);
				currpos=i;
				flag[t]=1;	
				cout<<seclist[t]<<"\t";
				}
			}
		
		if(i==minseclist)
		{
	
		currpos=i;
	
		
		break;	
		}	
		
		i--;	
			
		}
		i=currpos;
		while(1)
		{
			int count=0;
			
			for(int t=0;t<n;t++)
			{
				if(seclist[t]==i&&flag[t]!=1)
				{
				total_head_movement+=abs(currpos-i);
				currpos=i;
				flag[t]=1;	
				cout<<seclist[t]<<"\t";
				}
			}
			
			i++;
			for(int t=0;t<n;t++)
			{
				if(flag[t]==1)
				{
					count++;
				}	
							
			}
			if(count==n||i==maxsec)
			{
				break;
			}
			}
			cout<<endl<<"Total head movement= "<<total_head_movement;
			return 0;
			
		}
		
		

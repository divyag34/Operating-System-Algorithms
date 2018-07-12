#include<iostream>
using namespace std;


int main()
{
	int n,m;
	cout<<"enter number of memory partitions";
	cin>>m;
	int mempartitions[m];
	cout<<"Enter size of memory blocks"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>> mempartitions[i];
	}
	cout<<"Enter number of processes";
	cin>>n;
	int processesmem[n];
	cout<<"Enter memory blocks of processes"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cin>>processesmem[i];
	}
	cout<<"Using Worst Fit"<<endl;
	int i=0;
	do{
		int temp=processesmem[i],diff[m];
		int flag=0;
		for(int j=0;j<m;j++)
		{
		
		diff[j]=0;	
				
		}
		
		for(int j=0;j<m;j++)
		{
		
			if(temp<=mempartitions[j])
			{
				diff[j]=mempartitions[j]-temp;
			    flag=1;	
				
			}
			
				
		}
		int max,index;
		for(int j=0;j<m;j++)
		{
		 
			if(diff[j]!=0)
			{
				max=diff[j];
				index=j;
				break;
			}
			
				
		}
		
		
		for(int j=1;j<m;j++)
		{
           if(diff[j]!=0)
		   {
		   		 
			if(diff[j]>max)
			{
				max=diff[j];
				index=j;
				
			}
			
		   }
		}
		if(flag==1)
		{		
		cout<<temp<<"k placed in "<<mempartitions[index]<<"k partition"<<endl;
		mempartitions[index]=mempartitions[index]-temp;
     	}
			
		  else
			{
				cout<<temp<<"k process must wait"<<endl;
			}
		i++;
    }while(i<n);
	
	return 0;
}

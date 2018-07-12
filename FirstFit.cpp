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
	cout<<"Using First Fit"<<endl;
	int i=0;
	do{
		int temp=processesmem[i];
		int flag=0;
		for(int j=0;j<m;j++)
		{
		
			if(temp<=mempartitions[j])
			{
				cout<<temp<<"k"<<" placed in "<<mempartitions[j]<<"k"<<endl;
				mempartitions[j]-=temp;
				flag=1;
				break;
			}
			
				
		}
		if(flag!=1)
			{
				cout<<temp<<"k process must wait"<<endl;
			}
		i++;
    }while(i<n);
	
	return 0;
}

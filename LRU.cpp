#include<iostream>
using namespace std;





int refstring[20],pgframe[80],front=-1,rear=-1,no_of_page_faults=0,qsize=0;

int isFull(int n)
{
	if(qsize==n)
	return(1);
	else
	return(0);
		
}

void replacepg(int pagefault,int n,int index)
{
	int diff[80];

	cout<<"\n";
	
	int t=0;
	do 
	{
		for(int j=index;j>=0;j--)
		{
			if(refstring[j]==pgframe[t])
			{
				diff[t]=j;
				break;
			}
		}
		t++;
	}while(t<n);
	

	
	int small=diff[0],replace=0;
	
	for(int t=1;t<n;t++)
	{
		if(small>diff[t])
		{
	     small=diff[t];
	     replace=t;
		}
	}
	
	pgframe[replace]=pagefault;
	cout<<"\n";	
	cout<<"After replacement page frames :-"<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<pgframe[i]<<"\n";
	}
	cout<<"\n";
}


void Enqueue(int page,int n,int index)

{
	cout<<"\n";
	cout<<"Page required ="<<page<<endl;
	cout<<"Current page frames :-"<<"\n";
	for(int i=0;i<qsize;i++)
	{
		cout<<pgframe[i]<<"\n";
	}
	
	if(isFull(n))
	{
		replacepg(page,n,index);
	}
   else
   {
   	
   	if(front==-1&&rear==-1)
   	{   rear++;
   		front=rear;
   	}
   	pgframe[rear++]=page;
   	qsize++;
   	cout<<"\n"<<"After replacement page frames :-"<<"\n";
	for(int i=0;i<qsize;i++)
	{
		cout<<pgframe[i]<<"\n";
	}
	cout<<"\n";	
       	
   }
     
}


int main()
{
	int n;
    cout<<"Enter number of frames";
    cin>>n;
	int i,j;
	cout<<"\n"<<"Enter number of refrence string"<<"\n";
	for(i=0;i<20;i++)
	{
		cin>>refstring[i];
	}
cout<<"Using LRU Replacement algorithm"<<"\n";
	
	for(i=0;i<n;i++)
	{
		pgframe[i]=-1;
	}
	
	
	
	
	i=0;
	do
	{
		int flag=1;

		
		for(j=0;j<n;j++)
		{
			
			if(pgframe[j]!=refstring[i])
			{
				flag=0;
			}
			else
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
			no_of_page_faults++;
			Enqueue(refstring[i],n,i);
		}
	i++;
	}while(i<20);
	
	cout<<"\n"<<"Number of page faults="<<no_of_page_faults;
	return 0;
}


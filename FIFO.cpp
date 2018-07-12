#include<iostream>
using namespace std;

int refstring[20],pgframe[80],front=-1,rear=-1,no_of_page_faults=0,qsize=0;
void swap(int a ,int b )
{
int temp;
temp=a;
a=b;
b=temp;
}
int isFull(int n)
{
	if(qsize==n)
	return(1);
	else
	return(0);
		
}

void replacepg(int pagefault,int n)
{
	cout<<"Page required ="<<pagefault<<endl;
	cout<<"Current page frames :-"<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<pgframe[i]<<"\n";
	}
	cout<<"\n";
	pgframe[front]=pagefault;
	int f=front+1;
	front=f%n;
	cout<<"After replacement page frames :-"<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<pgframe[i]<<"\n";
	}
	cout<<"\n";
}
	
void Enqueue(int page,int n)
{
	
	if(isFull(n))
	{
		replacepg(page,n);
	}
   else
   {
   	
   	if(front==-1&&rear==-1)
   	{   rear++;
   		front=rear;
   	}
   	pgframe[rear++]=page;
   	qsize++;
       	
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
cout<<"Using FIFO Replacement algorithm"<<"\n";
	
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
			Enqueue(refstring[i],n);
		}
	i++;
	}while(i<20);
	
	cout<<"\n"<<"Number of page faults="<<no_of_page_faults;
	return 0;
}

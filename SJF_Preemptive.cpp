#include<iostream>
using namespace std;
struct process
{
	int pid,at,rembt,bt,tt,wt;
};

void sort1(struct process *t,int p)
{
int i,j;
struct process *q,s;

for(i=0;i<p;i++,t++)
{
for(j=i+1,q=t+1;j<p;j++,q++)
{
 if((t->at)>(q->at))
 {
 s=*t;
 *t=*q;
 *q=s;
 }
 }
}
}

int main()
{
	int n,count=0;
	struct process p[80];
	int at,bt;
	cout<<"Enter number of processes";
	cin>>n;
	for (int i=0;i<n;i++)
      {
      	cout<<"for process"<<i+1<<"\n";
      	cout<<"pid";
      	cin>>p[i].pid;
      	cout<<"at";
      	cin>>p[i].at;
      	cout<<"bt";
      	cin>>p[i].bt;
      	p[i].rembt=p[i].bt;
      }	
      sort1(p,n);
      
      for(int time=0;count!=n;time++)
      {
      	int small=0;
      	
      	for(int j=1;j<n;j++)
      	{
      		if(p[j].at<=time&&p[j].rembt<=p[small].rembt&&p[j].rembt>0)
      		{
      			small=j;
      		}
      	}
      	
      	p[small].rembt--;
      	if(p[small].rembt==0)
      	{
      		count++;
      		int t=time+1;
      		p[small].tt=t-p[small].at;
      		p[small].wt=p[small].tt-p[small].bt;
      	}
      	
      }
              
  	cout<<"ProcessId\t"<<"Arrival time\t"<<"Burst time\t"<<"Waiting Time\t"<<"Turnaround Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tt<<"\n";
	}
	return 0;
}

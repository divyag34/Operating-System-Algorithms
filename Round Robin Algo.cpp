#include <iostream>
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
	int n;
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
  int q=2;

  cout<<"\n"<<"Quantum= "<<q;
  int t=0;
  while(1)
  {
  	int flag=1;

  	for(int i=0;i<n;i++)
  	{

  		if(p[i].rembt>0)
  	    {

  	    flag=0;

  		if(p[i].rembt>q)
           {
           	t=t+q;
           }
  		else
  		{
  			t=t+p[i].rembt;
  			p[i].tt=t-p[i].at;
  			p[i].wt=p[i].tt-p[i].bt;
  			p[i].rembt=0;
  		}
  	}

  	}
  	if(flag==1)
  		{
  			break;
  		}

  	}




  	cout<<"ProcessId\t"<<"Arrival time\t"<<"Burst time\t"<<"Waiting Time\t"<<"Turnaround Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tt<<"\n";
	}
	return 0;
}

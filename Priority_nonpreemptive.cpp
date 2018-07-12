#include<iostream>
using namespace std;
struct Process
{
	int pid,at,flag,bt,wt,tt,ct,prt;
};
void swap(struct Process *t ,struct Process *w )
{
struct Process v;
v=*t;
*t=*w;
*w=v;
}
 void sort1(struct Process *t,int p)
{
int i,j;
struct Process *q,s;

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


void sort2(struct Process *t,int p)
{
int i,j;
struct Process *q,s;
if(t->pid==p)
{
	return;
}
for(i=1;i<p;i++,t++)
{
for(j=i+1,q=t+1;j<p;j++,q++)
{
 if((t->prt)>(q->prt))
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
	struct Process p[80];
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
      	cout<<"pt";
      	cin>>p[i].prt;
      }	
      
      for(int i=0;i<n;i++)
      {
      	p[i].flag=0;
      }
	sort1(p,n);
	p[0].wt=0;
	p[0].ct=p[0].bt;
	p[0].tt=p[0].ct;
	p[0].flag=1;
	
    

	
	int t=1;
	do{
	
	int diff=p[t].at-p[t-1].ct;
	if(diff<=0)
	{
	  sort2(&p[t],n);	
	  for( int i=t+1;i<n;i++)
	  {
	  	if(p[t].prt==p[i].prt&&p[i].at<p[t].at)
	  	{
	  		swap(&p[t],&p[i]);
	  		break;
	  	}
	  	
	  }
	  
	  p[t].ct=p[t-1].ct+p[t].bt;
	  p[t].tt=p[t].ct-p[t].at;
	  p[t].wt=p[t].tt-p[t].bt;
	}
	
	else
	{
		p[t].ct=p[t].at+p[t].bt;
		p[t].tt=p[t].ct-p[t].at;
		p[t].wt=0;
		sort2(&p[t+1],n);
	}
	t++;
		
	}	while(t < n);
	cout<<"ProcessId\t"<<"Arrival time\t"<<"Priority\t"<<"Burst time\t"<<"Waiting Time\t"<<"Turnaround Time\n";
	for(int i=0;i<n;i++)
	{
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].prt<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tt<<"\n";
	}
	
	return 0;
}



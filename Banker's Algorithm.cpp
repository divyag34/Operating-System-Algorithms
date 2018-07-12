#include<iostream>
using namespace std;
//Banker's Algorithm Implementation
int main()
{
	int num_resources,num_processes;
	cout<<"Enter number of resources =";
	cin>>num_resources;
	cout<<"Enter number of processes =";
	cin>>num_processes;
	int r=num_resources,p=num_processes;
	int allocation[p][r],max[p][r],need[p][r],available[r],finish[p],safeseq[p];
	int t=0,n=0;
   //Safety Alghorithm
	cout<<"enter the maximum resources by the processes (Max Matrix)\n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cin>>max[i][j];
		}
	}

	for(int i=0;i<p;i++)
	{
	finish[i]=0;
	}



	cout<<"enter the allocation of resources to processes (Allocation matrix)\n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cin>>allocation[i][j];
		}
	}

	cout<<"Need matrix "<<"\n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}

		for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<need[i][j]<<"\t";
		}
		cout<<"\n";
	}



	cout<<"Enter the available resources ( Resource Vector )\n";
	for(int t=0;t<r;t++)
	{
		cin>>available[t];
	}

	cout<<"\n"<<"The safe sequence is"<<"\t";
	while(1)
	{
    int req_process=0;
	for(int i=0;i<p;i++)
	{
		int c=0;
		for(int j=0;j<r;j++)
		{
			if(need[i][j]<=available[j]&&finish[i]!=1)
			{
				c++;
			}

		}
		if(c==r)
			{
              	safeseq[t++]=i;
				  n++;
				  req_process++;
			  for(int j=0;j<r;j++)
	         	{

				 available[j]+=allocation[i][j];
				 finish[i]=1;

			    }



	        }

		}

            int count=0;
			for(int i=0;i<p;i++)
			{
				if(finish[i]==1)
				{
					count++;
				}
			}

			if(count==p||req_process==0)
			{
				break;
			}




    }

    if(n==p)
	{
	 cout<<"\n"<<"The safe sequence is"<<"\t";
	for(int i=0;i<p;i++)
	{
	cout<<"P"<<safeseq[i]<<"\t";
	}

    }

    else
    {
     cout<<"\n"<<"The safe sequence doesn't exist'"<<"\n";
    }
    //Resource Request Algorithm
	char ch;
	int id,request[r];
	cout<<"\n"<<"want to request resource? y/n";
	cin>>ch;
	if(ch=='y'||ch=='Y')
	{
		t=0;
		n=0;
		cout<<"enter the process number for which request of resources are there";
		cin>>id;
		cout<<"Enter the number of resources requested ( request vector )\n ";
	    	for(int i=0;i<r;i++)
	       {
	           	cin>>request[i];
	       }


	  cout<<"Enter the available resources (Available Vector)\n";
	for(int t=0;t<r;t++)
	{
		cin>>available[t];
	}

		for(int j=0;j<r;j++)
		{
	        if(request[j]<=need[id-1][j])
	        {
	        	if(request[j]<=available[j])
	        	{
	        		available[j]=available[j]-request[j];
	        		allocation[id-1][j]+=request[j];
	        		need[id-1][j]-=request[j];
	        	}
	        	else
                {

                    cout<<"Have to wait!!"<<"\n";
                }

	        }

	        else
	        {
	        	cout<<"\n"<<"Request exceed the need";
	        }
		}



	for(int i=0;i<p;i++)
	{
	finish[i]=0;
	}


	cout<<"Need matrix "<<"\n";

		for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<need[i][j]<<"\t";
		}
		cout<<"\n";
	}


	cout<<"\n"<<"Available resources"<<"\n";

	for(int i=0;i<r;i++)
	{
	cout<<available[i]<<"\t";
	}
	cout<<"\n"<<"Allocation matrix"<<"\n";

		for(int i=0;i<p;i++)
	  {
		for(int j=0;j<r;j++)
		{
			cout<<allocation[i][j]<<"\t";
		}
		cout<<"\n";
	  }


	while(1)
	{
     int req_process=0;
	for(int i=0;i<p;i++)
	{
		int c=0;

		for(int j=0;j<r;j++)
		{
			if(need[i][j]<=available[j]&&finish[i]!=1)
			{
				c++;

			}

		}

		if(c==r)
			{

              req_process++;
              safeseq[t++]=i;
					  n++;
			  for(int j=0;j<r;j++)
	         	{

				 available[j]+=allocation[i][j];
				 finish[i]=1;

			    }



	        }

		}

            int count=0;
			for(int i=0;i<p;i++)
			{
				if(finish[i]==1)
				{
					count++;
				}
			}

			if(count==p||req_process==0)
			{
				break;
			}




    }

	if(n==p)
	{
	 cout<<"\n"<<"The safe sequence is"<<"\t";
	for(int i=0;i<p;i++)
	{
	cout<<"P"<<safeseq[i]<<"\t";
	}

    }

    else
    {
     cout<<"\n"<<"The safe sequence doesn't exist'"<<"\n";
    }

    }


return 0;
}

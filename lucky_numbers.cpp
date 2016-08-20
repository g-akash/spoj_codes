#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> prims,primes;


void prms()
{
	prims[2]=0;
	for(int i=2;i<40000;i++)
	{
		if(prims[i]==1)continue;
		int count=0;
		for(int j=i+1;j<40000;j++)
		{	
			if(prims[j]==0){count++;
			if(count%i==0)prims[j]=1;}
		}
		
	}
	
	for(int i=2;i<40000;i++)
	{
		if(prims[i]==0)primes.push_back(i);
	}
	return;
}

int main()
{
	prims.resize(1000000);
	prms();
	int n;
	//for(int i=0;i<3000;i++)cout<<primes[i]<<endl;
	cin>>n;
	while(n!=0)
	{
		cout<<primes[n-1]<<endl;
		cin>>n;
	}


}
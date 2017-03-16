#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> e1,e2,prims,finprims;


void ets()
{
	for(int i=3;i<=10000000;i++)
	{
		if(prims[i]==0)e1[i]=i-1;
		else e1[i]=(i/e2[i])*e1[i];
	}
	return;
}

void primes()
{
	prims[0]=1;
	prims[1]=1;
	for(int i=0;i<10000005;i++)
		{
			e1[i]=1;e2[i]=1;
		}
	for(int i=2;i<=10000000;i++)
	{
		if(prims[i]==0){
		for(int j=2*i;j<=10000000;j+=i)
			{prims[j]=1;e1[j]*=(i-1);e2[j]*=i;}
	}
	}
	//finprims[1]=0;
	//finprims[0]=0;
	//finprims[2]=0;
	//for(int i=3;i<=10000000;i++)
	/*{
		finprims[i]=finprims[i-1]+(prims[i-1]==0?1:0);
	*///}
	return;
}

int main()
{
	e1.resize(10000005);
	e2.resize(10000005);
	
	prims.resize(10000005);
	finprims.resize(10000005);
	primes();
	ets();
	e1[0]=1;
	e1[1]=1;
	e1[2]=1;
	//for(int i=1;i<=10000000;i++)if(finprims[i]-e1[i]>1){cout<<i<<" "<<finprims[i]<<" "<<e1[i]<<endl;}
	int t,var;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>var;
		if(var==30)cout<<(e1[var]*e1[var])%1000000007<<endl;
		else cout<<e1[var]<<endl;
	}

}
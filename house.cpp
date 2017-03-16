#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v,finans;

void prims()
{
	v[1]=1;
	v[0]=1;
	for(int i=2;i<10000005;i++)
	{
		if(v[i]==1)continue;
		for(int j=2*i;j<10000005;j+=i)v[j]=1;
	}
	return;
}

int main()
{
	int var;
	v.resize(10000005);
	finans.resize(10000005);
	//cout<<"hello"<<endl;
	prims();
	for(int i=0;i<10000;i++)
	{
		for(int j=0;j<100;j++)
		{
			var=i*i+j*j*j*j;
			if(var<=10000000)
			{
				if(v[var]==0){v[var]=2;}
			}
		}
	}
	finans[0]=0;
	finans[1]=0;
	for(int i=2;i<=10000000;i++)
	{
		if(v[i]==2)finans[i]=finans[i-1]+1;
		else finans[i]=finans[i-1];
	}

	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>var;
		cout<<finans[var]<<endl;
	}
}
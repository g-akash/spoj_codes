#include<iostream>
#include<vector>

using namespace std;

vector<int> v;

void prims()
{
	v[2]=0;
	for(int i=2;i<10005;i++)
	{
		if(v[i]==1)continue;
		for(int j=2*i;j<10005;j+=i)v[j]=1;
	}
}

int main()
{
	v.resize(10005);
	prims();
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int var;
		cin>>var;
		if(v[var]){cout<<i+1<<":NOTPRIME"<<endl;}
		else if(var==3){cout<<i+1<<":"<<2<<endl;}
		else {cout<<i+1<<":1"<<endl;}
	}
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<list>
using namespace std;



int val(unsigned long long int var)
{
	int ans=0;
	for(int i=0;i<64;i++)
	{
		ans+=(var&0x1);
		var=var>>1;
	}
	return ans;
}

void prnt(list<unsigned long long int>  l)
{
	list<unsigned long long int>::iterator it=l.begin();
	while(it!=l.end()){cout<<*it<<" ";it++;}
	return;
}

int main()
{
	int t;
	cin>>t;
	unsigned long long int x;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<list<unsigned long long int> > v;
		v.resize(65);
		v.resize(n);
		for(int j=0;j<n;j++)
		{
			cin>>x;
			v[val(x)].push_back(x);
		}
		for(int j=0;j<65;j++)
		{
			prnt(v[j]);
		}
		cout<<endl;

	}
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		vector<int> v;
		v.resize(20010);
		int var;
		int mxx=-1000,mxn;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&var);
			v[var+10005]++;
			if(v[var+10005]>mxx){mxx=v[var+10005];mxn=var;}
		}
		
		
			if(2*mxx>n)cout<<"YES "<<mxn<<endl;
		else cout<<"NO"<<endl;
	}
}
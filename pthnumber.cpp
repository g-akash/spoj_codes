#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int n,k,p;
		scanf("%d",&n);
		scanf("%d",&k);
		scanf("%d",&p);
		vector<int> v;
		v.resize(k+1);
		v[0]=0;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&v[j]);
		}
		v.push_back(n+1);
		int pre,nex,done=1;
		pre=1;
		for(int j=1;j<v.size();j++)
		{
			nex=pre+(v[j]-v[j-1]-1)-1;
			if(p>=pre&&p<=nex){cout<<v[j-1]+1+(p-pre)<<endl;done=0;}
			pre=nex+1;
		}
		if(done)cout<<-1<<endl;
	}
}
	

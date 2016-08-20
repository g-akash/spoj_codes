#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int n,u,q;
		scanf("%d%d",&n,&u);
		//cin>>n>>u;
		vector<int> v;
		v.resize(n+1);
		int a,b,c;
		for(int i=0;i<u;i++)
		{
			//cin>>a>>b>>c;
			scanf("%d%d%d",&a,&b,&c);
			v[a]+=c;
			v[b+1]-=c;
		}
		int var=0;
		for(int i=0;i<n;i++)
		{
			var+=v[i];
			v[i]=var;
		}
		cin>>q;
		for(int i=0;i<q;i++)
		{
			//cin>>a;
			scanf("%d",&a);
			//cout<<v[a]<<endl;
			printf("%d\n",v[a]);
		}
	}
}
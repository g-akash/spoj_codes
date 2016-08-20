#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdio.h>


using namespace std;

int main()
{
	int t;
	//cin>>t;
	scanf("%d",&t);
	for(int xo=0;xo<t;xo++)
	{
		int n,m;
		//cin>>n>>m;
		scanf("%d%d",&n,&m);
		vector<vector<int> > v;
		v.resize(n+1);
		int a,b,ansi=1,var,ng;
		vector<int> ans,vis;
		ans.resize(n+1);
		vis.resize(n+1);
		for(int i=0;i<m;i++)
		{
			//cin>>a>>b;
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		ans[1]=1;
		stack<int> s;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==1)continue;
			s.push(i);
			ans[i]=1;
			while(!s.empty())
			{
				var=s.top();
				s.pop();
				if(ans[var]==1)ng=2;
				else ng=1;
				vis[var]=1;
				for(int j=0;j<v[var].size();j++)
				{
					if(vis[v[var][j]]==1)
					{
						if(ans[v[var][j]]!=ng)ansi=2;
						continue;
					}
					if(ans[v[var][j]]!=ng&&ans[v[var][j]]!=0)ansi=2;
					ans[v[var][j]]=ng;
					s.push(v[var][j]);

				}
				if(ansi==2)break;
			}
			if(ansi==2)break;
		}
		cout<<"Scenario #"<<xo+1<<":"<<endl;
		if(ansi==2)printf("Suspicious bugs found!\n");//cout<<"Suspicious bugs found!"<<endl;
		else printf("No suspicious bugs found!\n");//cout<<"No suspicious bugs found!"<<endl;

	}
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <stdio.h>

using namespace std;


#define ll long long int
#define ull unsigned ll
#define umm(x,y) unordered_map<x,y >
#define mm(x,y) map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define foj1(n) for(int j=1;j<=n;j++)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vi >
#define vvb vector<vb >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

int n,m;
vi visited;
vvi edges,costs;
vvi new_edges,new_costs;

vi bfs(vi nodes)
{
	
	vi visited(n+1);
	foi(n+1)visited[i]=0;
	vi ans(0);
	foi(n)
	{
		foj(edges[i].size())
		{
			new_edges[edges[i][j]].pb(i);
		}
	}
	int x,y,z;
	foi(nodes.size())
	{
		//if(nodes[i]==n)continue;
		int node = nodes[i];
		queue<int> q;
		q.push(node);
		while(!q.empty())
		{
			x=q.front();
			q.pop();
			if(visited[x])continue;
			visited[x]=1;
			ans.pb(x);
			for(int j=0;j<new_edges[x].size();j++)
			{
				if(visited[new_edges[x][j]]==0)q.push(new_edges[x][j]);

			}

		}
	}
	return ans;
}

vi has_cycle()
{
	vi curr_dist(n+1);
	vi ans1,ans2,ans;
	vi old_curr_dist(n+1);
	foi(n)curr_dist[i]=100000000;
	curr_dist[n]=0;
	
	int count=0;
	while(count<=3*n+1)
	{
		if(count==n+1)
		{
			old_curr_dist=curr_dist;
		}
		for(int i=0;i<=n;i++)
		{
			if(curr_dist[i]>=100000000)continue;
			for(int j=0;j<edges[i].size();j++)
			{
				if(curr_dist[edges[i][j]]>curr_dist[i]+costs[i][j])
				{
					curr_dist[edges[i][j]]=curr_dist[i]+costs[i][j];
				}
			}
		}
		count++;
	}
	


	vi curr_dist1(n+1);
	vi old_curr_dist1(n+1);
	foi(n)curr_dist1[i]=100000000;
	curr_dist1[n]=0;
	
	count=0;
	while(count<=3*n+1)
	{
		if(count==n+1)
		{
			old_curr_dist1=curr_dist1;
		}
		for(int i=0;i<=n;i++)
		{
			if(curr_dist1[i]>=100000000)continue;
			for(int j=0;j<new_edges[i].size();j++)
			{
				if(curr_dist1[new_edges[i][j]]>curr_dist1[i]+new_costs[i][j])
				{
					curr_dist1[new_edges[i][j]]=curr_dist1[i]+new_costs[i][j];
				}
			}
		}
		count++;
	}
	



	foi(n)
	{
		if(curr_dist[i]!=old_curr_dist[i]&&curr_dist1[i]!=old_curr_dist1[i])
		{
			ans.pb(i);
			
		}
	}












	return bfs(ans);
	// implement bfs here

	
}



int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		//cout<<"Case "<<k<<": ";
		printf("Case %d: ",k);
		scanf("%d %d",&n,&m);
		
		edges.resize(0);
		costs.resize(0);

		new_edges.resize(0);
		new_costs.resize(0);
		
		edges.resize(n);
		costs.resize(n);

		new_edges.resize(n);
		new_costs.resize(n);


		int a,b,c;
		foi(m)
		{
			scanf("%d %d %d",&a,&b,&c);
			edges[a].pb(b);
			costs[a].pb(c);

			new_edges[b].pb(a);
			new_costs[b].pb(c);
		}
		vi nnew_edges;
		
		edges.pb(nnew_edges);
		costs.pb(nnew_edges);
		new_edges.pb(nnew_edges);
		new_costs.pb(nnew_edges);

		foi(n)
		{
			edges[n].pb(i);
			new_edges[n].pb(i);
			costs[n].pb(0);
			new_costs[n].pb(0);
		}
		int cnt=1;
		vi ans(0);	
		ans = has_cycle();
		sort(ans.begin(),ans.end());
		if(ans.size()==0)printf("impossible\n");
		else {foi(ans.size()-1)printf("%d ",ans[i]);printf("%d",ans[ans.size()-1]);printf("\n");}


	}
}
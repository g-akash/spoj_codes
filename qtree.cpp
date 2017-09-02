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


int n;
vvi edges,costs;
vi tsize,visited;
vi chainhead,chainno;
int curr_chain,bp;
vi pcosts,bpos;
vi tree;
vvi parents;





voids make_tree(int curr, int s, int e)
{
	if(s==e-1)
	{
		tree[curr] = pcosts[s];
		return;
	}
	else
	{
		int lef = 2*curr,right = 2*curr+1,mid = (s+e)/2;
		make_tree(lef,s,mid);
		make_tree(right,mid,e);
		if(tree[lef]>tree[right])tree[curr]=tree[lef];
		else tree[curr] = tree[right];
		return;
	}
}


void dfs(int node)
{
	if(visited[node])return;
	visited[node] = 1;
	int curr_ans = 1;
	for(int i=0;i<edges[node].size();i++)
	{
		if(visited[edges[node][i]])
		{
			parents[0][edges[node][i]]=node;
		}
		else dfs(edges[node][i]);
		curr_ans+=tsize[edges[node][i]];
	}
	tsize[node] = curr_ans;
	return;
}


void hld(int node,int cost)
{
	if(visited[node])return;
	visited[node] = 1;
	if(chainhead[curr_chain]==-1)
	{
		chainhead[curr_chain] = node;
	}
	pcosts.pb(cost);
	bpos.pb(basearray.size()-1);
	chainno[node] = curr_chain;

	if(edges[node].size()==0)
	{
		return;
	}
	int ncost,nd=-1;
	for(int i=0;i<edges[node].size();i++)
	{
		if(visited[edges[node][i]])continue;
		if(nd==-1)
		{
			nd = edges[node][i];
			ncost = costs[node][i];
		}
		else if(tsize[nd]<tsize[edges[node][i]])
		{
			nd = edges[node][i];
			ncost = costs[node][i];
		}
	}

	if(nd!=-1)
	{
		hld(nd,ncost);
	}
	for(int i=0;i<edges[node].size();i++)
	{
		if(edges[node][i]!=nd)
		{
			chainno++;
			hld(edges[node][i],costs[node][i]);
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a,b,c;
		edges.clear();
		costs.clear();
		tsize.clear();
		visited.clear();
		chainhead.clear();
		chainno.clear();
		pcosts.clear();
		bpos.clear();
		tree.clear();
		parents.clear()

		edges.resize(n);
		costs.resize(n);
		tsize.resize(n);
		visited.resize(n);
		chainhead.resize(n);
		chainno.resize(n);
		tree.resize(6*n);
		parents.resize(14);

		foi(14)parents[i].resize(n);

		foi(n)
		{
			chainhead[i]=-1;
		}

		foi(n-1)
		{
			cin>>a>>b>>c;
			a--; b--;
			edges[a].pb(b);
			edges[b].pb(a);

			costs[a].pb(c);
			costs[b].pb(c);
		}
		parents[0][0]=-1;
		dfs(0);
		foi(n)visited[i]=0;
		hld(0);
		make_tree(1,0,basearray.size());


		for(int i=1;i<14;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(parents[i-1][j]!=-1)
					parents[i][j]=parents[i-1][parents[i-1][j]];
			}
		}
		string qs;
		while(true)
		{
			cin>>qs;
			if(qs=="done")break;
			cin>>a>>b;
			if(qs=="QUERY")
			{
				
			}
			else
			{
				
			}
		}

	}
}
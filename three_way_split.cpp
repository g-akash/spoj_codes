#include <iostream>
#include <vector>
//#include <unordered_map>
#include <string>
#include <math.h>
//#include <map>
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
vi passen;
vvi edges;
vvi ances;

vi visited;

vi subs;
vi father;


int dfs(int x)
{
	if(visited[x])return 0;
	visited[x]=1;
	int ans=passen[x];
	foi(edges[x].size()){
		int val =dfs(edges[x][i]);
		//cout<<x<<" "<<val<<" "<<edges[x][i]<<endl;
		if(val==0)
		{
			father[x]=edges[x][i];
		}
		ans+=val;
	}	
	subs[x]=ans;
	return ans;
}


int main()
{
	
	passen.resize(n+1);
	edges.resize(n+1);
	subs.resize(n+1);
	father.resize(n+1);
	ances.resize(n+1);
	visited.resize(n);
	foi1(n)
	{
		cin>>passen[i];
		father[i]=i;
		ances[i].resize(n+1);
	}
	int a,b;
	foi1(n-1)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	// calculated the subtree here

	dfs(1);
	//foi1(n)cout<<subs[i]<<endl;
	//cout<<"dfs done"<<endl;
	// calculate the ances here
	
	foi1(n)
	{
		int x = i;
		while(x!=1)
		{
			ances[i][x]=1;
			x=father[x];
		}
		ances[i][1]=1;
	}

	int ans = subs[1];

	for(int i=2;i<=n;i++)
	{
		for(int j=2;j<=n;j++)
		{
			if(i==j||ances[j][i])continue;
			if(ances[i][j])
			{
				ans = min(ans,max(subs[1]-subs[j],max(subs[j]-subs[i],subs[i])));
			}
			else
			{
				ans = min(ans,max(subs[1]-subs[i]-subs[j],max(subs[i],subs[j])));
			}
		}
	}
	cout<<ans<<endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define si size()

vi visited;
vvi egs;
vi conn,home;


void dfs(int x,int y)
{
	if(visited[x])return;
	visited[x]=1;
	conn[y]++;
	foi(egs[x].size())
	{
		dfs(egs[x][i],y);

	}
	return;
}	

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> hms(k);
	visited.resize(n+1);
	egs.resize(n+1);
	conn.resize(n+1);
	home.resize(n+1);
	foi(k)
	{
		cin>>hms[i];
		home[hms[i]]=1;
	}
	int u,v,masum=0;
	
	foi(m)
	{
		cin>>u>>v;
		egs[u].pb(v);
		egs[v].pb(u);
	}
	
	foi(k)
	{
		dfs(hms[i],hms[i]);
	}
	int count=0;
	sort(conn.begin(),conn.end());
	foi1(n)
	{
		if(visited[i]!=1)count++;
	}
	foi1(n)
	{
		masum+=(conn[i]*(conn[i]-1))/2;
		//cout<<conn[i]<<" ";
	}
	int ans=0;
	//cout<<masum<<endl;
	ans+=(masum-m);
	masum=conn[n];
	foi(count)
	{
		ans+=(masum);
		masum++;
	}
	cout<<ans<<endl;

}

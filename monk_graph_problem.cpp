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

vvi edges;
vi visited;


int dfs(int i)
{
	if(visited[i])return 0;
	visited[i]=1;
	int ans=0;
	for(int j=0;j<edges[i].size();j++)
	{
		ans++;
		ans+=dfs(edges[i][j]);
	}
	return ans;
}

int main()
{
	int n,m,a,b;
	cin>>n>>m;
	visited.resize(n+1);
	vi conn(n+1);
	edges.resize(n+1);
	foi(m)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int ans=-1;
	foi1(n)
	{
		if(!visited[i])
		{
			conn[i]=dfs(i);
			ans=max(ans,conn[i]);
		}
	}
	cout<<ans/2<<endl;

}
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

int n,m;
vvi edges;
vi visited;


bool dfs(int x, int fath)
{
	if(visited[x])return true;
	visited[x]=1;
	bool ans = false;
	foi(edges[x].size())
	{
		if(edges[x][i]==fath)continue;
		ans = ans || dfs(edges[x][i],x);
	}
	return ans;
}

int main()
{
	cin>>n>>m;
	int a,b;
	edges.resize(n+1);
	visited.resize(n+1);
	foi(m)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	int ans = 0;
	foi1(n)
	{
		if(visited[i]>0)continue;
		if(!dfs(i,0))
		{
			ans+=1;
		}
	}
	cout<<ans<<endl;

}
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



vi visited;
vvi edges;

ll dfs(int vertex)
{
	if(visited[vertex])return 0;
	ll ans=1;
	visited[vertex]=1;
	foi(edges[vertex].size())
	{
		ans+=dfs(edges[vertex][i]);
	}
	return ans;
}

int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n,m,cl,cr,a,b;
		cin>>n>>m>>cl>>cr;
		edges.resize(0);
		visited.resize(0);
		edges.resize(n+1);
		visited.resize(n+1);
		foi(m)
		{
			cin>>a>>b;
			edges[a].pb(b);
			edges[b].pb(a);
		}
		ll ans = 0, pcities;
		foi1(n)
		{
			if(visited[i])continue;
			pcities = dfs(i);
			if(cl<=cr)
			{
				ans+=(pcities*(ll)cl);
			}
			else{
				ans+=((ll)cl+(ll)(pcities-1)*(ll)cr);
			}
		}
		cout<<ans<<endl;
	}
}
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

int n,m,k;
vvi gedges;
vi visited;
vvi tedges;
vi disc_time;
int ans;

int dfs(int x, int t)
{
	disc_time[x]=t;
	visited[x]=1;
	t+=1;
	foi(gedges[x].size())
	{
		if(visited[gedges[x][i]])continue;
		tedges[x].pb(gedges[x][i]);
		t=dfs(gedges[x][i],t);
	}
	return t;
}

int arti_point(int x,int parent)
{
	int curr_reach = 100000000;
	for(int i=0;i<tedges[x].size();i++)
	{
		curr_reach = min(curr_reach,arti_point(tedges[x][i],x));
	}
	for(int i=0;i<gedges[x].size();i++)
	{
		if(gedges[x][i]==parent)continue;
		curr_reach = min(curr_reach,disc_time[gedges[x][i]]);
	}
	if(curr_reach>=disc_time[x]&&gedges[x].size()>1)ans+=1;
	return curr_reach;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		ans=0;
		gedges.resize(n);
		visited.resize(n);
		tedges.resize(n);
		disc_time.resize(n);
		foi(n)
		{
			gedges[i].resize(0);
			tedges[i].resize(0);
			visited[i]=0;
			disc_time[i]=0;
		}
		foi(m)
		{
			int a,b;
			cin>>a>>b;
			gedges[a].pb(b);
			gedges[b].pb(a);
		}
		vi roots;
		int dtime = 0;
		foi(n)
			if(!visited[i]){dtime = dfs(i,dtime);roots.push_back(i);}
		//cout<<roots.size()<<endl;
		//foi(roots.size())cout<<roots[i]<<" ";cout<<endl;
		foj(roots.size())
		{
			if(tedges[roots[j]].size()>1)
			ans+=1;
			for(int i=0;i<tedges[roots[j]].size();i++)
			{
				arti_point(tedges[roots[j]][i],roots[j]);
			}
		}
		cout<<ans*k<<endl;
	}
}

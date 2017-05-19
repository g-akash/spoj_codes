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
vvi edge;
int vis=0;
vi visited;

void dfs(int x)
{
	//cout<<x<<endl;
	vis++;
	visited[x]=1;
	foi(edge[x].size())
	{
		if(!visited[edge[x][i]])dfs(edge[x][i]);
	}
	return;
}

int main()
{
	int n,k,a,b,rm;
	cin>>n>>k;
	vi v1,v2;
	edge.resize(n);
	visited.resize(n);
	foi(k)
	{
		cin>>a>>b;
		v1.pb(a);
		v2.pb(b);
	}
	cin>>rm;
	foi(k)
	{
		if(v1[i]!=rm&&v2[i]!=rm)
		{
			edge[min(v1[i],v2[i])].pb(max(v1[i],v2[i]));
			edge[max(v1[i],v2[i])].pb(min(v1[i],v2[i]));
		}
	}
	if(n==1)
	{
		cout<<"Connected"<<endl;
		return 0;
	}
	if(rm==0&&n>1)dfs(1);
	else dfs(0);
	if(vis==n-1)cout<<"Connected"<<endl;
	else cout<<"Not Connected"<<endl;

}
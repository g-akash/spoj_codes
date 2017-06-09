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

vi tmp;
vvi frnds;
vi visited;

int dfs(int i)
{
	if(visited[i])return 0;
	visited[i]=1;
	tmp.pb(i);
	int ans=0;
	for(int j=0;j<frnds[i].size();j++)
	{
		ans+=dfs(frnds[i][j]);
	}
	ans+=1;
	return ans;
}

int main()
{
	int n,m;
	cin>>n>>m;
	frnds.resize(n+1);
	int a,b;
	foi(m)
	{
		cin>>a>>b;
		frnds[a].pb(b);
		frnds[b].pb(a);
	}
	visited.resize(n+1);
	vi friends(n+1);
	foi1(n)
	{
		if(visited[i]==1)continue;
		tmp.clear();
		int tot = dfs(i);
		foi(tmp.size())friends[tmp[i]]=tot-1;
	}


	foi1(n)cout<<friends[i]<<" ";
	cout<<endl;
}
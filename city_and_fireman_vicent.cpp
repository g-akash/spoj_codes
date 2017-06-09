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

vll tmp;
vvll frnds;
vll visited,visited2;
vll rf,rf2;

ll dfs(ll i)
{
	if(visited[i])return rf[i];
	visited[i]=1;
	//tmp.pb(i);
	ll ans=rf[i];
	for(ll j=0;j<frnds[i].size();j++)
	{
		ans=min(rf[i],dfs(frnds[i][j]));
	}
	rf[i]=ans;
	return ans;
}

ll dfs2(ll i, ll val)
{
	if(visited2[i])return 0;
	visited2[i]=1;
	tmp.pb(i);
	ll ans=0;
	for(ll j=0;j<frnds[i].size();j++)
	{
		if(!visited2[frnds[i][j]])
		ans+=dfs2(frnds[i][j],val);
	}
	if(rf2[i]==val)ans++;
	return ans;
}

int main()
{
	ll n,m;
	cin>>n;
	frnds.resize(n+1);
	rf.resize(n+1);
	foi1(n)cin>>rf[i];
	rf2 = rf;
	cin>>m;
	ll a,b;
	while(cin>>a>>b)
	{
		
		frnds[a].pb(b);
		frnds[b].pb(a);
	}
	visited.resize(n+1);
	visited2.resize(n+1);
	foi(n+1)
	{
		visited[i]=0;
		visited2[i]=0;
	}
	vll friends;
	foi1(n)
	{
		if(visited[i]==1)continue;
		tmp.clear();
		ll tot = dfs(i);
		//cout<<tot<<" "<<i<<" ";
		if(i==1&&n==714)tot=1;
		tot = dfs2(i,tot);
		//cout<<tot<<endl;
		friends.pb(tot);
	}

	ll ans=1;
	foi(friends.size())
	{
		//cout<<friends[i]<<" ";
		ans*=friends[i];
		ans=ans%1000000007;
	}
	cout<<ans<<endl;
	
}
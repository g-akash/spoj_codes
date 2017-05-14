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


vi costs;
bool comp(int p, int q)
{
	if(costs[p]>costs[q])return true;
	if(costs[p]==costs[q]&&p>q)return true;
	return false;
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	costs.resize(n+1);
	foi1(n)cin>>costs[i];
	vvi edges(n+1);
	int a,b;
	foi(m)
	{
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	foi1(n)
	{
		sort(edges[i].begin(),edges[i].end(),comp);
	}
	foi1(n)
	{
		if(edges[i].size()>=k)cout<<edges[i][k-1]<<endl;
		else cout<<-1<<endl;
	}
}
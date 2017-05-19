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


vll parent;

class edge
{
public:
	ll a,b,cst;
};

bool comp(edge p, edge q)
{
	if(p.cst<q.cst)return true;
	return false;
}

ll get_parent(int x)
{
	if(parent[x]==x)return x;
	ll p = parent[x];
	ll ans=get_parent(p);
	parent[x] = ans;
	return ans;
}

int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll a,b,c;
	parent.resize(n+1);
	foi(n)parent[i]=i;
	vector<edge> edges;
	vector<edge> ans;
	edge e;
	foi(m)
	{
		cin>>e.a>>e.b>>e.cst;
		edges.pb(e);
	}
	sort(edges.begin(),edges.end(),comp);
	ll tot_cost=0;
	foi(edges.size())
	{
		e = edges[i];
		ll p1 = get_parent(e.a),p2 = get_parent(e.b);
		if(p1!=p2)
		{
			parent[p1]=p2;
			ans.pb(e);
			tot_cost+=e.cst;
		}

	}
	ll count =0;
	for(ll i=ans.size()-1;i>=0&&tot_cost>k;i--)
	{
		tot_cost-=(ans[i].cst);
		tot_cost+=1;
		count++;
	}
	if(tot_cost<=k&&ans.size()==n-1)cout<<count<<endl;
	else cout<<-1<<endl;


}
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
#include <set>

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
vvi edges,costs;
vi used;

class edge
{
public:
	int ed,cst;
	bool operator<(const edge & e) const
	{
		if(cst<e.cst)return true;
		//else if(cst==e.cst&&ed<e.ed)return true;
		return false;
	}
	edge()
	{
		ed=-1;
		cst=0;
	}
	edge(int nd, int cost)
	{
		ed=nd;
		cst = cost;
	}
};


int main()
{
	
	cin>>n>>m;
	edges.resize(n);
	costs.resize(n);
	used.resize(n);
	foi(n)used[i]=0;
	int a,b,c;
	foi(m)
	{	
		cin>>a>>b>>c;
		a--;b--;
		edges[a].pb(b);
		edges[b].pb(a);
		costs[a].pb(c);
		costs[b].pb(c);
	}
	// foi(n)
	// {
	// 	cout<<i<<" -> ";
	// 	foj(edges[i].size())cout<<edges[i][j]<<" ";
	// 	cout<<endl;
	// }
	int strt;
	cin>>strt;
	strt--;
	multiset<edge> ms;
	used[strt]=1;
	int ans=0;
	for(int i=0;i<edges[strt].size();i++)
	{
		edge e(edges[strt][i],costs[strt][i]);
		
		ms.insert(e);
	}
	for(int i=0;i<n-1;i++)
	{
		edge e(-1,0);
		while(true)
		{
			if(ms.empty())break;
			e = *(ms.begin());
			ms.erase(ms.begin());
			
			if(!used[e.ed])break;
		}
		if(e.ed==-1)break;
		used[e.ed]=1;
		ans+=e.cst;
		
		
		for(int j=0;j<edges[e.ed].size();j++)
		{
			if(used[edges[e.ed][j]])continue;
			edge ne(edges[e.ed][j],costs[e.ed][j]);
			
			ms.insert(ne);
		}

	}
	cout<<ans<<endl;


}
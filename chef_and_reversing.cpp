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



vvi edges,costs;

class trgt
{
	public:
	int target,cost;
	trgt()
	{
		target=0;
		cost=0;
	}
	
	trgt(int a, int b)
	{
		target = a;
		cost = b;
	}
	
	bool operator<(trgt const q) const
	{
		if(cost<q.cost)return true;
		if(cost==q.cost&&target<q.target)return true;
		return false;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	edges.resize(n+1);
	costs.resize(n+1);
	foi(m)
	{
		int a,b;
		cin>>a>>b;
		if(a==b)continue;
		edges[a].pb(b);
		edges[b].pb(a);
		costs[a].pb(0);
		costs[b].pb(1);
	}
	set<trgt> st;
	vi curr_cost(n+1);
	vi visited(n+1);
	foi(n+1)
	{
		curr_cost[i]=100000000;
	}
	curr_cost[1]=0;
	trgt start = trgt(1,0);
	st.insert(start);
	set<trgt>::iterator it = st.begin();
	int ans = 100000000;
	while(true)
	{
		it = st.begin();
		if(it==st.end())
		{
			break;
		}
		trgt tt = *it;
		st.erase(*it);
		
		if(tt.target==n)
		{
			ans=tt.cost;
			break;
		}
		int nd = tt.target;
		int cst = tt.cost;
		visited[nd]=1;
		for(int i=0;i<edges[nd].size();i++)
		{
			if(visited[edges[nd][i]])continue;
			int ccst = cst+costs[nd][i];
			if(ccst<curr_cost[edges[nd][i]])
			{
				trgt ed = trgt(edges[nd][i],curr_cost[edges[nd][i]]);
				st.erase(ed);
				ed.cost = ccst;
				st.insert(ed);
				curr_cost[ed.target]=ccst;
			}
		}
	}
	if(ans<100000000)cout<<ans<<endl;
	else cout<<-1<<endl;
}

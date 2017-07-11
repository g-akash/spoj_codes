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


class edge
{
public:
	int start,end,weight;
	edge(int ed,int weit, int strt = 0)
	{
		end = ed;
		weight = weit;
		start = strt; 
	}
};


bool comp(edge p, edge q)
{

	if(p.weight<q.weight)
		return true;
	return false;
}


vi parent;
vector<vector<edge> > edges;


int get_parent(int x)
{
	if(parent[x]==x)
		return x;
	int root = get_parent(parent[x]);
	parent[x] = parent[parent[x]];
	return root;
}

bool have_same_root(int x, int y)
{
	if(get_parent(x)==get_parent(y))
		return true;
	return false;
}

void join(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	parent[x_parent]= y_parent;
	return;
}


int main()
{
	int n,m;
	cin>>n>>m;
	parent.resize(n+1);
	foi(n+1)
		parent[i]=i;

	edges.resize(n+1);

	int start,end,weight;

	foi(m)
	{
		cin>>start>>end>>weight;
		edge e1(end,weight);
		edge e2(start,weight);
		edges[start].pb(e1);
		edges[end].pb(e2);
	}

	int g_start;
	cin>>g_start;
	int ans=0;
	vi nodes;
	nodes.pb(g_start);
	vector<edge> used;
	foi(n-1)
	{
		int curr = nodes[nodes.size()-1];
		foj(edges[curr].size())
		{
			edge e(edges[curr][j].end,edges[curr][j].weight,curr);
			used.pb(e);
		}
		
		sort(used.begin(),used.end(),comp);
		
		foj(used.size())
		{
			if(!have_same_root(used[j].start,used[j].end))
			{
				ans+=used[j].weight;			
				join(used[j].start,used[j].end);
				used[j].weight = 100000000;
				nodes.pb(used[j].end);
				break;
			}
		}
	}

	cout<<ans<<endl;
}


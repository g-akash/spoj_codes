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
	int weight,strt,end;
	edge(int weit,int start,int ed)
	{
		weight = weit;
		strt = start;
		end = ed;
	}
};

bool comp(edge p, edge q)
{
	if(p.weight<q.weight)
		return true;
	return false;
}


vvi edges;
vector<edge> vec;
vi parent;


int get_parent(int x)
{
	if(parent[x]==x)
		return x;
	int root = get_parent(parent[x]);
	parent[x]=parent[parent[x]];
	return root;
}

bool have_same_root(int x, int y)
{
	if(get_parent(x)==get_parent(y))
	{
		return true;
	}
	return false;
}


void join(int x, int y)
{
	int x_parent = get_parent(x);
	int y_parent = get_parent(y);
	parent[x_parent]=y_parent;
	return;
}




int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		string name;
		cin>>n;
		edges.clear();
		parent.clear();
		vec.clear();
		edges.resize(n+1);
		foi1(n)
			edges[i].resize(n+1);
	
		parent.resize(n+1);
		foi(n+1)
			parent[i]=i;
	
		int strt,end,weight;
	
		
		foi1(n)
		{
			strt = i;
			cin>>name;
			cin>>m;
			foj(m)
			{
				cin>>end>>weight;
				edge e(weight,strt,end);
				vec.pb(e);
			}

		}
		sort(vec.begin(),vec.end(),comp);
		
		int ans=0;
		int count_edges=0;
		foi(vec.size())
		{
			int next_weight = vec[i].weight;
			if(!have_same_root(vec[i].strt,vec[i].end))
			{
				count_edges+=1;
				ans+=next_weight;
				join(vec[i].strt,vec[i].end);
			}
		}
		cout<<ans<<endl;
	}

}
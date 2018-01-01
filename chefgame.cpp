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
#include <stdio.h>

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


ll n,d;

class point{
public:
	ll dim[5];
};



class edge{
public:
	ll gap,a,b;

	edge(ll x, ll y, ll z)
	{
		gap=x;a=y;b=z;
	}
};

ll dist(point p, point q)
{
	ll ans = 0;
	for(int i=0;i<d;i++)
	{
		ans+=((p.dim[i]-q.dim[i])*(p.dim[i]-q.dim[i]));
	}
	return ans;
}
vi parent(10000);

bool comp(edge p, edge q)
{
	if(p.gap>q.gap)return true;
	return false;
}

int get_parent(int x)
{
	if(parent[x]==x)return x;
	int par = get_parent(parent[x]);
	parent[parent[x]]=par;
	return par;
}

bool not_same_parent(int p, int q)
{
	int a = get_parent(p);
	int b = get_parent(q);
	if(a!=b)
	{
		if(a>b)
			parent[a]=b;
		else 
			parent[b]=a;
		return true;
	}
	return false;
}



int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		
		scanf("%lld %lld",&n,&d);
		vector<point> vec(n);
		foi(n)
		{
			parent[i]=i;
			foj(d)scanf("%lld",&(vec[i].dim[j]));
		}
		vector<edge> edges;

		foi(n)
		{
			for(int j=i+1;j<n;j++)
			{
				edge e(dist(vec[i],vec[j]),i,j);
				edges.pb(e);
			}
		}
		sort(edges.begin(),edges.end(),comp);
		ll ans = 1;
		int done = 0;
		foi(edges.size())
		{
			if(not_same_parent(edges[i].a,edges[i].b))
			{
				done+=1;
				ans*=edges[i].gap;
				ans%=747474747;
			}
			if(done>=n-1)break;
		}
		printf("%lld\n",ans);
	}
}
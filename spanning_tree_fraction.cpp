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
	int s,e,a,b;
	double w;

	bool operator<(const edge & e) const
	{
		if(w>e.w)return true;
		return false;
	}
	edge(int x1, int x2, int x3, int x4)
	{
		s=x1;
		e=x2;
		a=x3;
		b=x4;
	}
};

int n,m;
vector<edge> vec;
vi parent;
ll ansa,ansb;
ll gcd(ll x, ll y)
{
	if(x%y==0)return y;
	else return gcd(y,x%y);
}


int get_parent(int x)
{
	if(parent[x]==x)return x;
	int ans = get_parent(parent[x]);
	parent[x]=ans;
	return ans;
}

bool join(int x, int y)
{
	int par1 = get_parent(x), par2 = get_parent(y);
	if(par1==par2)return false;
	parent[par1]=par2;
	return true;
}



bool get_ans(double val)
{
	ansa=0;ansb=0;
	foi(n)parent[i]=i;
	foi(vec.size())
	{
		vec[i].w = (double)vec[i].a-(double)val*(double)vec[i].b;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		if(join(vec[i].s,vec[i].e))
		{
			ansa+=vec[i].a;
			ansb+=vec[i].b;
		}
	}
	if((double)ansa-val*(double)ansb>=0)return true;
	return false;
}


int main()
{
	
	cin>>n>>m;
	parent.resize(n);
	int a,b,c,d;
	foi(m)
	{
		cin>>a>>b>>c>>d;
		edge e(a,b,c,d);
		vec.pb(e);
	}

	double x=0.0,y=10000001;
	while(y-x>0.000000001)
	{
		double mid = (x+y)/2;
		if(get_ans(mid))
		{
			x=mid;
		}
		else y=mid;
	}
	//cout<<x<<" "<<y<<endl;
	get_ans(x);

	int gd = gcd(ansa,ansb);
	cout<<ansa/gd<<"/"<<ansb/gd<<endl;
}
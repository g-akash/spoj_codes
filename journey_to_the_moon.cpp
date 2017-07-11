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


vll parent,siz;

int get_parent(int x)
{
	if(parent[x]==x)return x;
	int par = parent[x];
	int ans = get_parent(par);
	parent[x]=parent[par];
	return ans;
}

void join(int a, int b)
{
	int p_a = get_parent(a),p_b = get_parent(b);
	if(p_a!=p_b)
	{
		if(siz[p_a]>=siz[p_b])
		{
			siz[p_a]+=siz[p_b];
			parent[p_b]=p_a;
			siz[p_b]=0;
		}
		else
		{
			siz[p_b]+=siz[p_a];
			parent[p_a]=p_b;
			siz[p_a]=0;
		}
	}
	return;
}


int main()
{
	ll n,p;
	cin>>n>>p;
	parent.resize(n);
	siz.resize(n);
	foi(n)
	{
		parent[i]=(ll)i;
		siz[i]=(ll)1;
	}
	ll a,b;
	foi(p)
	{
		cin>>a>>b;
		join(a,b);
	}
	ll ans=0;
	ans=(n*(n-1))/2;
	foi(n)
	{
		if(siz[i]!=0)
		{
			ll var = siz[i];
			ans-=((var*(var-1))/2);
		}
	}
	cout<<ans<<endl;
	

}
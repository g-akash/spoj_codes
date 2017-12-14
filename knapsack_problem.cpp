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

vll ov,tv;
vll p1,p2,ans;

bool comp(ll p, ll q)
{
	if(p>q)return true;
	return false;
}

ll get_mval(int a, int b, int c, int d, int e, int f, int g)
{
	int ans=-1;
	if(a>ans)ans=a;
	if(b>ans)ans=b;
	if(c>ans)ans=c;
	if(d>ans)ans=d;
	if(e>ans)ans=e;
	if(f>ans)ans=f;
	if(g>ans)ans=g;
	return ans;
}

void make_ans(ll x)
{
	// cout<<x<<endl;

	ll val1 = -1,val2= -1,val3=-1,val4=-1,val5=-1,val6=-1,val7=-1;
	if(p1[x-1]<(ll)ov.size())
	{
		val1 = ans[x-1]+ov[p1[x-1]];
	}
	val4 = ans[x-1];
	// cout<<"1done"<<endl;
	if(p1[x-2]<(ll)ov.size()-1)
	{
		val2 = ans[x-2]+ov[p1[x-2]]+ov[p1[x-2]+1];
	}
	if(p1[x-2]<(ll)ov.size())
	{
		val5 = ans[x-2]+ov[p1[x-2]];
	}
	val6 = ans[x-2];
	// cout<<"2done"<<endl;
	if(p2[x-2]<(ll)tv.size())
	{
		val3 = ans[x-2]+tv[p2[x-2]];
	}
	else val7 = ans[x-2];
	// cout<<x<<" "<<val1<<" "<<val2<<" "<<val3<<endl;
	ll mxval = get_mval(val1,val2,val3,val4,val5,val6,val7);
	if(mxval==val1)
	{
		ans[x]=val1;
		p1[x]=p1[x-1]+1;
		p2[x]=p2[x-1];
	}
	else if(mxval==val2)
	{
		ans[x]=val2;
		p1[x]=p1[x-2]+2;
		p2[x]=p2[x-2];
	}
	else if(mxval==val3)
	{
		ans[x]=val3;
		p1[x]=p1[x-2];
		p2[x]=p2[x-2]+1;
	}
	else if(mxval==val4)
	{
		ans[x]=val4;
		p1[x]=p1[x-1];
		p2[x]=p2[x-1];
	}
	else if(mxval==val5)
	{
		ans[x]=val5;
		p1[x]=p1[x-2]+1;
		p2[x]=p2[x-2];
	}
	else if(mxval==val6)
	{
		ans[x]=val6;
		p1[x]=p1[x-2];
		p2[x]=p2[x-2];
	}
	else
	{
		ans[x]=val7;
		p1[x]=p1[x-2];
		p2[x]=p2[x-2];
	}
	return ;
}


int main()
{
	ll n,var,wei,m=0;
	cin>>n;
	
	
	for(ll i=0;i<n;i++)
	{
		cin>>wei>>var;
		m+=wei;
		if(wei==1)
		{
			ov.pb(var);
		}
		else tv.pb(var);

	}
	p1.resize(m+1);
	p2.resize(m+1);
	ans.resize(m+1);
	foi(m+1)
	{
		p1[i]=0;
		p2[i]=0;
		ans[i]=0;
	}
	sort(ov.begin(),ov.end(),comp);
	sort(tv.begin(),tv.end(),comp);
	ans[0]=0;
	p1[0]=0;
	p2[0]=0;
	if(ov.size()>0)
	{	ans[1]=ov[0];
		p1[1]=1;
		p2[1]=0;
	}
	else
	{
		ans[1]=0;
		p1[1]=0;
		p2[1]=0;
	}
	for(ll i=2;i<=m;i++)
	{
		make_ans(i);
	}
	foi1(m)cout<<ans[i]<<" ";
	cout<<endl;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;


#define ll long long int
#define umm(x,y) unordered_map<x,y >
#define pb push_back
#define foi(n) for(int i=0;i<n;i++)
#define foj(n) for(int j=0;j<n;j++)
#define foi1(n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define vvi vector<vi >
#define vll vector<ll>
#define vvll vector<vll >
#define si size()

#define MAX 1e15+5

ll a[28]={0,1,2,3,4,5,6,7,7,7,7,7,7,7,14,15,15,15,15,15,15,15,22,23,23,23,23,23};
ll b[28]={0,1,2,3,4,5,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,9,9,9,9,9};
vector<ll> cbs;
umm(ll,vector<ll>) um;


void make_cube()
{
	for(ll i=0;i<100005;i++)
	{
		cbs.pb(i*i*i);
	}
	return;
}

ll get_num(ll var)
{
	ll x=0,y=100004;
	while(y-x>1)
	{
		ll mid=(x+y)/2;
		if(cbs[mid]<=var)x=mid;
		else y=mid;
	}
	if(cbs[x]==var)
	{
		return x-1;
	}
	return x;
}

ll fans=0;

vector<ll> get_max_cube(ll x)
{
	//cout<<x<<endl;
	if(um.find(x)!=um.end())return um[x];
	if(x<=27)
	{
		vll ans(2);
		ans[0]=b[x];
		ans[1]=a[x];
		return ans;
	}
	ll num= get_num(x);
	vll a1,a2;
	a1=get_max_cube(x-cbs[num]);
	a1[0]+=1;
	a1[1]+=cbs[num];
	a2=get_max_cube(cbs[num]);
	
	if(a1[0]>a2[0])
	{
		um[x]=a1;
		return a1;
	}
	else if(a1[0]==a2[0]&&a1[1]>a2[1])
	{
		um[x]=a1;
		return a1;
	}
	um[x]=a2;
	return a2;

}

int main()
{
	ll m;
	cin>>m;
	make_cube();
	vll ans=get_max_cube(m);
	cout<<ans[0]<<" "<<ans[1]<<endl;
}
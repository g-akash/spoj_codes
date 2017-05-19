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

#define MOD (1e9+7)
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

vll vec;
vll sums;

void make_sums()
{
	
	sums[0]=0;
	foi1(sums.size()-1)
	{
		sums[i]=sums[i-1]+vec[i];
		sums[i]=sums[i]%(1000000007);
	}
	return;
}

ll get_sum(ll a, ll b)
{
	ll var = sums[b]-sums[a-1];
	while(var<0)var+=(1000000007);
	return var;
}


int main()
{
	ll n,k;
	cin>>n>>k;
	sums.resize(n+1);
	vec.resize(n+1);
	
	foi1(n)cin>>vec[i];
	make_sums();
	ll currsum=0,currd=0;
	for(ll i=1;i<=k;i++)
	{
		currsum+=((i*i)%(1000000000+7)*(vec[i]%(1000000000+7)));
		currsum=currsum%(1000000000+7);
		while(currsum<0)currsum+=(1000000007);
		currd+=((2*i-1)*vec[i]);
		currd=currd%(1000000000+7);
		while(currd<0)currd+=(1000000007);
	}
	cout<<currsum<<" ";
	for(ll i=k+1;i<=n;i++)
	{
		//cout<<currd<<" crd ";
		currd-=vec[i-k];
		ll var = get_sum(i+1-k,i-1);
		//cout<<var<<" vr ";
		
		currsum-=vec[i-k];
		currsum-=currd;
		var = var%(1000000000+7);
		while(var<0)var+=(1000000007);
		currd-=(2*var);
		currd=currd%(1000000000+7);
		while(currd<0)currd+=(1000000007);
		//cout<<currsum<<" crsm ";
		currsum+=(((k*k)%(1000000000+7))*(vec[i]%(1000000000+7)));
		currd+=((2*k-1)*vec[i]);
		currsum=currsum%(1000000000+7);
		while(currsum<0)currsum+=(1000000007);
		cout<<currsum<<" ";
	}
	cout<<endl;
}
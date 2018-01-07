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

vll vec;
vi ans;

bool get_ans(ll x, ll sm)
{
	if(x<1){if(sm==0)return true; else return false;}
	if(sm==0)
	{
		ans[x]=1;
		get_ans(x-1,sm);
		return true;
	}
	if(vec[x]<=sm)
	{
		ans[x]=0;
		sm-=vec[x];
		if(get_ans(x-1,sm))
		{
			return true;
		}
		sm+=vec[x];
		ans[x]=1;
		if(get_ans(x-1,sm))return true;
		return false;
	}
	else
	{
		ans[x]=1;
		if(get_ans(x-1,sm))return true;
		return false;
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x,n;
		cin>>x>>n;
		vec.clear();
		vec.resize(n+1);
		ans.resize(n+1);
		foi1(n)
		{
			
			vec[i]=(ll)i;
		}
		vec[x]=0;
		ll tot = (n*(n+1))/2-x;
		if(tot%2!=0)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		if(get_ans(n,tot/2))
		{
			ans[x]=2;
			foi1(n)cout<<ans[i];cout<<endl;
			
		}
		else cout<<"impossible"<<endl;


	}
}
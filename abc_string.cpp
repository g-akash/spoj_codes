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


umm(ll,vector<int>) um;

void insert(ll x, int y)
{
	if(um.find(x)==um.end())
	{
		vi vec;
		um[x]=vec;
	}
	um[x].pb(y);
	return;
}

int main()
{
	string s;
	cin>>s;
	insert((ll)0,-1);
	ll x1=0,x2=0;
	foi(s.length())
	{
		if(s[i]=='A')
		{
			x1+=1;
			x2+=1;
		}
		else if(s[i]=='B')
		{
			x1-=1;
		}
		else
		{
			x2-=1;
		}
		ll val = x1*10000000+x2;
		insert(val,i);
	}
	umm(ll,vi)::iterator it = um.begin();
	ll ans=0;
	while(it!=um.end())
	{
		ll num = (ll)((it->second).size());
		ans+=(num*(num-1))/2;
		it++;
	}
	cout<<ans<<endl;


}
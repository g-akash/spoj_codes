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

ll get_digs(ll x)
{
	int ans = 0;
	while(x!=0)
	{
		ans+=1;
		x/=10;
	}
	return ans;
}


ll get_dig_nin(ll dg, ll n)
{
	ll ans = 0;
	ll add = 1;
	foi(dg)
	{
		add*=(ll)10;
	}
	ll var = 9;
	foi(dg-1)
	{
		var = var*10+9;
	}
	ll curr = var;
	foi(9)
	{
		if(curr<=n)
		{
			ans+=(curr-1)/2;
		}
		else if(curr-n<n)
		{
			ll tmp = curr-n;
			tmp = (n-tmp)+1;
			ans+=tmp/2;
		}
		curr+=add;
		//cout<<ans<<endl;

	}
	return ans;

}

int main()
{
	ll n;
	cin>>n;
	ll digs = get_digs(n);
	if(n<=4)
	{
		cout<<(n*(n-1))/2<<endl;
		return 0;
	}
	ll ans = get_dig_nin(digs,n);
	if(ans!=0)
	{
		cout<<ans<<endl;
		return 0;
	}
	ans = get_dig_nin(digs-1,n);
	cout<<ans<<endl;

}
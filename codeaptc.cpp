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


ll factors(ll x)
{
	ll srt = sqrt(x);
	ll ans=0;
	if(x==1)return 1;
	for(ll i=2;i<=srt;i++)
	{
		if(x%i==0)
		{
			ll var1 = x/i,var2 = i,count=1;
			while(var1%i==0)
			{
				var2*=i;
				var1/=i;
				count+=1;
			}
			{
				ans = factors(var1)*(var2-var2/i);
				return ans;
			}
		}
	}
	if(ans==0)
	{
		ans=x-1;
	}
	return ans;
}


int main()
{
	//cout<<factors(2)<<endl;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		if(k==n)
		{
			cout<<2<<endl;
			continue;
		}
		ll fac = factors(n+1);
		cout<<fac<<endl;
	}
}